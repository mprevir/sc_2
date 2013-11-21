#include "mainwindow.h"

#include "customLabel.h"

#include "AANN/neuron.h"

#include <QColor>
#include <QPixmap>
#include <QPainter>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QMouseEvent>

namespace sc2
{
namespace
{
void drawField( QPainter* painter )
{
  constexpr uint32_t width{ N * pixels_per_cell };
  painter->fillRect( 0, 0, width, width, Qt::white );
  uint32_t x = 0;
  while (x <= width) {
    painter->setPen( Qt::black );
    painter->drawLine( x, 0, x, width );
    painter->drawLine( 0, x, width, x);

    x += width / N;
  }
}

void setPixel( QPainter* painter, const int x, const int y, QColor colour )
{
  painter->setPen( colour );
  painter->fillRect( x * pixels_per_cell + 1
                   , y * pixels_per_cell + 1
                   , pixels_per_cell - 1
                   , pixels_per_cell - 1
                   , colour );
}
} // namespace

MainWindow::MainWindow(QWidget *parent)
    : QWidget{ parent, Qt::FramelessWindowHint }
    , m_inputPixmap   { new QPixmap  { pixels_per_cell * N + 1, pixels_per_cell * N + 1 }  }
    , m_inputPainter  { new QPainter { m_inputPixmap.get()                              }  }
    , m_outputPixmap  { new QPixmap  { pixels_per_cell * N + 1, pixels_per_cell * N + 1 }  }
    , m_outputPainter { new QPainter { m_outputPixmap.get()                             }  }

    , m_store       { new QPushButton { tr( "Store~" ), this        }  }
    , m_clear       { new QPushButton { tr( "Clear~" ), this        }  }
    , m_recall      { new QPushButton { tr( "Recall~" ), this       }  }
    , m_showWeights { new QPushButton { tr( "Show weigths~" ), this }  }

    , m_inputGB  { new QGroupBox { tr( "Input pattern~" ), this    }  }
    , m_outputGB { new QGroupBox { tr( "Recalled pattern~" ), this }  }

    , m_inputLabel  { new customLabel { pixels_per_cell, m_inputGB.get() }  }
    , m_outputLabel { new QLabel      { m_outputGB.get()                 }  }

    , m_input( N * N )
    , m_network{ new Network( N * N ) }
    , m_matrixShower{ new MatrixDialog{ this } }
{
  clearField1();
  clearField2();
  setupUI();
  connectSignals();
}

void MainWindow::clearField1()
{
  for (auto& i : m_input ) i = -1;

  drawField( m_inputPainter.get() );
}

void MainWindow::clearField2()
{
  drawField( m_outputPainter.get() );
}

void MainWindow::setupUI()
{
  m_inputLabel->setMaximumSize( pixels_per_cell * N + 1, pixels_per_cell * N + 1 );
  m_inputLabel->setMinimumSize( pixels_per_cell * N + 1, pixels_per_cell * N + 1 );

  m_outputLabel->setMaximumSize( pixels_per_cell * N + 1, pixels_per_cell * N + 1 );
  m_outputLabel->setMinimumSize( pixels_per_cell * N + 1, pixels_per_cell * N + 1 );

  std::unique_ptr< QVBoxLayout > groupbox_layout{ new QVBoxLayout{ m_inputGB.get() } };
  groupbox_layout->addWidget( m_inputLabel.get() );
  m_inputGB->setLayout( groupbox_layout.release() );

  groupbox_layout.reset( new QVBoxLayout{ m_outputGB.get() } );
  groupbox_layout->addWidget( m_outputLabel.get() );
  m_outputGB->setLayout( groupbox_layout.release() );

  std::unique_ptr< QHBoxLayout > top_layout{ new QHBoxLayout{ nullptr } };
  top_layout->addWidget( m_inputGB.get() );
  top_layout->addSpacing( 32 );
  top_layout->addWidget( m_outputGB.get() );

  std::unique_ptr< QHBoxLayout > bottom_layout{ new QHBoxLayout{ nullptr } };
  bottom_layout->addWidget( m_store.get() );
  bottom_layout->addSpacing( 8 );
  bottom_layout->addWidget( m_clear.get() );
  bottom_layout->addSpacing( 8 );
  bottom_layout->addWidget( m_showWeights.get() );
  bottom_layout->addSpacing( 8 );
  bottom_layout->addWidget( m_recall.get() );
  bottom_layout->addSpacing( 8 );

  std::unique_ptr< QVBoxLayout > main_layout{ new QVBoxLayout{ this } };
  main_layout->addLayout( top_layout.release() );
  main_layout->addSpacing( 16 );
  main_layout->addLayout( bottom_layout.release() );

  this->setLayout( main_layout.release() );
}

void MainWindow::connectSignals()
{
  connect( m_inputLabel.get(), SIGNAL( mousePressed( int, int ) ), this, SLOT( clickField1( int, int ) ) );
  connect( m_store.get(), SIGNAL( clicked() ), this, SLOT( store() ) );
  connect( m_clear.get(), SIGNAL( clicked() ), this, SLOT( clearField1() ) );
  connect( m_showWeights.get(), SIGNAL( clicked() ), this, SLOT( showWeights() ) );
  connect( m_recall.get(), SIGNAL( clicked() ), this, SLOT( recall() ) );
}

MainWindow::~MainWindow()
{
}

void MainWindow::paintEvent(QPaintEvent *)
{
  m_inputLabel->setPixmap(  *m_inputPixmap  );
  m_outputLabel->setPixmap( *m_outputPixmap );
}

void MainWindow::clickField1( const int x, const int y )
{
  int pos = 10 * x + y;
  QColor color = (-1 == m_input[pos]) ? Qt::blue : Qt::white;
  m_input[pos] *= -1;
  setPixel( m_inputPainter.get(), x, y, color);
  clearField2();
}

void MainWindow::store()
{
  // TODO: STORE PATTERN in m_input
    Neuron inputNeuron(m_input);
    m_network->storePattern( inputNeuron );
    m_network->calculateWeightMatrix();
}

void MainWindow::showWeights()
{
  // TODO: Get weights
  // TODO: Pass to showMatrixForm
  // TODO: showMatrixForm->showModal();
    m_matrixShower->setMatrix( m_network->getWeightMatrix() );
    m_matrixShower->exec();
}

void MainWindow::recall()
{
  // TODO: Get pattern in m_input
  // TODO: Recall pattern into output.
    Neuron inputNeuron(m_input);
    std::vector< int32_t > output = m_network->recallPattern(inputNeuron).getVals();

  for (int i = 0; i < N; ++i ) {
    for (int j = 0; j < N; ++j ) {
      QColor colour = (1 == output[ 10 * i + j ] ) ? Qt::blue : Qt::white;
      setPixel( m_outputPainter.get(), i, j, colour );
    }
  }
}

} // namespace sc2

