
#include "GameInstance.h"

GameInstance* GameInstance::instance = nullptr;



GameInstance* GameInstance::GetInstance()
{
	if (instance == nullptr) {
		instance = new GameInstance();
	}
	return instance;
}
