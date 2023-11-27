#pragma once
#include "glm.hpp"
#include <vector>

using namespace std;

class DrawableObject
{
protected:
	glm::vec3 pos;   // usually we will use only x and y
	glm::vec3 size;  // usually we will use only x and y
	glm::vec3 scale; // usually we will use only x and y

public:
	glm::mat4 getTransform();

	DrawableObject();
	~DrawableObject();
	virtual void Render(glm::mat4 globalModelTransform) = 0;
	void SetSize(float sizeX, float sizeY);
	void SetPosition(glm::vec3 newPosition);
	void Translate(glm::vec3 moveDistance);
	// override function update animation frame 
	virtual void UpdateFrame();
	float GetX();
	float GetY();
	//Rotate, Scale ???

};

