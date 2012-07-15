#ifndef TABMOVEEVENT_H
#define TABMOVEEVENT_H

#include <QObject>
#include <QPoint>


class TabMoveEvent
{
    Q_ENUMS(MovementType)

public:
    enum MovementType {
        Dragging, Moving
    };

    /* Create a new instance of a tab move event passing the movement type, the
       tab index under the mouse cursor and the position of the mouse at the
       start of the tab's move action.

       If the movement type is a DRAG operation, the pos attribute stores the
       global cursor's coordinates, otherwise if the movement is a MOVE
       operation it will store the offset between the cursor's and the top left
       corner of the window.
    */
    TabMoveEvent(MovementType type, int index, QPoint pos = QPoint());

    const MovementType type() { return m_type; }
    const int index() { return m_index; }
    const QPoint pos() { return m_pos; }
    bool manhattan(const QPoint &pos);

private:
    MovementType m_type;
    int m_index;
    QPoint m_pos;
};

#endif // TABMOVEEVENT_H
