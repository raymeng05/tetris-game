#ifndef WINDOW_H
#define WINDOW_H
#include <X11/Xlib.h>
#include <iostream>
#include <string>

class Xwindow {
  Display *d;
  Window w;
  int s, width, height;
  GC gc;
  unsigned long colours[8];

 public:
  Xwindow(int width=500, int height=500);  // Constructor; displays the window.
  ~Xwindow();                              // Destructor; destroys the window.

  enum {Yellow, Gray, Red, Green, Blue, Magenta, White, Black}; // Available colours.

  int getWidth() const;
  int getHeight() const;

  // Draws a Block
  void fillBlock(int x, int y, char blockType);

;

};

#endif
