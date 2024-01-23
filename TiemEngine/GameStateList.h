#pragma once

enum GameState
{
	// list of all game states 
	GS_LEVEL1 = 0,
	GS_LEVEL2,
	GS_LEVEL_test1, 
	GS_LEVEL_test2,
	GS_LEVEL_Zen,  //LVC. Level change testing add by Zen d13m9y2023
	GS_LEVEL_Template,

	// special game state. Do not change
	GS_RESTART,
	GS_QUIT,
	GS_NONE
};