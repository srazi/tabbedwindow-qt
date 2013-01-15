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

#ifndef GHOSTWINDOW_H
#define GHOSTWINDOW_H

#include <QWidget>


class TabBar;

/*
 * This widget is a static screenshot of the original tab view.
 *
 * It will be created during the Drag&Drop action as a visual feedback for the
 * user.
 *
 * When moving this widget on the screen use moveWithOffest() instead of move()
 * so the mouse cursor will maintain the current offset from the upper left
 * corner of the window as when the D&D operation has started.
 */
class GhostWindow : public QWidget
{
    Q_OBJECT

public:
    // Constructor accepts the reference to the tab bar widget and the position
    // of the cursor local to the tab bar itself
    explicit GhostWindow(TabBar *tabbar, const QPoint& pos);

    // Offset between the position of the cursor on the tab bar and the upper
    // left position of the tab bar's window.
    const QPoint offset() { return m_offset; }

    // Index of the original tab in the tab bar
    const int index() { return m_index; }

    // Move the widget into the given position taking in accout the current
    // offest() value
    void moveWithOffset(const QPoint&);

    // Return True if the difference between the position of the original
    // widget and given point is greater than the
    // QApplication::startDragDistance() value
    bool dragStarted(const QPoint&);

private:
    QPoint m_offset;
    int m_index;
    QPoint m_originPos;
};

#endif // GHOSTWINDOW_H
