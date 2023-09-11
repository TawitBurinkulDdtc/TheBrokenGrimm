#pragma once
#include "GameEngine.h"
#include "SquareMeshVbo.h"
#include "GameObject.h"
#include "ImageObject.h"

class Level
{
private:
	vector<DrawableObject*> objectsList;
	ImageObject * player;

public:
	virtual void LevelLoad();
	virtual void LevelInit();
	virtual void LevelUpdate();
	virtual void LevelDraw();
	virtual void LevelFree();
	virtual void LevelUnload();

	virtual void HandleKey(char key);
	virtual void HandleMouse(int type, int x, int y);
};
