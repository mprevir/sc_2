#pragma once

#include <QLabel>
#include <QPoint>
class QMouseEvent;

namespace sc2
{
class customLabel : public QLabel
{
  Q_OBJECT
signals:
  void mousePressed( const QPoint& );
public:
  customLabel ( QWidget* parent = nullptr);

private:
  virtual void mousePressEvent( QMouseEvent* event );
}; // class customLabel
} // namespace sc2
