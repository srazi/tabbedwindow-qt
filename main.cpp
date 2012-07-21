#include <QApplication>
#include <QToolBar>

#include "tabbedwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TabbedWindow w;
    QMainWindow red, green, blue;

    red.setStyleSheet("QMainWindow { background-color: red; }");
    blue.setStyleSheet("QMainWindow { background-color: blue; }");
    green.setStyleSheet("QMainWindow { background-color: green; }");

    QToolBar *tb = red.addToolBar("toolbar");
    tb->addAction("RED");

    w.addView(&red, QString("Red View"));
    w.addView(&blue, QString("Blue view"));
    w.addView(&green, QString("Green view"));
    w.resize(400, 400);
    w.show();
    
    return a.exec();
}
