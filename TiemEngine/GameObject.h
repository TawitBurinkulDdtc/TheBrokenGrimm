#pragma once

#include "DrawableObject.h"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include <string>

class GameObject :public DrawableObject
{
protected:
	unsigned int texture;

public:
	GameObject();
	~GameObject();
	
	// function is override from DrawableObject 
	virtual void UpdateFrame();

	void SetTexture(string path);
	virtual void Render(glm::mat4 globalModelTransform);
};






