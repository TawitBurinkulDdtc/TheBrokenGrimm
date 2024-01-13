#pragma once
#include "GameEngine.h"
#include "SquareMeshVbo.h"
#include "GameObject.h"
#include "ImageObject.h"
#include "GameInstance.h"
#include "ItemUi.h"
#include "talkClass.h"

class Level
{
private:
	vector<DrawableObject*> objectsList;
	GameObject* player;

public:
	virtual void LevelLoad();
	virtual void LevelInit();
	virtual void LevelUpdate();
	virtual void LevelDraw();
	virtual void LevelFree();
	virtual void LevelUnload();

	virtual void HandleKey(char key);
	virtual void HandleMouse(int type, int x, int y);

	ItemUi* inventoryL[8];
	int holdedItemIndex = -1;

	float mapWidth;
	GameObject* inventoryBar;
	GameObject* selectUi;

	talkClass talk;
	GameObject* dialogueCharacter;
};
