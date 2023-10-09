#pragma once

#include "GameObject.h"

class InteractableObject :public GameObject
{
	

public:
	InteractableObject();
	virtual void Interact() = 0;
	bool GetClick(float mouseX, float mouseY);
};

