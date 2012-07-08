#ifndef TABBEDWINDOWPRIVATE_H
#define TABBEDWINDOWPRIVATE_H

#include "tabbedwindow.h"


class TabbedWindowPrivate
{
public:
    TabbedWindowPrivate(TabbedWindow* q_ptr);

    int addView(QWidget* view, QString &title);
    void removeView(int index);

private:
    TabbedWindow *q_ptr;
    QTabWidget* tabs;
};

#endif // TABBEDWINDOWPRIVATE_H
