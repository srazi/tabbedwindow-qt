#include "tabmoveevent.h"

#include <QApplication>


bool TabMoveEvent::manhattan(const QPoint &pos)
{
    return (m_pos - pos).manhattanLength() > QApplication::startDragDistance();
}


TabMoveEvent::TabMoveEvent(MovementType type, int index, QPoint pos)
{
    m_type = type;
    m_index = index;
    m_pos = pos;
}
