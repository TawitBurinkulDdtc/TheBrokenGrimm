#pragma once

#include "InteractableObject.h"

#include <irrKlang.h>

using namespace irrklang;

class ItemUi :public InteractableObject
{
	

public:
	
	ItemUi();
	virtual void Interact();
	//void DetectMouse(float mouseX, float mouseY);
	
	void gone();

	ISoundEngine* SoundEngine;
	bool Interacted = false;
};

