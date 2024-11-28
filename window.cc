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
                            BlackPixel(d, s), WhitePixel(d, s));
    XSelectInput(d, w, ExposureMask | KeyPressMask);
    XMapRaised(d, w);

    Pixmap pix = XCreatePixmap(d,w,width,
            height,DefaultDepth(d,DefaultScreen(d)));
    gc = XCreateGC(d, pix, 0,(XGCValues *)0);

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
        case 'Z': colorIndex = White; break;
        case 'T': colorIndex = Magenta; break;
        default: colorIndex = Black; break; // Default to black if unknown
    }
    XSetForeground(d, gc, colours[colorIndex]);
    XFillRectangle(d, w, gc, x, y, 25, 25);
}

int Xwindow::getHeight() const {
    return height;
}

int Xwindow::getWidth() const {
    return width;
}

Xwindow::~Xwindow() {
    XFreeGC(d, gc);
    XDestroyWindow(d, w);
    XCloseDisplay(d);
}
