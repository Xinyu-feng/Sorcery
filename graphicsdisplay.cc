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

void GraphicsDisplay::printVec(vector<string> vec) {
	int x = height / 8;
	int y = width / 16;
	for (auto &msg : vec) {
		xw.drawString(x, y, msg);
		y += 18;
	}
}
