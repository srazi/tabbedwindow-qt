#include <QMouseEvent>
#include <QApplication>

#include "tabbar_p.h"
#include "tabview_p.h"
#include "tabmoveevent.h"


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
    TabMoveEvent::MovementType type;
    QPoint pos;

    if (event->button() == Qt::LeftButton) {
        if (count() > 1) {
            type = TabMoveEvent::Dragging;
            pos = event->globalPos();
        } else {
            type = TabMoveEvent::Moving;
            pos = event->globalPos() - window()->pos();
        }

        moveEvent = new TabMoveEvent(type, tabAt(event->pos()), pos);
    }

    // Call superclass
    QTabBar::mousePressEvent(event);
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
    // process the current action
    if (moveEvent->type() == TabMoveEvent::Dragging
            && moveEvent->manhattan(event->globalPos()))
    {
        // Stop dragging
        TabBarPrivate *w = dynamic_cast<TabBarPrivate*>(
                    QApplication::widgetAt(event->globalPos()));

        // Choose action by the widget under the mouse's coordinates
        if (w == NULL) {
            // Creates a new window with the dragged tab
            createNewWindow(event->globalPos(), moveEvent);

        } else {
            // Move the dragged tab into the window under the cursor
            TabbedWindow *wnd = dynamic_cast<TabbedWindow*>(w->window());

            if (wnd != NULL) {
                moveToWindow(wnd, event->globalPos(), moveEvent);
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
    index = wnd->insertTab(pos, page, text);

    // Set it as the current tab and move focus to the new window
    wnd->setCurrentView(index);
    wnd->raise();
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
    // Create the new window with the same size and centered under the cursor
    TabbedWindow *wnd = new TabbedWindow();
    QRect geometry = window()->geometry();

    geometry.moveCenter(pos);
    wnd->setGeometry(geometry);

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


void TabBarPrivate::mouseMoveEvent(QMouseEvent *event)
{
    // No left button or no move event
    if (!(event->buttons() & Qt::LeftButton)
            or moveEvent == NULL
            or moveEvent->type() != TabMoveEvent::Moving) {
        return;
    }

    // Move the window by the delta between the current mouse position and the
    // last one
    window()->move(event->globalPos() - moveEvent->pos());
}
