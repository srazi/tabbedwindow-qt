#include "tabbedwindow_p.h"
#include "tabview_p.h"
#include "tabbar_p.h"


TabbedWindowPrivate::TabbedWindowPrivate(TabbedWindow* q_ptr)
{
    // Create tab widget
    tabs = new TabViewPrivate();
    tabs->setTabsClosable(true);
    tabs->setDocumentMode(true);

    // Set up main window
    this->q_ptr = q_ptr;
    this->q_ptr->setCentralWidget(tabs);
}


int TabbedWindowPrivate::insertView(const QPoint &pos, QWidget *page,
                                    const QString &text)
{
    // Get tab's index at the given global postition
    int index = tabs->tabAt(tabs->mapFromGlobal(pos));

    // Insert new tab
    return tabs->insertTab(index, page, text);
}


int TabbedWindowPrivate::addView(QWidget *view, const QString &title)
{
    return tabs->addTab(view, title);
}


void TabbedWindowPrivate::removeView(int index)
{
    tabs->removeTab(index);
}
