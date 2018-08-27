#pragma once

#include "ofMain.h"
#include <vector>

class Cell
{
public:
	int X, Y, Z;
	float gridL, gridW, gridH;
	int LEVEL = 0;

	//ofVec3f pts[7];
	vector<ofVec3f> pts;

	Cell(int, int, int, float, float, float);
	void draw();
	void draw(bool);
	void draw(int, bool);

};

