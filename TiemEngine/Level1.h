#pragma once
#include "Level.h"
#include "InteractableObject.h"

class Level1 : public Level
{
public:

	vector<DrawableObject*> uiList;
	vector<DrawableObject*> playerList;
	vector<DrawableObject*> objectsList;
	vector<DrawableObject*> backgroundList;
	
	vector<InteractableObject*> interactableList;
	GameObject* player;
	GameObject* cursor;
public:
	virtual void LevelLoad();
	virtual void LevelInit();
	virtual void LevelUpdate();
	virtual void LevelDraw();
	virtual void LevelFree();
	virtual void LevelUnload();

	virtual void HandleKey(char key);
	virtual void HandleMouse(int type, int x, int y);

	float playerWalkTo;
	int playerFrameDelay;
	float playerStepPerFrame;
	float playerCurrentTime;
};
