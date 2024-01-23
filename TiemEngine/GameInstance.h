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

	int gameEvent[500] = { 0 };

	GameEventType key1 = NotPick;
};