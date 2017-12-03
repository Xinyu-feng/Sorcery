#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <iostream>
#include <vector>
#include "window.h"

class GraphicsDisplay {
	const int width;
	const int height;
	Xwindow xw;
	public:
	GraphicsDisplay(int width, int height);
	void clearScreen();
};
#endif
