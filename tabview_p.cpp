#include "tabview_p.h"
#include "tabbar_p.h"


TabViewPrivate::TabViewPrivate(QWidget *parent) :
    QTabWidget(parent)
{
    setTabBar(new TabBarPrivate);
}
