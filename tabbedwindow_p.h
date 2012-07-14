#ifndef TABBEDWINDOWPRIVATE_H
#define TABBEDWINDOWPRIVATE_H

#include "tabbedwindow.h"
#include "tabview_p.h"


class TabbedWindowPrivate : public QObject
{
    Q_OBJECT;

public:
    TabbedWindowPrivate(TabbedWindow* q_ptr);

    int addView(QWidget* view, const QString &title);
    int insertView(QPoint pos, QWidget *page, QString text);
    void removeView(int index);

private:
    TabbedWindow *q_ptr;
    TabViewPrivate* tabs;
};

#endif // TABBEDWINDOWPRIVATE_H
