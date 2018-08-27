#include "ofApp.h"

int ofApp::findCellByIndex(int u, int v, int w) {
	int idx = -1;
	for (int t = 0; t < CELLS.size(); t++) {
		int i = CELLS[t].I;
		int j = CELLS[t].J;
		int k = CELLS[t].K;
		if (u == i && v == j && k == w) {
			idx = CELLS[t].CellId;
		}
	}
	return idx;
}

int ofApp::checkOccupancy(int u) {
	int sum = 0;
	for (int t = 0; t < cellTrail.size(); t++) {
		if (CELLS[u].CellId == cellTrail[t].CellId) { sum++; break; }
	}
	if (sum == 0) return 0;
	else return 1;
}

void ofApp::clearTrail() {
	cellTrail.clear();
	MSG = "";
}

void ofApp::initMove() {
	cellTrail.clear();
	random_shuffle(CELLS.begin(), CELLS.end());
	Cell a = CELLS[0];
	cellTrail.push_back(a);
	a.OCCUPIED = 1;
	MSG += "\nmove initiated, initial cell=" + to_string(a.CellId);
}

void ofApp::moveLeft() {
	Cell cell = cellTrail[cellTrail.size()-1];
	int I = cell.I;	int J = cell.J; int K = cell.K;
	int t= findCellByIndex(--I, J, K);
	MSG += "\nmove  LEFT initiated";
	if (t > -1 && checkOccupancy(t) == 0) {
		cellTrail.push_back(CELLS[t]);
		CELLS[t].OCCUPIED = 1;
		MSG += "\nmove accepted, cell id=" + to_string(t);
	}
	else {
		MSG += "\nmove rejected";
	}
}

void ofApp::moveRight() {
	Cell cell = cellTrail[cellTrail.size() - 1];
	int I = cell.I;	int J = cell.J; int K = cell.K;
	int t = findCellByIndex(++I, J, K);
	cout << " move RIGHT init " << t << endl;
	MSG += "\nmove  RIGHT initiated";
	if (t > -1 && checkOccupancy(t) == 0) {
		cellTrail.push_back(CELLS[t]);
		CELLS[t].OCCUPIED = 1;
		MSG += "\nmove accepted, cell id=" + to_string(t);
	}
	else {
		MSG += "\nmove rejected";
	}
}

void ofApp::moveUp() {
	Cell cell = cellTrail[cellTrail.size() - 1];
	int I = cell.I;	int J = cell.J; int K = cell.K;
	int t = findCellByIndex(I, ++J, K);
	cout << " move UP init " << t << endl;
	MSG += "\nmove  UP initiated";
	if (t > -1 && checkOccupancy(t) == 0) {
		cellTrail.push_back(CELLS[t]);
		CELLS[t].OCCUPIED = 1;
		MSG += "\nmove accepted, cell id=" + to_string(t);
	}
	else {
		MSG += "\nmove rejected";
	}
}

void ofApp::moveDown() {
	Cell cell = cellTrail[cellTrail.size() - 1];
	int I = cell.I;	int J = cell.J; int K = cell.K;
	int t = findCellByIndex(I, --J, K);
	cout << " move DOWN init " << t << endl;
	MSG += "\nmove  DOWN initiated";
	if (t > -1 && checkOccupancy(t) == 0) {
		cellTrail.push_back(CELLS[t]);
		CELLS[t].OCCUPIED = 1;
		MSG += "\nmove accepted, cell id=" + to_string(t);
	}
	else {
		MSG += "\nmove rejected";
	}
}

void ofApp::moveIn() {
	Cell cell = cellTrail[cellTrail.size() - 1];
	int I = cell.I;	int J = cell.J; int K = cell.K;
	int t = findCellByIndex(I, J, --K);
	cout << " move IN init " << t << endl;
	MSG += "\nmove  IN initiated";
	if (t > -1 && checkOccupancy(t) == 0) {
		cellTrail.push_back(CELLS[t]);
		CELLS[t].OCCUPIED = 1;
		MSG += "\nmove accepted, cell id=" + to_string(t);
	}
	else {
		MSG += "\nmove rejected";
	}
}

void ofApp::moveOut() {
	Cell cell = cellTrail[cellTrail.size() - 1];
	int I = cell.I;	int J = cell.J; int K = cell.K;
	int t = findCellByIndex(I, J, ++K);
	cout << " move OUT init " << t << endl;
	MSG += "\nmove  OUT initiated";
	if (t > -1 && checkOccupancy(t) == 0) {
		cellTrail.push_back(CELLS[t]);
		CELLS[t].OCCUPIED = 1;
		MSG += "\nmove accepted, cell id=" + to_string(t);
	}
	else {
		MSG += "\nmove rejected";
	}
}

void ofApp::resetSys() {
	CELLS.clear();	
	int m = 0;
	int x = 0; 
	for (int i = 0; i < numXGrids; i++) {
		int y = 0;
		for (int j = 0; j < numYGrids; j++) {
			int z = 0;
			for (int k = 0; k < numZGrids; k++) {
				Cell cell(x, y, z, gridLength, gridWidth, gridHeight);
				cell.setIndices(m, i, j, k);
				CELLS.push_back(cell);
				z += gridHeight;
				m++;
			}
			y += gridWidth;
		}
		x += gridLength;
	}
}

void ofApp::setup(){
	srand(unsigned(std::time(0)));
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
	MSG = "\npress 'a' 'A' to start ";
	resetSys();
}

void ofApp::update(){

	gridLength = gui->gridLength;
	gridWidth = gui->gridWidth;
	gridHeight = gui->gridHeight;
	numXGrids = gui->numXGrids;
	numYGrids = gui->numYGrids;
	numZGrids = gui->numZGrids;
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
	
	if (gui->showGrid == true) {
		for (int i = 0; i < CELLS.size(); i++) {
			if (isolateZXPlane == true) { CELLS[i].draw(ZXToIsolate, gui->wireframe); }
			else { CELLS[i].draw(gui->wireframe); }
		}
	}
	
	
	for (int i = 0; i < cellTrail.size(); i++) {
		ofColor co = gui->color0; ofFill();
		cellTrail[i].draw(co, false);
	}
	
	int axisDim = gridLength*numXGrids*1.5;
	ofDrawAxis(axisDim);
	cam.end();

	ofDisableDepthTest();

	ofDrawBitmapStringHighlight(" Mouse Controls for 3d interface            ", 10, 20);
	ofDrawBitmapStringHighlight("--------------------------------------------", 10, 40);
	ofDrawBitmapStringHighlight(" Orbit: left-mouse button drag              ", 10, 60);
	ofDrawBitmapStringHighlight(" (Drag down & left)                         ", 10, 80);
	ofDrawBitmapStringHighlight(" (Axis : Red +X, Blue +Y, Green +Z          ", 10, 100);
	ofDrawBitmapStringHighlight(" Pan: middle-mouse button drag              ", 10, 120);
	ofDrawBitmapStringHighlight(" Zoom: scroll  / right-mouse drag           ", 10, 140);
	ofDrawBitmapStringHighlight("Keyboard Controls                           ", 10, 180);
	ofDrawBitmapStringHighlight("-----------------------------------------   ", 10, 200);
	ofDrawBitmapStringHighlight("Press 'e' or 'E' to reset system            ", 10, 220);
	ofDrawBitmapStringHighlight("Press 'c' or 'C' to clear cell trails       ", 10, 240);
	ofDrawBitmapStringHighlight("Press 'a' or 'A' to reset init cell trail   ", 10, 260);
	ofDrawBitmapStringHighlight("Press 'l' or 'L' to move left               ", 10, 280);
	ofDrawBitmapStringHighlight("Press 'r' or 'R' to move right              ", 10, 300);
	ofDrawBitmapStringHighlight("Press 'u' or 'U' to move up                 ", 10, 320);
	ofDrawBitmapStringHighlight("Press 'd' or 'D' to move down               ", 10, 340);
	ofDrawBitmapStringHighlight("Press 'i' or 'I' to move in                 ", 10, 360);
	ofDrawBitmapStringHighlight("Press 'o' or 'O' to move out                ", 10, 380);
	ofDrawBitmapStringHighlight("--------------------------------------------", 10, 440);
	ofDrawBitmapStringHighlight("GRID: Left Window Controls                  ", 10, 460);
	ofDrawBitmapStringHighlight("--------------------------------------------", 10, 480);
	ofDrawBitmapStringHighlight("Sliders for various numerical parameters    ", 10, 500);
	ofDrawBitmapStringHighlight("Boolean toggles for wireframe / color cells ", 10, 520);
	ofDrawBitmapStringHighlight("Color picker R,G,B,A for user cell trail    ", 10, 540);
	
	ofSetColor(255,0,0); ofFill(); ofDrawBitmapString(MSG,1000,40);


}

void ofApp::keyPressed(int key){
	if (key == 'e') { resetSys(); }
	if (key == 'c') { clearTrail(); }
	if (key == 'a') { initMove(); }
	if (key == 'l') { moveLeft(); }
	if (key == 'r') { moveRight(); }
	if (key == 'u') { moveUp(); }
	if (key == 'd') { moveDown(); }
	if (key == 'i') { moveIn(); }
	if (key == 'o') { moveOut(); }
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
