#pragma once
#include "Level.h"
#include "sdl.h"
#include "InteractableObject.h"
#include "ButtonObject.h"
#include "TextObject.h"
#include "SpriteObject.h"

class Level1 : public Level
{
public:

	vector<DrawableObject*> uiList;
	vector<DrawableObject*> playerList;
	vector<DrawableObject*> objectsList;
	vector<DrawableObject*> backgroundList;
	
	vector<InteractableObject*> interactableList;
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
	
	void refreshInventoryPic();
	void createInventory();
	void inventoryLogic(); //put in handle mouse

	void showText(string word, SDL_Color textColor, int fontSize, float sizeX, float sizeY);
	void getItem(string name, string displayText, string fileName);
	void objectPickableItem(ButtonObject* object, GameEventType ge,/*getItem info*/ string name, string displayText, string fileName,/*showText info*/string word, SDL_Color textColor, int fontSize, float sizeX, float sizeY);


	float playerWalkTo; //might not needed anymore if change to key press movement instead of mouse movement
	int playerFrameDelay;
	float playerStepPerFrame;
	float playerCurrentTime;
	int playerWalkSide = 0; //0 stop, 1 walk left, 2 walk right
	int pSpriteInt = 0;
	float playerStartStandStill = 0;
	float playerStandStillDelay;

	TextObject* uiText;
	string displayText;
	ButtonObject* button1;
	ButtonObject* button2;
	ButtonObject* floatyGlobe;
	//ButtonObject* chest1;
	ButtonObject* key1;


	//extern howManyTimeButton1WasPressed;
};
