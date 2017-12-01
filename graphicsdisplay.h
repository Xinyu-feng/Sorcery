#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "state.h"
#include "window.h"

class GraphicsDisplay: public Observer {
	//const int gridSize;
	const int winSize;
	Xwindow xw;
	public:
	//GraphicsDisplay(int gridSize, int winSize);
	void notify(Subject &whoNotified) override;
};
#endif
