#pragma once
//#include "Level.h"
#include "Level1.h"
#include "InteractableObject.h"
#include "ButtonObject.h"
#include "TextObject.h"

class Level2Scene5p3 : public Level1
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
	ButtonObject* stick;
	GameObject* stickPic;
	ButtonObject* pebble;

};
