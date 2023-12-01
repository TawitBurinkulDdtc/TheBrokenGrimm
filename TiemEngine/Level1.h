#pragma once
#include "Level.h"
#include "InteractableObject.h"
#include "TextObject.h"

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

	float playerWalkTo; //might not needed anymore if change to key press movement instead of mouse movement
	int playerFrameDelay;
	float playerStepPerFrame;
	float playerCurrentTime;
	int playerWalkSide = 0; //0 stop, 1 walk left, 2 walk right
	TextObject* uiText;
};
