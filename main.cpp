#include <QApplication>
#include <QToolBar>
#include <QMenuBar>

#include "tabbedwindow.h"


int main(int argc, char *argv[])
{
    // Create application
    QApplication a(argc, argv);

    // Create tabbed views
    TabbedWindow w;
    QMainWindow red, green, blue;

    red.setStyleSheet("QMainWindow { background-color: red; }");
    blue.setStyleSheet("QMainWindow { background-color: blue; }");
    green.setStyleSheet("QMainWindow { background-color: green; }");

    w.addView(&red, QString("Red View"));
    w.addView(&blue, QString("Blue view"));
    w.addView(&green, QString("Green view"));

    // Added test toolbar
    QToolBar *tb = red.addToolBar("toolbar");
    tb->addAction("RED");

    // Add test menubar
    QAction *ma = new QAction("Test", &green);
    QMenu *m = green.menuBar()->addMenu("File");
    m->addAction(ma);

    // Set size and show
    w.resize(400, 400);
    w.show();
    
    // Start mainloop
    return a.exec();
}
