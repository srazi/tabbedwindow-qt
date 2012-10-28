/*
 * Copyright (c) 2012, Daniele Esposti <expo@expobrain.net>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * The name of the contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "tabbedwindow.h"

#include <QApplication>
#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QMenuBar>

/*
 * Demo application to show the tabbedwindow behaviour
 */
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
