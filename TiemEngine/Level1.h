#pragma once
#include "Level.h"
#include "InteractableObject.h"

class Level1 : public Level
{
private:
	vector<DrawableObject*> objectsList;
	vector<InteractableObject*> interactableList;
	GameObject* player;
	//ImageObject* background;

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
