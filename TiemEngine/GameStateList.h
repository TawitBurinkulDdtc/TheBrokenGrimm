#pragma once

enum GameState
{
	// list of all game states 
	GS_LEVEL1 = 0,
	GS_LEVEL2,
	GS_LEVEL2Scene2,
	GS_LEVEL2Scene3,
	GS_LEVEL2Scene4,
	GS_LEVEL2Scene5,
	GS_LEVEL2Scene5p2,
	GS_LEVEL2Scene6,
	GS_LEVEL3,
	GS_LEVEL3Scene2,
	GS_LEVEL4,
	GS_LEVEL_test1, 
	GS_LEVEL_test2,
	GS_LEVEL_Zen,  //LVC. Level change testing add by Zen d13m9y2023
	GS_LEVELTemplate,


	// special game state. Do not change
	GS_RESTART,
	GS_QUIT,
	GS_NONE
};