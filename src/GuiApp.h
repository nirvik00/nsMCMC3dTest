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
	ofParameter<bool>isolateXYPlane;
	ofParameter<bool>isolateYZPlane;
	ofParameter<bool>isolateZXPlane;
	ofParameter<int>XYToIsolate;
	ofParameter<int>YZToIsolate;
	ofParameter<int>ZXToIsolate;
	
	ofParameter <string> area;
	ofParameter<float> agentArea1;
	ofParameter<float> agentArea2;
	ofParameter<float> agentArea3;
	ofParameter<float> agentArea4;
	ofParameter<float> agentArea5;

	ofParameter <string> color;
	ofParameter<ofColor> color0;
	ofParameter<ofColor> color1;
	ofParameter<ofColor> color2;
	ofParameter<ofColor> color3;
	ofParameter<ofColor> color4;
	
	ofxPanel gui;
};

