#include "QtGui"
#include "tabbar_p.h"
#include "tabbedwindow.h"
#include "tabview_p.h"


TabBarPrivate::TabBarPrivate(QWidget *parent) :
    QTabBar(parent)
{
}


TabBarPrivate::~TabBarPrivate()
{
    delete moveEvent;
}


void TabBarPrivate::mousePressEvent(QMouseEvent *event)
{
    // If left button is pressed save current mouse position for
    // possible draggin action triggered in the future
    if (event->button() == Qt::LeftButton) {
        qDebug() << "left button pressed at" << event->globalPos();
        moveEvent = new TabMoveEvent(DRAG, tabAt(event->pos()),
                                     event->globalPos());
    }

    // Call superclass
    QTabBar::mousePressEvent(event);
}


bool TabMoveEvent::manhattan(const QPoint &pos)
{
    return (m_pos - pos).manhattanLength() > QApplication::startDragDistance();
}


void TabBarPrivate::mouseReleaseEvent(QMouseEvent *event)
{
    // Call superclass if a button different than the left one was released
    // and return
    if (event->button() != Qt::LeftButton) {
        QTabBar::mouseReleaseEvent(event);
        return;
    }

    // If left button was released and a move action is involved
    // stop the current action
    if (moveEvent->type() == DRAG && moveEvent->manhattan(event->globalPos()))
    {
        // Stop dragging
        TabBarPrivate *w = dynamic_cast<TabBarPrivate*>(
                    QApplication::widgetAt(event->globalPos()));

        qDebug() << "stop dragging tab" << "on widget" << w;

        // Chose action by the widget under the mouse's coordinates
        if (w == NULL) {
            // Creates a new window with the dragged tab
            createNewWindow(event->globalPos(), moveEvent);

        } else {
            // Move the dragged tab into the window under the cursor
            TabbedWindow *wnd = dynamic_cast<TabbedWindow*>(w->window());

            if (wnd != NULL) {
                moveToWindow(wnd, event->globalPos(), moveEvent);
            } else {
                qDebug() << "TabBarPrivate not inside a TabbedWindow!!!";
            }
        }

        // Reset move event
        moveEvent = NULL;
    }
}


void TabBarPrivate::moveToWindow(TabbedWindow *wnd, const QPoint &pos,
                                 TabMoveEvent *event)
{
    // Remove view from this window
    TabViewPrivate *view = static_cast<TabViewPrivate*>(parent());
    int index = event->index();
    QString text = tabText(index);
    QWidget *page = view->widget(index);

    view->removeTab(index);

    // Insert tab into the new window at the given cursor's position
    wnd->insertTab(pos, page, text);
}


void TabBarPrivate::tabRemoved(int index)
{
    if (count() == 0) {
        window()->close();
    }
}


void TabBarPrivate::createNewWindow(const QPoint &pos,
                                    TabMoveEvent *event)
{
    // Create the new window with the same size and positioned under the cursor
    TabbedWindow *wnd = new TabbedWindow();
    wnd->resize(window()->size());
    wnd->move(pos);

    // Move widget to the new window
    TabViewPrivate *view = static_cast<TabViewPrivate*>(parent());
    int index = event->index();
    QWidget *tab = view->widget(index);
    QString text = view->tabText(index);

    view->removeTab(index);
    wnd->addView(tab, text);

    // Show the new window
    wnd->show();
}


TabMoveEvent::TabMoveEvent(MovementTypeEnum type, int index, QPoint pos)
{
    m_type = type;
    m_index = index;
    m_pos = pos;
}


void TabBarPrivate::mouseMoveEvent(QMouseEvent *event)
{
//    // No left button
//    if (!(event->buttons() & Qt::LeftButton)) {
//        qDebug() << "no left button";
//        return;
//    }

//    // We are already dragging
//    if (dragging > -1) {
//        return;
//    }

//    // No far enough
//    if ((event->pos() - dragStartPos).manhattanLength()
//            < QApplication::startDragDistance()) {
//        qDebug() << "no far enough"
//                 << ((event->pos() - dragStartPos).manhattanLength())
//                 << QApplication::startDragDistance();
//        return;
//    }

//    // Start dragging
//    qDebug() << "start dragging tab" << tabAt(event->pos());
//    dragging = tabAt(event->pos());
}
