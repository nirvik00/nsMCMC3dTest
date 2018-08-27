#pragma once

#include "ofMain.h"
#include <vector>

class Cell
{
public:
	int X, Y, Z;
	int CellId, I, J, K;
	float gridL, gridW, gridH;
	int LEVEL = 0;
	int OCCUPIED = 0;

	//ofVec3f pts[7];
	vector<ofVec3f> pts;

	Cell(int, int, int, float, float, float);

	void setIndices(int, int, int, int);
	
	void drawEdges();

	void draw();
	void draw(bool);
	void draw(int, bool);
	
	void draw(ofColor, bool);
	void draw(ofColor, int, bool);

	float cellArea();

};

