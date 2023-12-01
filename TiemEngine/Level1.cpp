#include "Level1.h"
#include "ButtonObject.h"
#include "sdl.h"
#include "SpriteObject.h"

#define GIRL_SCALE 2

void Level1::LevelLoad()
{
	SquareMeshVbo * square = new SquareMeshVbo();
	square->LoadData();
	GameEngine::GetInstance()->AddMesh(SquareMeshVbo::MESH_NAME, square);

	//cout << "Load Level" << endl;
}

void Level1::LevelInit()
{

	GameObject* background = new GameObject();
	background->SetTexture("../Resource/Texture/testVillage.jpeg");
	background->SetSize(2000.0f, -1000.0f);
	background->SetPosition(glm::vec3(900.0f, 960.0f, 0.0f));
	backgroundList.push_back(background);

	ButtonObject* testButton = new ButtonObject();
	testButton->SetTexture("../Resource/Texture/DoNotPress.png");
	testButton->SetSize(100.0f, -100.0f);
	testButton->SetPosition(glm::vec3(500.0f, 800.0f, 0.0f));
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
	uiList.push_back(objCursor);

	SpriteObject* Girl = new SpriteObject("../Resource/Texture/girlCensorVersion.png", 4, 10);
	Girl->SetPosition(glm::vec3(950.0f, 300.0f, 0.0f));
	Girl->SetSize(64.0f * 2, 128.0f * 2);
	objectsList.push_back(Girl);
	
	TextObject* objUiText = new TextObject();
	SDL_Color textColor = { 0, 0, 0 }; //(0 to 255)
	objUiText->LoadText("Hello??? anybody?", textColor, 100);
	objUiText->SetPosition(glm::vec3(960.0f, 200.0f, 0.0f));
	objUiText->SetSize(500.0f, -100.0f);
	uiList.push_back(objUiText);

	TextObject* animationTextBug = new TextObject();
	//SDL_Color textColor = { 0, 0, 0 }; //(0 to 255)
	animationTextBug->LoadText("Why is this one bug.. idk probably pointer thingy", textColor, 100);
	animationTextBug->SetPosition(glm::vec3(960.0f, 500.0f, 0.0f));
	animationTextBug->SetSize(500.0f, -100.0f);
	objectsList.push_back(animationTextBug);



	uiText = objUiText;
	
	
	cursor = objCursor;
	//player = objPlayer;
	player = Girl;

	playerWalkTo = player->GetX();
	playerCurrentTime = 0;




	//--------------------- walk speed editer----------------------------
	playerFrameDelay = 1;
	playerStepPerFrame = 10;
	//---------------------------------------------------------------------
	//cout << "Init Level" << endl;

}




void Level1::LevelUpdate()
{	
	/*
	if (SDL_GetTicks() > playerCurrentTime + playerFrameDelay) {


		if (player->GetX() < playerWalkTo - playerStepPerFrame || player->GetX() > playerWalkTo + playerStepPerFrame) {
			if (player->GetX() < playerWalkTo) {
				player->Translate(glm::vec3(playerStepPerFrame, 0, 0));
				GameEngine::GetInstance()->SetDrawArea(player->GetX() - 960, 960 + player->GetX(), 0, 1080);
			}
			else {
				player->Translate(glm::vec3(-playerStepPerFrame, 0, 0));
				GameEngine::GetInstance()->SetDrawArea(player->GetX() - 960, 960 + player->GetX(), 0, 1080);
			}
		}

		playerCurrentTime = SDL_GetTicks();
	}
	*/

	if (SDL_GetTicks() > playerCurrentTime + playerFrameDelay) {
		if (playerWalkSide != 0) {
			if (player->GetX() > 960 && player->GetX() < 3000) {										//set camera limit here
				GameEngine::GetInstance()->SetDrawArea(player->GetX() - 960, 960 + player->GetX(), 0, 1080);
			}
			if (playerWalkSide == 2) {
				player->Translate(glm::vec3(playerStepPerFrame, 0, 0));
				//GameEngine::GetInstance()->SetDrawArea(player->GetX() - 960, 960 + player->GetX(), 0, 1080);
				playerWalkSide = 0;
			}
			else if (playerWalkSide == 1) {
				player->Translate(glm::vec3(-playerStepPerFrame, 0, 0));
				//GameEngine::GetInstance()->SetDrawArea(player->GetX() - 960, 960 + player->GetX(), 0, 1080);
				playerWalkSide = 0;
			}
		}
		playerCurrentTime = SDL_GetTicks();
	}
	player->UpdateFrame();

}

void Level1::LevelDraw()
{
	GameEngine::GetInstance()->Render(backgroundList,true);
	GameEngine::GetInstance()->Render(playerList,false);
	GameEngine::GetInstance()->Render(objectsList,false);
	GameEngine::GetInstance()->Render(uiList, false);

	//cout << "Draw Level" << endl;
}

void Level1::LevelFree()
{
	for (DrawableObject* obj : backgroundList) {
		delete obj;
	}
	backgroundList.clear();
	for (DrawableObject* obj : playerList) {
		delete obj;
	}
	playerList.clear();
	for (DrawableObject* obj : objectsList) {
		delete obj;
	}
	objectsList.clear();
	for (DrawableObject* obj : uiList) {
		delete obj;
	}
	uiList.clear();
	//cout << "Free Level" << endl;
}

void Level1::LevelUnload()
{
	GameEngine::GetInstance()->ClearMesh();
	//cout << "Unload Level" << endl;
}

void Level1::HandleKey(char key)
{

	switch (key)
	{
	//case 'w': player->Translate(glm::vec3(0, 0.3, 0)); break;
	//case 's': player->Translate(glm::vec3(0, -0.3, 0)); break;
	case 'a': playerWalkSide = 1;
		//player->Translate(glm::vec3(-50, 0, 0)); 
		//GameEngine::GetInstance()->SetDrawArea(player->GetX() - 960, 960 + player->GetX(), 0, 1080);
		break;
	case 'd': playerWalkSide = 2;
		//player->Translate(glm::vec3(50, 0, 0)); 
		//GameEngine::GetInstance()->SetDrawArea(player->GetX() - 960, 960 + player->GetX(), 0, 1080); 
		break;
	case 'q': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_QUIT; ; break;
	case 'r': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_RESTART; ; break;
	case 'e': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL_test1; ; break; //LVC. Level change testing add by Zen d13m9y2023
	}
}

void Level1::HandleMouse(int type, int x, int y)
{
	

	
	
	
	//printf("print work  ");

	cursor->SetPosition(glm::vec3(x, y, 0));

	for (int i = 0; i < interactableList.size(); i++) {
		if (interactableList[i]->GetClick(x, y)) {
			interactableList[i]->Interact();
		}
	}

	//playerWalkTo = x;

}