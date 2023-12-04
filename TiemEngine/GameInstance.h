#pragma once



class GameInstance
{
	static GameInstance* instance;
	
public:
	static GameInstance* GetInstance();

	//items
	int testIntInstance=0;

	//info
	int PlayerFrom = 0; 
	
};