#include "tabbedwindow.h"
#include "tabbedwindow_p.h"


TabbedWindow::TabbedWindow(QWidget *parent) :
    QMainWindow(parent),
    d_ptr(new TabbedWindowPrivate(this))
{
}


TabbedWindow::~TabbedWindow()
{
    delete d_ptr;
}


int TabbedWindow::insertTab(const QPoint &pos, QWidget *page,
                            const QString &text)
{
    return d_ptr->insertView(pos, page, text);
}


int TabbedWindow::addView(QWidget *view, const QString &title)
{
    return d_ptr->addView(view, title);
}


void TabbedWindow::removeView(int index)
{
    d_ptr->removeView(index);
}
