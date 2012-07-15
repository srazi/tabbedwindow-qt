#ifndef VIEWBAR_P_H
#define VIEWBAR_P_H

#include <QTabBar>
#include "tabbedwindow.h"


class TabMoveEvent;


class TabBarPrivate : public QTabBar
{
    Q_OBJECT

public:
    TabBarPrivate(QWidget *parent = 0);
    ~TabBarPrivate();

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

protected:
    void createNewWindow(const QPoint&, TabMoveEvent*);
    void moveToWindow(TabbedWindow*, const QPoint&, TabMoveEvent*);
    void tabRemoved(int index);
    
signals:
    
public slots:

private:
    TabMoveEvent *moveEvent;
};

#endif // VIEWBAR_P_H
