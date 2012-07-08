#include "viewtabs_p.h"
#include "viewbar_p.h"


ViewTabsPrivate::ViewTabsPrivate(QWidget *parent) :
    QTabWidget(parent)
{
    setTabBar(new ViewBarPrivate);
}
