#pragma once

#include "InteractableObject.h"

class ButtonObject :public InteractableObject
{
	

public:
	
	ButtonObject();
	virtual void Interact();
	//void DetectMouse(float mouseX, float mouseY);
	void printButtonInfo();
	
};

