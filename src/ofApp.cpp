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
}

void ofApp::initMove() {
	cellTrail.clear();
	random_shuffle(CELLS.begin(), CELLS.end());
	Cell a = CELLS[0];
	cellTrail.push_back(a);
	a.OCCUPIED = 1;
	cout << " move initiated " << a.CellId << endl;
}

void ofApp::moveLeft() {
	Cell cell = cellTrail[cellTrail.size()-1];
	int I = cell.I;	int J = cell.J; int K = cell.K;
	int t= findCellByIndex(--I, J, K);
	cout << " move LEFT init " << t << endl;
	if (t > -1 && checkOccupancy(t) == 0) {
		cellTrail.push_back(CELLS[t]);
		CELLS[t].OCCUPIED = 1;
		cout << " move LEFT accepted " << t << endl;
	}
	else {
		cout << " move LEFT NOT accepted " << t << endl;
	}
}

void ofApp::moveRight() {
	Cell cell = cellTrail[cellTrail.size() - 1];
	int I = cell.I;	int J = cell.J; int K = cell.K;
	int t = findCellByIndex(++I, J, K);
	cout << " move RIGHT init " << t << endl;
	if (t > -1	&& checkOccupancy(t) == 0) {
		cellTrail.push_back(CELLS[t]);
		CELLS[t].OCCUPIED = 1;
		cout << " move RIGHT accepted " << t << endl;
	} else {
		cout << " move RIGHT NOT accepted " << t << endl;
	}
}

void ofApp::moveUp() {
	Cell cell = cellTrail[cellTrail.size() - 1];
	int I = cell.I;	int J = cell.J; int K = cell.K;
	int t = findCellByIndex(I, ++J, K);
	cout << " move UP init " << t << endl;
	if (t > -1 && checkOccupancy(t) == 0) {
		cellTrail.push_back(CELLS[t]);
		CELLS[t].OCCUPIED = 1;
		cout << " move UP accepted " << t << endl;
	}
	else {
		cout << " move UP NOT accepted " << t << endl;
	}
}

void ofApp::moveDown() {
	Cell cell = cellTrail[cellTrail.size() - 1];
	int I = cell.I;	int J = cell.J; int K = cell.K;
	int t = findCellByIndex(I, --J, K);
	cout << " move DOWN init " << t << endl;
	if (t > -1 && checkOccupancy(t) == 0) {
		cellTrail.push_back(CELLS[t]);
		CELLS[t].OCCUPIED = 1;
		cout << " move DOWN accepted " << t << endl;
	}
	else {
		cout << " move DOWN NOT accepted " << t << endl;
	}
}

void ofApp::moveIn() {
	Cell cell = cellTrail[cellTrail.size() - 1];
	int I = cell.I;	int J = cell.J; int K = cell.K;
	int t = findCellByIndex(I, J, --K);
	cout << " move IN init " << t << endl;
	if (t > -1 && checkOccupancy(t) == 0) {
		cellTrail.push_back(CELLS[t]);
		CELLS[t].OCCUPIED = 1;
		cout << " move IN accepted " << t << endl;
	}
	else {
		cout << " move IN NOT accepted " << t << endl;
	}
}

void ofApp::moveOut() {
	Cell cell = cellTrail[cellTrail.size() - 1];
	int I = cell.I;	int J = cell.J; int K = cell.K;
	int t = findCellByIndex(I, J, ++K);
	cout << " move OUT init " << t << endl;
	if (t > -1 && checkOccupancy(t) == 0) {
		cellTrail.push_back(CELLS[t]);
		CELLS[t].OCCUPIED = 1;
		cout << " move OUT accepted " << t << endl;
	}
	else {
		cout << " move OUT NOT accepted " << t << endl;
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
	
	for (int i = 0; i < cellTrail.size(); i++) {
		ofSetColor(0, 0, 255); ofFill();
		cellTrail[i].draw(ofColor(0, 0, 255), false);
	}
	
	int axisDim = gridLength*numXGrids*1.5;
	ofDrawAxis(axisDim);
	cam.end();


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
