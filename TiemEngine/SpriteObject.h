#pragma once
#include "GameObject.h"
#include "SDL.h"

class SpriteObject: public GameObject {
private:
	bool animated = false;
	int frames = 0;
	int speed = 10;
	int row = 0;
	int col = 0;
	float newUV[8];
	float MaxRow = 0.0f;
	float MaxCol = 0.0f;
	
public:
	SpriteObject(const char* path,int MaxR, int MaxC);
	void updateAnimate();
	void CalculateUV(int r, int c);
	virtual void Render(glm::mat4 globalModelTransform);
	virtual void UpdateFrame();
	
};