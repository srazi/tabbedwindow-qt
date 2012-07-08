#include "QtGui"
#include "viewbar_p.h"


void ViewBarPrivate::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        qDebug() << "left button pressed at" << event->pos();
        dragStartPos = event->pos();
    }
}


void ViewBarPrivate::mouseMoveEvent(QMouseEvent *event)
{
    // No left button
    if (!(event->buttons() & Qt::LeftButton)) {
        qDebug() << "no left button";
        return;
    }

    // No far enough
    if ((event->pos() - dragStartPos).manhattanLength()
            < QApplication::startDragDistance()) {
        qDebug() << "no far enough"
                 << ((event->pos() - dragStartPos).manhattanLength())
                 << QApplication::startDragDistance();
        return;
    }

    // Start dragging
    QDrag *drag = new QDrag(this);
    QMimeData *mimedata = new QMimeData;

    drag->setMimeData(mimedata);

    qDebug() << "start dragging";
    Qt::DropAction action = drag->exec(Qt::MoveAction);
}
