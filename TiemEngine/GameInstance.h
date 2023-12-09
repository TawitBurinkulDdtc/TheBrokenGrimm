#pragma once
#include<string>
#include<vector>
#include"Item.h"

class GameInstance
{
	static GameInstance* instance;
	
public:
	static GameInstance* GetInstance();

	//items
	int testIntInstance=0;
	
	vector<Item> inventory;
	
	//info
	int PlayerFrom = 0; 
	int potatoEaten = 0;
	
};