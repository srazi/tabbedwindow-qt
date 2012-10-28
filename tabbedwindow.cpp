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

#include "tabbedwindow_p.h"
#include "tabview.h"

#include <QMenuBar>


TabbedWindow::TabbedWindow(QWidget *parent) :
    QMainWindow(parent),
    d_ptr(new TabbedWindowPrivate(this))
{
}


TabbedWindow::~TabbedWindow()
{
    delete d_ptr;
}


QWidget* TabbedWindow::currentView()
{
    return d_ptr->currentView();
}


QWidget* TabbedWindowPrivate::currentView()
{
    return tabs->currentWidget();
}


void TabbedWindow::setCurrentView(int index)
{
    d_ptr->setCurrentView(index);
}


int TabbedWindow::insertView(const QPoint &pos, QWidget *page,
                            const QString &text)
{
    return d_ptr->insertView(pos, page, text);
}


int TabbedWindow::addView(QWidget *view, const QString &title)
{
    return d_ptr->addView(view, title);
}


void TabbedWindow::removeView(int index)
{
    d_ptr->removeView(index);
}


TabbedWindowPrivate::TabbedWindowPrivate(TabbedWindow* q_ptr)
{
    // Create tab widget
    tabs = new TabView();
    tabs->setDocumentMode(true);

    // Set up main window
    this->q_ptr = q_ptr;
    this->q_ptr->setCentralWidget(tabs);
}


void TabbedWindowPrivate::setCurrentView(int index)
{
    tabs->setCurrentIndex(index);
}


int TabbedWindowPrivate::insertView(const QPoint &pos, QWidget *page,
                                    const QString &text)
{
    // Get tab's index at the given global postition
    int index = tabs->tabAt(tabs->mapFromGlobal(pos));

    // Insert new tab
    return tabs->insertTab(index, page, text);
}


int TabbedWindowPrivate::addView(QWidget *view, const QString &title)
{
    return tabs->addTab(view, title);
}


void TabbedWindowPrivate::removeView(int index)
{
    tabs->removeTab(index);
}

