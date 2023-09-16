#pragma once

#include "GameStateList.h"

class Level;

class GameStateController
{
private:
	Level* currentLevel;

public:

	GameState gameStateCurr;
	GameState gameStatePrev;
	GameState gameStateNext;
	

	GameStateController();
	void Init(GameState gameStateInit);

	void LoadLevel();
	void InitLevel();
	void UpdateLevel();
	void DrawLevel();
	void Freelevel();
	void UnloadLevel();
	void HandleKeyLevel(char key);
	void HandleMouseLevel(int type, int x, int y);

};