#pragma once

#include <QWidget>
#include <memory>
#include <vector>

class QMouseEvent;
class QPaintEvent;
class QPainter;
class QColor;
class QPixmap;
class QPoint;
class QPushButton;
class QLabel;
class QGroupBox;

namespace sc2
{
constexpr uint32_t N{ 10 };
constexpr uint32_t pixels_per_cell{ 30 };
class customLabel;
class MainWindow : public QWidget
{
  Q_OBJECT
public:
  MainWindow( QWidget *parent = nullptr );
  virtual ~MainWindow();

private:
  std::unique_ptr < QPixmap     > m_inputPixmap;
  std::unique_ptr < QPainter    > m_inputPainter;
  std::unique_ptr < QPixmap     > m_outputPixmap;
  std::unique_ptr < QPainter    > m_outputPainter;

  std::unique_ptr < QPushButton > m_store;
  std::unique_ptr < QPushButton > m_clear;
  std::unique_ptr < QPushButton > m_recall;
  std::unique_ptr < QPushButton > m_showWeights;

  std::unique_ptr < QGroupBox   > m_inputGB;
  std::unique_ptr < QGroupBox   > m_outputGB;

  std::unique_ptr < customLabel > m_inputLabel;
  std::unique_ptr < QLabel      > m_outputLabel;

  std::vector     < int32_t     > m_input;

  // std::unique_ptr< MEGAMATRIXSHOWER > m_matrixShower;

  virtual void paintEvent( QPaintEvent *event );

  void setupUI();
  void connectSignals();
  void clearField2();
private slots:
  void clickField1( const QPoint& p );
  void clearField1();
  void store();
  void recall();
  void showWeights();

};
} // namespace sc2
