#pragma once

#include "ImageObject.h"

class InteractableObject :public ImageObject
{
	

public:
	InteractableObject();
	virtual void Interact() = 0;
	bool GetClick(float mouseX, float mouseY);
};

