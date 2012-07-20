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
    // If left button is pressed start tab move event
    if (event->button() == Qt::LeftButton) {
        QPoint offset = event->globalPos() - window()->pos();

        moveEvent = new TabMoveEvent(offset, tabAt(event->pos()));
    }

    // Call superclass
    QTabBar::mousePressEvent(event);
}


void TabBarPrivate::moveWindow(QWidget *window, const QPoint &pos)
{
    window->move(pos);
}


void TabBarPrivate::mouseReleaseEvent(QMouseEvent *event)
{
    // Call superclass if a button different than the left one was released
    // and return
    if (event->button() != Qt::LeftButton) {
        QTabBar::mouseReleaseEvent(event);
        return;
    }

    //
    TabBarPrivate *w = dynamic_cast<TabBarPrivate*>(
                QApplication::widgetAt(event->globalPos()));

    // Choose action by the widget under the mouse's coordinates
    if (w == NULL) {
        if (count() == 1) {
            // Move the current window into the new position
            moveWindow(window(), event->globalPos());
        } else {
            // Creates a new window with the dragged tab
            createNewWindow(event->globalPos(), moveEvent);
        }
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


void TabBarPrivate::createNewWindow(const QPoint &pos, TabMoveEvent *event)
{
    // Create the new window with the same size and centered under the cursor
    TabbedWindow *wnd = new TabbedWindow();

    wnd->resize(window()->size());
    wnd->move(pos - event->pos());

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
