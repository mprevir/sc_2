#include "customLabel.h"

#include <QMouseEvent>
namespace sc2
{
customLabel::customLabel( QWidget* parent )
  : QLabel{ parent }
{
}

void customLabel::mousePressEvent(QMouseEvent *event)
{
  const QPoint p = event->pos();

  emit mousePressed( p );
}
} // namespace sc2
