#ifndef VIEWBAR_P_H
#define VIEWBAR_P_H

#include <QtGui>
#include "tabbedwindow.h"


enum MovementTypeEnum {
    DRAG, MOVE
};


class TabMoveEvent
{
public:
    TabMoveEvent();
    TabMoveEvent(MovementTypeEnum type, int index, QPoint pos);

    const MovementTypeEnum type() { return m_type; }
    const int index() { return m_index; }
    const QPoint pos() { return m_pos; }
    bool manhattan(const QPoint &pos);

private:
    MovementTypeEnum m_type;
    int m_index;
    QPoint m_pos;
};


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
