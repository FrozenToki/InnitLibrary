#include "MenuManager.h"
#include "app/ApplicationInnit.h"

MenuManager::MenuManager(ApplicationInnit *a) : app(a) {
	modes.reserve(10);
	modeNames.reserve(10);
}

void MenuManager::addControll(Ssd1306 *dis, ButtonCross *buttC) {
	display = dis;
	buttonCross = buttC;
}

void MenuManager::addMenuItem(String n, void (*mode)())
{
	modes.push_back(mode);
	modeNames.push_back(n);
}

void MenuManager::loop() {
	
	if (inMode) {
		buttonCross->update();
		if (buttonCross->pressed(0)) {
			while (buttonCross->pressed(0)){
				buttonCross->update();
			}
			// app->getDrivingControl().turnOff();
			inMode = false;
		} else {
			modes[mode]();
		}
		
		
	} else {
		buttonCross->update();
		// if  (buttonCross->pressed(4)) {
		// 	while (buttonCross->pressed(4)){
		// 		buttonCross->update();
		// 	}
		// 	display->resetConnection();
		// }
		if (buttonCross->pressed(1)) {
			while (buttonCross->pressed(1)){
				buttonCross->update();
			}
			if (mode == 0) {
				mode = modes.size() - 1;
			}
			else {
				mode -= 1;
			}
			
		}
		else if (buttonCross->pressed(3)) {
			while (buttonCross->pressed(3)){
				buttonCross->update();
			}
			mode += 1;
		}


		if (mode == modes.size()) {
			mode = 0;
		}

		display->print("_______", modeNames[mode], "_______");
		if (buttonCross->pressed(2)) {
			while (buttonCross->pressed(2)){
				buttonCross->update();
			}
			inMode = true;
		}
	}
}
