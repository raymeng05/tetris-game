#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include "window.h"

using namespace std;

Xwindow::Xwindow(int width, int height) : width{width}, height{height} {

    d = XOpenDisplay(NULL);
    if (d == NULL) {
        cerr << "Cannot open display" << endl;
        exit(1);
    }
    s = DefaultScreen(d);
    w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, width, height, 1,
                            BlackPixel(d, s), BlackPixel(d, s));
    XSelectInput(d, w, ExposureMask | KeyPressMask);
    XMapRaised(d, w);

    pm = XCreatePixmap(d, w, width, height, DefaultDepth(d, s));
    gc = XCreateGC(d, pm, 0,(XGCValues *)0);

    XFlush(d);
    XFlush(d);

    // Set up colours.
    Colormap cmap = DefaultColormap(d, s);
    XColor xcolour;
    char color_vals[8][20] = {"yellow", "gray", "red", "green", "blue", "white", "magenta", "black"};
    for (int i = 0; i < 8; ++i) {
        XParseColor(d, cmap, color_vals[i], &xcolour);
        XAllocColor(d, cmap, &xcolour);
        colours[i] = xcolour.pixel;
    }

    XSetForeground(d,gc,colours[Black]);

    // Make window non-resizeable.
    XSizeHints hints;
    hints.flags = (USPosition | PSize | PMinSize | PMaxSize );
    hints.height = hints.base_height = hints.min_height = hints.max_height = height;
    hints.width = hints.base_width = hints.min_width = hints.max_width = width;
    XSetNormalHints(d, w, &hints);

    XSynchronize(d,True);

    XSetWindowBackground(d, w, BlackPixel(d, s));
    XClearWindow(d, w);

    usleep(1000);
}

void Xwindow::fillBlock(int x, int y, char blockType) {
    int colorIndex;
    switch (blockType) {
        case 'I': colorIndex = Yellow; break;
        case 'J': colorIndex = Gray; break;
        case 'L': colorIndex = Red; break;
        case 'O': colorIndex = Green; break;
        case 'S': colorIndex = Blue; break;
        case 'Z': colorIndex = Magenta; break;
        case 'T': colorIndex = White; break;
        default: colorIndex = Black; break; // Default to black if unknown
    }
    XSetForeground(d, gc, colours[colorIndex]);
    int blockWidth = 20;
    int blockHeight = 20;
    int gap = 5;
    XFillRectangle(d, pm, gc, x + gap, y + gap, blockWidth, blockHeight);
}

int Xwindow::getHeight() const {
    return height;
}

int Xwindow::getWidth() const {
    return width;
}

void Xwindow::flush() {
    XCopyArea(d, pm, w, gc, 0, 0, width, height, 0, 0);
    XFlush(d);
}

void Xwindow::drawLine(int x1, int y1, int x2, int y2) {
    XSetForeground(d, gc, colours[Gray]);
    XDrawLine(d, pm, gc, x1, y1, x2, y2);
}

Display* Xwindow::getDisplay() const {
    return d;
}

Window Xwindow::getWindow() const {
    return w;
}

int Xwindow::getScreen() const {
    return s;
}

GC Xwindow::getGC() const {
    return gc;
}

Pixmap Xwindow::getPixmap() const {
    return pm;
}

unsigned long Xwindow::getColour(int index) const {
    if (index >= 0 && index < 8) {
        return colours[index];
    }
    return 0;
}

void Xwindow::drawText(int x, int y, const string &text) {
    XSetForeground(d, gc, colours[Gray]);
    XDrawString(d, pm, gc, x, y, text.c_str(), text.length());
}

Xwindow::~Xwindow() {
    XFreePixmap(d, pm);
    XFreeGC(d, gc);
    XDestroyWindow(d, w);
    XCloseDisplay(d);
}
