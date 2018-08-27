#include "ofMain.h"
#include "ofApp.h"
#include "GuiApp.h"

#include "ofAppGLFWWindow.h"

int main( ){
	
	ofGLFWWindowSettings settings;

	//gui window
	settings.setSize(225, 600);
	settings.setPosition(ofVec2f(0, 0));
	settings.resizable = false;
	shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);

	//ofApp window
	settings.setSize(1350, 1000);
	settings.setPosition(ofVec2f(225, 0));
	settings.resizable = false;
	shared_ptr<ofAppBaseWindow> appWindow = ofCreateWindow(settings); 

	shared_ptr<GuiApp> guiApp(new GuiApp);
	shared_ptr<ofApp> viewerApp(new ofApp);

	viewerApp->gui = guiApp;

	ofRunApp(appWindow, viewerApp);
	ofRunApp(guiWindow, guiApp);
	
	ofRunMainLoop();
}
