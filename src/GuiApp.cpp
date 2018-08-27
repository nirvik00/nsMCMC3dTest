#include "GuiApp.h"

void GuiApp::setup()
{
	parameters.setName("Controls");
	parameters.add(grids.set("GRIDS"));
	parameters.add(gridLength.set("(slider)GridLength", 10, 5, 15));
	parameters.add(gridWidth.set("(slider)GridWidth", 10, 5, 15));
	parameters.add(gridHeight.set("(slider)GridHeight", 10, 5, 15));
	parameters.add(numXGrids.set("(slider)numXGrids", 5, 1, 15));
	parameters.add(numYGrids.set("(slider)numYGrids", 5, 1, 15));
	parameters.add(numZGrids.set("(slider)numZGrids", 5, 1, 15));
	parameters.add(wireframe.set("(slider)display WireFrame", true));

	parameters.add(isolate.set("ISOLATE LEVELS"));
	parameters.add(isolateZXPlane.set("(boolean)isolate ZX-Plane", false));
	parameters.add(ZXToIsolate.set("(slider)ZX grid to Isolate", 3, 0, 15));

	parameters.add(show.set("SHOW GRIDS"));
	parameters.add(showGrid.set("(boolean) show grids", true));

	parameters.add(color.set("COLOR OF SPACE USED"));
	parameters.add(color0.set("(picker)color Area 0", 100, ofColor(0, 0), 255));

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
