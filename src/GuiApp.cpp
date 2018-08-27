#include "GuiApp.h"

void GuiApp::setup()
{
	parameters.setName("Controls");
	parameters.add(grids.set("GRIDS"));
	parameters.add(gridLength.set("GridLength", 10, 5, 15));
	parameters.add(gridWidth.set("GridWidth", 10, 5, 15));
	parameters.add(gridHeight.set("GridHeight", 10, 5, 15));
	parameters.add(numXGrids.set("numXGrids", 5, 1, 15));
	parameters.add(numYGrids.set("numYGrids", 5, 1, 15));
	parameters.add(numZGrids.set("numZGrids", 5, 1, 15));
	parameters.add(wireframe.set("display WireFrame", true));

	parameters.add(isolate.set("ISOLATE LEVELS"));
	parameters.add(isolateZXPlane.set("isolate ZX-Plane", false));
	parameters.add(ZXToIsolate.set("ZX grid Isolate", 3, 0, 15));


	parameters.add(area.set("AREA"));
	parameters.add(agentArea1.set("Area 0", 2500, 2500, 50000));
	parameters.add(agentArea2.set("Area 1", 2500, 2500, 50000));
	parameters.add(agentArea3.set("Area 2", 2500, 2500, 50000));
	parameters.add(agentArea4.set("Area 3", 2500, 2500, 50000));
	parameters.add(agentArea5.set("Area 4", 2500, 2500, 50000));

	parameters.add(color.set("COLOR"));
	parameters.add(color0.set("color Area 0", 100, ofColor(0, 0), 255));
	parameters.add(color1.set("color Area 1", 100, ofColor(0, 0), 255));
	parameters.add(color2.set("color Area 2", 100, ofColor(0, 0), 255));
	parameters.add(color3.set("color Area 3", 100, ofColor(0, 0), 255));
	parameters.add(color4.set("color Area 4", 100, ofColor(0, 0), 255));

	gui.setup(parameters);
	gui.setBackgroundColor(0);
	gui.setBorderColor(255);
	gui.setFillColor(ofColor(255, 0, 0));
}
void GuiApp::update()
{
}
void GuiApp::draw()
{
	ofBackground(255);
	ofSetVerticalSync(false);
	gui.draw();
}
