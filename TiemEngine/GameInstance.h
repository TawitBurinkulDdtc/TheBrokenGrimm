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


	bool LV2chairAtCabinet = false;
	bool LV2frontDoorLock = true;
	bool pebbelCollect[4] = { false };
	bool insectCollect = false;
	int pebbleAmount = 0;
	bool PuzzleCollectPebbleDone = false;
	bool usePebbles = false;

	int birdTalking = 0;
};

//GameInstance::GetInstance()->