#include "tabbedwindow.h"
#include "tabbedwindow_p.h"


TabbedWindow::TabbedWindow(QWidget *parent) :
    QMainWindow(parent)
{
    d_ptr = new TabbedWindowPrivate(this);
}


TabbedWindow::~TabbedWindow()
{
    delete d_ptr;
}


int TabbedWindow::addView(QWidget *view, QString &title)
{
    return d_ptr->addView(view, title);
}


void TabbedWindow::removeView(int index)
{
    d_ptr->removeView(index);
}
