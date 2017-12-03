#include <iostream>
#include "graphicsdisplay.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay(int width, int height): 
	width{width}, height{height}, xw{width, height} {
	clearScreen();
}

void GraphicsDisplay::clearScreen() {
	xw.fillRectangle(0, 0, width, height, Xwindow::White);
}
