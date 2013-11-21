#include "customLabel.h"

#include <QMouseEvent>

namespace sc2
{
customLabel::customLabel( const uint32_t pixels_per_cell, QWidget* parent )
  : QLabel{ parent }
  , m_pixels_per_cell{ pixels_per_cell }
  , m_clicked{ false }
{
}

void customLabel::mousePressEvent(QMouseEvent *event)
{
  if (Qt::LeftButton == event->button()) {
    const QPoint p = event->pos();
    m_x = p.x() / m_pixels_per_cell;
    m_y = p.y() / m_pixels_per_cell;
    m_clicked = true;
    emit mousePressed( m_x, m_y );
  }
}

void customLabel::mouseReleaseEvent( QMouseEvent *event )
{
  if (Qt::LeftButton == event->button()) {
    m_clicked = false;
  }
}

void customLabel::mouseMoveEvent( QMouseEvent *event )
{
  if (m_clicked) {
    const QPoint p = event->pos();
    int x = p.x() / m_pixels_per_cell;
    int y = p.y() / m_pixels_per_cell;
    if ((m_x != x) || (m_y != y)) {
      m_x = x;
      m_y = y;
      if ((m_x >= 0) && (m_x < 10) && (m_y >= 0) && (m_y < 10)) {
        emit mousePressed( m_x, m_y );
      }
    }
  }
}
} // namespace sc2
