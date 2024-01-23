
#include "ButtonObject.h"
#include "GameEngine.h"
#include "SquareMeshVbo.h"



//#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll

ButtonObject::ButtonObject(){
	SoundEngine = createIrrKlangDevice();
}

void ButtonObject::Interact(){  // pos.x-(size.x/2)

		if (SoundEngine) {
			//SoundEngine->play2D("Ahhh.ogg", false);
			//printf("\nButton.cpp press working well");
			//SoundEngine->drop(); // Release resources
		}
		else {
			// Handle the case when the sound engine creation fails
			//printf("\nFailed to create the sound engine");
		}
		Interacted = true;
}




/*
void ButtonObject::DetectMouse(float mouseX, float mouseY) {
	if ((mouseX > pos.x - (size.x / 2) && mouseX < pos.x + (size.x / 2) && mouseY > pos.y - (size.y / 2) && mouseY < pos.y + (size.y / 2))) {
		Interact();
	}
}
*/


void ButtonObject::printButtonInfo() {
	std::cout << "hi" << std::endl;
}

