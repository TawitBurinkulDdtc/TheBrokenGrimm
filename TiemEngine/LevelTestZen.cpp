#include "LevelTestZen.h"
#include "ButtonObject.h"
#include "sdl.h"


void LevelTestZen::LevelLoad()
{
	SquareMeshVbo * square = new SquareMeshVbo();
	square->LoadData();
	GameEngine::GetInstance()->AddMesh(SquareMeshVbo::MESH_NAME, square);

	//cout << "Load Level" << endl;
}

void LevelTestZen::LevelInit()
{

	
	GameObject* background = new GameObject();
	background->SetTexture("../Resource/Texture/testVillage.jpeg");
	background->SetSize(20.0f, -4.0f);
	background->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	objectsList.push_back(background);


	ButtonObject* testButton = new ButtonObject();
	testButton->SetTexture("../Resource/Texture/DoNotPress.png");
	testButton->SetSize(100.0f, -100.0f);
	testButton->SetPosition(glm::vec3(300.0f, 800.0f, 0.0f));
	objectsList.push_back(testButton);
	interactableList.push_back(testButton);


	GameObject* objPlayer = new GameObject();
	objPlayer->SetTexture("../Resource/Texture/penguin.png");
	objPlayer->SetPosition(glm::vec3(950.0f, 300.0f, 0.0f));
	objPlayer->SetSize(100.0f, -100.0f);
	objectsList.push_back(objPlayer);


	GameObject* objCursor = new GameObject();
	objCursor->SetTexture("../Resource/Texture/uglyHand.png");
	objCursor->SetSize(100.0f, -100.0f);
	objectsList.push_back(objCursor);

	cursor = objCursor;
	player = objPlayer;
	
	playerWalkTo = player->GetX();
	playerFrameDelay = 10;
	playerStepPerFrame = 4;
	playerCurrentTime = 0;

	//cout << "Init Level" << endl;
}








void LevelTestZen::LevelUpdate()              //Do animation and thing that need "per frame" here
{
	if (SDL_GetTicks() > playerCurrentTime + playerFrameDelay) {

		if (player->GetX() < playerWalkTo - playerStepPerFrame || player->GetX() > playerWalkTo + playerStepPerFrame) {
			if (player->GetX() < playerWalkTo) {
				player->Translate(glm::vec3(playerStepPerFrame, 0, 0));
			}
			else {
				player->Translate(glm::vec3(-playerStepPerFrame, 0, 0));
			}
		}

		playerCurrentTime = SDL_GetTicks();
	}
}

void LevelTestZen::LevelDraw()
{
	GameEngine::GetInstance()->Render(objectsList,true);
	//cout << "Draw Level" << endl;
}

void LevelTestZen::LevelFree()
{
	for (DrawableObject* obj : objectsList) {
		delete obj;
	}
	objectsList.clear();
	//cout << "Free Level" << endl;
}

void LevelTestZen::LevelUnload()
{
	GameEngine::GetInstance()->ClearMesh();
	//cout << "Unload Level" << endl;
}

void LevelTestZen::HandleKey(char key)
{

	switch (key)
	{
	case 'w': player->Translate(glm::vec3(0, 0.3, 0)); break;
	case 's': player->Translate(glm::vec3(0, -0.3, 0)); break;
	case 'a': player->Translate(glm::vec3(-0.3, 0, 0)); break;
	case 'd': player->Translate(glm::vec3(0.3, 0, 0)); break;
	case 'q': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_QUIT; ; break;
	case 'r': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_RESTART; ; break;
	case 'e': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL1; ; break; //LVC. Level change testing add by Zen d13m9y2023
	
	}
}

void LevelTestZen::HandleMouse(int type, int x, int y)
{
	
	//float windowSizeX, windowSizeY;
	//windowSizeX = GameEngine::GetInstance()->GetWindowWidth();
	//windowSizeY = GameEngine::GetInstance()->GetWindowHeight();
	

	cursor->SetPosition(glm::vec3(x, y, 0));
	
	for (int i = 0; i < interactableList.size(); i++) {
			if (interactableList[i]->GetClick(x, y)) {
				interactableList[i]->Interact();
			}
			
	}

	playerWalkTo = x;
	
}