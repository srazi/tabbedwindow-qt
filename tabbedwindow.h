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

    int addView(QWidget* view, const QString &title);
    int insertTab(const QPoint &pos, QWidget *page, const QString &text);
    void removeView(int index);

private:
    TabbedWindowPrivate* d_ptr;
};

#endif // TABBEDWINDOW_H
