#pragma once

#include "ofMain.h"

#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Cell.h"

class Agent
{
public:
	vector<Cell> allCells;
	vector<Cell> occupiedCells;
	Cell inCell;

	void setInitialCell();
	void setAllCells();
	void addOccupiedCells();
	void setArea();
	void move();
	void clear();
};

