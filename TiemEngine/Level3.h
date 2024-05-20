#pragma once
//#include "Level.h"
#include "Level1.h"
#include "InteractableObject.h"
#include "ButtonObject.h"
#include "TextObject.h"

class Level3 : public Level1
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
	ButtonObject* door;
	ButtonObject* placedPebblesHere;
	GameObject* HanselPic;
	GameObject* pebblesPic;

	ButtonObject* campsite;
	ButtonObject* sticks[5];
	ButtonObject* stones[5];
};
