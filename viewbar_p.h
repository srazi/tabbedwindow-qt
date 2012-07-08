#ifndef VIEWBAR_P_H
#define VIEWBAR_P_H

#include <QtGui>

class ViewBarPrivate : public QTabBar
{
    Q_OBJECT
public:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    
signals:
    
public slots:

private:
    QPoint dragStartPos;
    
};

#endif // VIEWBAR_P_H
