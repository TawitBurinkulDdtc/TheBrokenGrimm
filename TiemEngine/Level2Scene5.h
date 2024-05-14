#pragma once
//#include "Level.h"
#include "Level1.h"
#include "InteractableObject.h"
#include "ButtonObject.h"
#include "TextObject.h"

class Level2Scene5 : public Level1
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
	ButtonObject* pebble[3];
	GameObject* GretelPic;
	GameObject* pebblePic[3];
    GameObject* pebblePic1;


	int pebbleAmount = 0;
	int lastAmount = 0;
	TextObject* sayPebble;
	TextObject* showAmount;
	bool openAmount = false;
};
