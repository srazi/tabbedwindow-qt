#ifndef TABBEDWINDOW_H
#define TABBEDWINDOW_H

#include <QMainWindow>


class TabbedWindowPrivate;


class TabbedWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TabbedWindow(QWidget *parent = 0);
    ~TabbedWindow();

    int addView(QWidget* view, QString &title);
    void removeView(int index);

private:
    TabbedWindowPrivate* d_ptr;
};

#endif // TABBEDWINDOW_H
