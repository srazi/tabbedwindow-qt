## Tabbed Windows implementation in Qt
This is a implementation of the same tabs Drag&Drop behaviour that you can find
in Firefox or Google Chrome browsers.

Any tab dragged outside the main window will create a new window with the
dragged tab and tabs  can be moved between different windwos as well.

This code is a proof of concept of how that behaviour can be implemented in Qt
so the code itself is not perfect nor feature rich.

However I think this is a good starting point for a more complete widget or
framework.

[![demo](http://img.youtube.com/vi/wjV0_3VXtfc/0.jpg)](http://www.youtube.com/watch?v=wjV0_3VXtfc)

## Features
* Add, insert, move and remove views from the tab bar
* Dragging a tab outside the window will creates a new window with the dragged
  tab
* Dragging a tab between windows will move the tab from one window to the
  another
* A QMainWindow can be used as tab's content; its menu bar and toolbars will be
  displayed

## Support
* Works on Windows, Mac and Linux (on Linux there is still a smll bug during
  D&D operations)
* Can be build against Qt 4.8.x (Qt5 support will be completed soon)

## License
Copyright (c) 2012, Daniele Esposti <expo@expobrain.net>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
* Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.
* Neither the name of the <organization> nor the
  names of its contributors may be used to endorse or promote products
  derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
