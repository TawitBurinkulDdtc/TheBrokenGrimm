#pragma once
#include<string>
#include<vector>
#include"Item.h"

enum GameEventType
{
	NotPick,
	AlreadyPick
};

enum PlayerFrom
{
	Left,
	Right,
	Middle
};


class GameInstance
{
	static GameInstance* instance;
	
public:
	static GameInstance* GetInstance();

	//items
	int testIntInstance=0;
	
	vector<Item> inventory;
	
	//info
	PlayerFrom PlayerFrom = PlayerFrom::Left;
	int potatoEaten = 0;

	int gameTracking = 1;

	GameEventType key1 = NotPick;

	bool chairPick = false;
	bool LV2chairAtCabinet = false;
	bool LV2frontDoorLock = true;
	bool talkOnceOutside = false;
	bool pebbelCollect[5] = {false};
	bool insectCollect = false;
	bool stickCollect = false;
	int pebbleAmount = 0;
	bool PuzzleCollectPebbleDone = false;
	bool usePebbles = false;

	int campSiteRequirement = 0;
	bool lv3StartCutScene = false;

	int birdTalking = 0;
};

//GameInstance::GetInstance()->