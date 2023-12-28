#pragma once

#include <irrKlang.h>
#include <string>
#include <iostream>
#include "sdl.h"
using namespace irrklang;
using namespace std;
class Item
{
public:
	string name= "nothing";
	string fileName = "../Resource/Texture/invisible.png";
	int amount = 0;
	
	string type = "holding";  //type:  using:will be use when click,holding:will be hold when click 

	string showText = "Empty Text";
	float textFontSize = 100.0f;
	float textSizeX = 700.0f;
	float textSizeY = 100.0f;
	SDL_Color textColor = { 255, 255, 255 };
};

