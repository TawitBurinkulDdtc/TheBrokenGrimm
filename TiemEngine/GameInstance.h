#pragma once
#include<string>
#include<vector>

class GameInstance
{
	static GameInstance* instance;
	
public:
	static GameInstance* GetInstance();

	//items
	int testIntInstance=0;
	struct items {
		string name;
		string fileName;
		int amount;
	};
	vector<items> inventory;
	
	//info
	int PlayerFrom = 0; 
	
};