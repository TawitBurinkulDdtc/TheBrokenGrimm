#pragma once
#include "Level.h"
#include "sdl.h"
#include "InteractableObject.h"
#include "ButtonObject.h"
#include "TextObject.h"
#include "SpriteObject.h"
#include "talkExcelRecord.h"
#include <fstream>
#include <irrKlang.h>
//talkExcelRecord

using namespace irrklang;

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
	void inventoryOpen();

	void showText(string word, SDL_Color textColor, int fontSize, float sizeX, float sizeY);
	void setDialoguePosition();


	void getItem(string name, string displayText, string fileName);
	void loseHoldedItem();
	void objectPickableItem(ButtonObject* object, GameEventType ge,/*getItem info*/ string name, string displayText, string fileName,/*showText info*/string word, SDL_Color textColor, int fontSize, float sizeX, float sizeY);
	void name(string input);
	void box(bool open);
	void setUiPos();
	void picGlow(GameObject* go,bool b);
	void createPlayer(int spriteNum);
	void playerMovement(int spriteNum);
	void excelRecRecording(string sceneName);
	void excelRecClear();


	float playerWalkTo; //might not needed anymore if change to key press movement instead of mouse movement
	int playerFrameDelay;
	float playerStepPerFrame;
	float playerCurrentTime;
	int playerWalkSide = 0; //0 stop, 1 walk left, 2 walk right
	int pSpriteInt = 0;
	float playerStartStandStill = 0;
	float playerStandStillDelay;
	float AverySizeRatio = 0.68f;
	float Avery_y_Position = 330.0f;

	TextObject* uiText;
	TextObject* nameText;
	string displayText;
	SDL_Color dialogueTextColor = { 255, 255, 255 };
	SDL_Color whiteText = { 255, 255, 255 };
	SDL_Color blackText = { 0, 0, 0 };
	TextObject* spaceBar2open;
	bool closeTextSp = false;

	ItemUi* inventoryL[8];
	int holdedItemIndex = -1;
	bool lastHold[8] = { false };
	GameObject* inventoryBox[8];
	float inventoryYPosition = 100.0f;
	bool wahhhhhhhhhh = false;

	float mapWidth;
	GameObject* inventoryBar;

	talkClass talk;
	GameObject* dialogueBox;
	GameObject* screenPic;
	vector<talkExcelRecord> excelRec;
	ifstream readExcel; //readExcel.open("Book1.csv");
	bool finishRead = false;
	int talkEndAt = 0;

	ISoundEngine* SoundEngine;

	private:
	ButtonObject* button1;
	ButtonObject* button2;
	ButtonObject* floatyGlobe;
	//ButtonObject* chest1;
	ButtonObject* key1;
	GameObject* birdAnim;
	ButtonObject* bird;
	ButtonObject* book1;
	ButtonObject* book2;
	ButtonObject* book3;
	ButtonObject* bookHunselAndGretel;
	ButtonObject* mirrorInter;
	GameObject* book1Pic;
	GameObject* book2Pic;
	GameObject* book3Pic;
	GameObject* bookHGPic;
	GameObject* mirrorPic;
	bool checkBookInInventory = false;
	
	ButtonObject* mapInter;



	

	//extern howManyTimeButton1WasPressed;
};
