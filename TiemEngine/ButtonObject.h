#pragma once

#include "InteractableObject.h"

#include <irrKlang.h>

using namespace irrklang;

class ButtonObject :public InteractableObject
{
	

public:
	
	ButtonObject();
	virtual void Interact();
	//void DetectMouse(float mouseX, float mouseY);
	void printButtonInfo();

	ISoundEngine* SoundEngine;
	
};

