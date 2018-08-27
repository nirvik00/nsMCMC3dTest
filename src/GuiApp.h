#pragma once


#include "ofMain.h"
#include "ofxGui.h"

class GuiApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();
	
	ofParameterGroup parameters;

	ofParameter <string> grids;
	ofParameter<int>numXGrids;
	ofParameter<int>numYGrids;
	ofParameter<int>numZGrids;
	ofParameter<int>gridLength;
	ofParameter<int>gridWidth;
	ofParameter<int>gridHeight;
	ofParameter<bool>wireframe;

	ofParameter <string> isolate;
	ofParameter<bool>isolateZXPlane;
	ofParameter<int>ZXToIsolate;

	ofParameter <string> show;
	ofParameter<bool>showGrid;

	ofParameter <string> color;
	ofParameter<ofColor> color0;
	
	ofxPanel gui;
};

