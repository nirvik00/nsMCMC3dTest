#include "ofApp.h"


void ofApp::resetSys() {
	CELLS.clear();
	int x = 0; 
	for (int i = 0; i < numXGrids; i++) {
		int y = 0;
		for (int j = 0; j < numYGrids; j++) {
			int z = 0;
			for (int k = 0; k < numZGrids; k++) {
				Cell cell(x, y, z, gridLength, gridWidth, gridHeight);
				CELLS.push_back(cell);
				z += gridHeight;
			}
			y += gridWidth;
		}
		x += gridLength;
	}
}

void ofApp::setup(){
	srand(NULL);
	ofEnableDepthTest();
	ofSetVerticalSync(true);
	cam.setDistance(200);
	gridLength = gui->gridLength;
	gridWidth = gui->gridWidth;
	gridHeight = gui->gridHeight;
	numXGrids = gui->numXGrids;
	numYGrids = gui->numYGrids;
	numZGrids = gui->numZGrids;
	isolateZXPlane = gui->isolateZXPlane;
	ZXToIsolate = gui -> ZXToIsolate;
	resetSys();
}

void ofApp::update(){
	gridLength = gui->gridLength;
	gridWidth = gui->gridWidth;
	gridHeight = gui->gridHeight;
	numXGrids = gui->numXGrids;
	numYGrids = gui->numYGrids;
	numZGrids = gui->numZGrids;
	XYToIsolate = gui->XYToIsolate;
	YZToIsolate = gui->YZToIsolate;
	ZXToIsolate = gui->ZXToIsolate;
	isolateZXPlane = gui->isolateZXPlane;
	ZXToIsolate = gui->ZXToIsolate;

	resetSys();
}

void ofApp::draw(){
	ofBackground(255); ofSetColor(0); ofSetLineWidth(1);	
	ofSetColor(255, 0, 0, 50);
	OF_MESH_WIREFRAME;
	cam.begin();
	int x = 0; 
	for (int i = 0; i < CELLS.size(); i++) {
		if (isolateZXPlane == true) { CELLS[i].draw(ZXToIsolate,gui->wireframe); }
		else { CELLS[i].draw(gui->wireframe); }
	}
	int axisDim = gridLength*numXGrids*1.5;
	ofDrawAxis(axisDim);
	cam.end();
}

void ofApp::keyPressed(int key){

}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y ){

}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){

}

void ofApp::mouseReleased(int x, int y, int button){

}

void ofApp::mouseEntered(int x, int y){

}

void ofApp::mouseExited(int x, int y){

}

void ofApp::windowResized(int w, int h){

}

void ofApp::gotMessage(ofMessage msg){

}

void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
