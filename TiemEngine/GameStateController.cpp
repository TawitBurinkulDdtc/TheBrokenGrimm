#include "GameStateController.h"
#include "Level.h"
#include "LevelTest.h"
#include "LevelTestZen.h"           //LVC. Level change testing add by Zen d13m9y2023
#include "Level1.h"					// First real level we work in
#include "Level2.h"	

GameStateController::GameStateController()
{
	// set the initial game state
	gameStateCurr = gameStatePrev = gameStateNext = GameState::GS_NONE;

	currentLevel = nullptr;
}

void GameStateController::Init(GameState gameStateInit)
{
	// reset the current, previoud and next game
	gameStateCurr = gameStatePrev = gameStateNext = gameStateInit;
}

void GameStateController::LoadLevel()
{
	if ((gameStateCurr == GameState::GS_RESTART) || (gameStateCurr == GameState::GS_QUIT))
	{
		return;
	}

	switch (gameStateCurr)
	{
		case GameState::GS_LEVEL1:
			currentLevel = new Level1();
			break;
		case GameState::GS_LEVEL2:
			currentLevel = new Level2();
			break;
		case GameState::GS_LEVEL_test1:
			currentLevel = new Level();
			break;
		case GameState::GS_LEVEL_test2:
			currentLevel = new LevelTest();
			break;
		case GameState::GS_LEVEL_Zen:				//LVC. Level change testing add by Zen d13m9y2023
			currentLevel = new LevelTestZen();
			break;
		default:
			cout << "gGameStateCurr : invalid state!!" << endl;
			exit(1);
	}

	currentLevel->LevelLoad();
}

void GameStateController::InitLevel()
{
	currentLevel->LevelInit();
}

void GameStateController::UpdateLevel()
{
	currentLevel->LevelUpdate();
}

void GameStateController::DrawLevel()
{
	currentLevel->LevelDraw();
}

void GameStateController::Freelevel()
{
	currentLevel->LevelFree();
}

void GameStateController::UnloadLevel()
{
	currentLevel->LevelUnload();
}

void GameStateController::HandleKeyLevel(char key)
{
	currentLevel->HandleKey(key);
}

void GameStateController::HandleMouseLevel(int type, int x, int y)
{
	currentLevel->HandleMouse(type, x, y);
}