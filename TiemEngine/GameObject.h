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

	void AddTextures(const char* path);
	void ChangeTextures(int texIndex);

	int renderMode = 1; //book1Pic->renderMode = 2;

	string savePic = " ";

	vector<unsigned int> textures;
};






