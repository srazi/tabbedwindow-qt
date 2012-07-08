#include "QtGui"
#include "viewbar_p.h"


ViewBarPrivate::ViewBarPrivate(QWidget *parent) :
    QTabBar(parent),
    dragging(-1)
{
}

void ViewBarPrivate::mousePressEvent(QMouseEvent *event)
{
    // If left button is pressed save current mouse position for
    // possible draggin action triggered in the future
    if (event->button() == Qt::LeftButton) {
        qDebug() << "left button pressed at" << event->pos();
        dragStartPos = event->pos();
    }

    // Call superclass
    QTabBar::mousePressEvent(event);
}


void ViewBarPrivate::mouseReleaseEvent(QMouseEvent *event) {
    // Call superclass if a button different than the left one was released
    // and return
    if (event->button() != Qt::LeftButton) {
        QTabBar::mouseReleaseEvent(event);
        return;
    }

    // If left button was released and a dragging action is involved
    // stop dragging
    if (dragging > -1) {
        qDebug() << "stop dragging tab" << dragging;
        dragging = -1;
    }
}


void ViewBarPrivate::mouseMoveEvent(QMouseEvent *event)
{
    // No left button
    if (!(event->buttons() & Qt::LeftButton)) {
        qDebug() << "no left button";
        return;
    }

    // We are already dragging
    if (dragging > -1) {
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
    qDebug() << "start dragging tab" << tabAt(event->pos());
    dragging = tabAt(event->pos());
}
