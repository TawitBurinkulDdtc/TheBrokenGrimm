#pragma once



class GameInstance
{
	static GameInstance* instance;
	
public:
	static GameInstance* GetInstance();
	int testIntInstance=0;
	
};