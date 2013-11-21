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
  void mousePressed( int, int );
public:
  customLabel ( uint32_t pixels_per_cell, QWidget* parent = nullptr);

private:
  const uint32_t m_pixels_per_cell;
  int  m_x;
  int  m_y;
  bool m_clicked;

  virtual void mousePressEvent(   QMouseEvent* event );
  virtual void mouseMoveEvent(    QMouseEvent* event );
  virtual void mouseReleaseEvent( QMouseEvent* event );
}; // class customLabel
} // namespace sc2
