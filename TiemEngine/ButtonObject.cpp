
#include "ButtonObject.h"
#include "GameEngine.h"
#include "SquareMeshVbo.h"


ButtonObject::ButtonObject(){}

void ButtonObject::Interact(){  // pos.x-(size.x/2)
		printf("\nButton.cpp press working well");
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

