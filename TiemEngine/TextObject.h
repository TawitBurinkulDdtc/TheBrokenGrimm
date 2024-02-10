#pragma once

#include "DrawableObject.h"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include <SDL_ttf.h>
#include <string>

class TextObject :public DrawableObject
{
private:
	unsigned int texture;
	const char* fontFileName = "../Resource/Font/Gabilo Display Demo.otf";

public:
	TextObject();
	~TextObject();
	void Render(glm::mat4 globalModelTransform);
	void Update(float deltaTime);
	void LoadText(string text, SDL_Color textColor, int fontSize);
	void setFont(const char* fontLocation);			// example    uiText->setFont("../Resource/Font/ShortBaby-Mg2w.ttf");
};