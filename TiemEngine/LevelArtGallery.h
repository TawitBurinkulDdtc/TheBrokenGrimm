#pragma once
//#include "Level.h"
#include "Level1.h"
#include "InteractableObject.h"
#include "ButtonObject.h"
#include "TextObject.h"

class LevelArtGallery : public Level1
{
public:

	
public:
	virtual void LevelLoad();
	virtual void LevelInit();
	virtual void LevelUpdate();
	virtual void LevelDraw();
	virtual void LevelFree();
	virtual void LevelUnload();

	virtual void HandleKey(char key);
	virtual void HandleMouse(int type, int x, int y);


	
	private:

		ButtonObject* i1;
		ButtonObject* i2;

};


/*
i1 = new ButtonObject();
i1->SetTexture("../Resource/Texture/ArtGal/0button.png");
i1->SetSize(300, -150.0f);
i1->SetPosition(glm::vec3(8800.0f, 600.0f, 0.0f));
objectsList.push_back(i1);
interactableList.push_back(i1);
*/