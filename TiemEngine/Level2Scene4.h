#pragma once
//#include "Level.h"
#include "Level1.h"
#include "InteractableObject.h"
#include "ButtonObject.h"
#include "TextObject.h"

class Level2Scene4 : public Level1
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
	ButtonObject* Hansel;
	ButtonObject* Gretel;
	ButtonObject* Chair;
	ButtonObject* Cabinet;
	ButtonObject* ChairPlacerArea;
	ButtonObject* frontDoor;
	ButtonObject* bedroomDoor;
	GameObject* GretelPic;
	GameObject* chairPic;
	GameObject* cabinetPic;
	GameObject* frontDoorPic;
};
