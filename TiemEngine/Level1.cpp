#include "Level1.h"
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
	mapWidth = 7764.5f;

	GameObject* background = new GameObject();
	background->SetTexture("../Resource/Texture/BackGround.png");
	background->SetSize(mapWidth, -1080.0f);
	background->SetPosition(glm::vec3(3882.25f, 540.0f, 0.0f));
	backgroundList.push_back(background);


	GameObject* floatyEarthPic = new GameObject();
	floatyEarthPic->SetTexture("../Resource/Texture/Interact_1.png");
	floatyEarthPic->SetSize(mapWidth, -1080.0f);
	floatyEarthPic->SetPosition(glm::vec3(3882.25f, 540.0f, 0.0f));
	backgroundList.push_back(floatyEarthPic);

	
	ButtonObject* floatyEarth = new ButtonObject();
	floatyEarth->SetTexture("../Resource/Texture/invisible.png");
	floatyEarth->SetSize(330.0f, -330.0f);
	floatyEarth->SetPosition(glm::vec3(3995.25f, 584.0f, 0.0f));
	objectsList.push_back(floatyEarth);
	interactableList.push_back(floatyEarth);
	

	ButtonObject* testButton = new ButtonObject();
	testButton->SetTexture("../Resource/Texture/DoNotPress.png");
	testButton->SetSize(100.0f, -100.0f);
	testButton->SetPosition(glm::vec3(500.0f, 800.0f, 0.0f));
	objectsList.push_back(testButton);
	interactableList.push_back(testButton);

	ButtonObject* testButton2 = new ButtonObject();
	testButton2->SetTexture("../Resource/Texture/DoNotPress.png");
	testButton2->SetSize(100.0f, -100.0f);
	testButton2->SetPosition(glm::vec3(1200.0f, 800.0f, 0.0f));
	objectsList.push_back(testButton2);
	interactableList.push_back(testButton2);

	GameObject* objPlayer = new GameObject();
	objPlayer->SetPosition(glm::vec3(950.0f, 300.0f, 0.0f));
	objPlayer->SetTexture("../Resource/Texture/penguin.png");
	objPlayer->SetSize(100.0f, -100.0f);
	objectsList.push_back(objPlayer);
	

	GameObject* objCursor = new GameObject();
	objCursor->SetTexture("../Resource/Texture/uglyHand.png");
	objCursor->SetSize(100.0f, -100.0f);
	uiList.push_back(objCursor);

	SpriteObject* Girl = new SpriteObject("../Resource/Texture/girl.png", 4, 10);
	Girl->SetSize(64.0f * 2, 128.0f * 2);
	objectsList.push_back(Girl);
	if (GameInstance::GetInstance()->PlayerFrom == 1) {
		Girl->SetPosition(glm::vec3(950.0f, 300.0f, 0.0f));
		GameEngine::GetInstance()->SetDrawArea(0, 1920, 0, 1080);
	}
	else if (GameInstance::GetInstance()->PlayerFrom == 2) {
		Girl->SetPosition(glm::vec3(mapWidth - 950.0f, 300.0f, 0.0f));
		GameEngine::GetInstance()->SetDrawArea(mapWidth - 1980.0f, mapWidth, 0, 1080);
	}
	else { Girl->SetPosition(glm::vec3(950.0f, 300.0f, 0.0f)); }


	//	inventory display stuff
	/*
	GameObject* inventoryBar = new GameObject();						// position, set in PlayerFrom if else logic
	inventoryBar->SetTexture("../Resource/Texture/inventoryBar.png");
	inventoryBar->SetSize(100.0f, -100.0f);
	uiList.push_back(inventoryBar);
	*/

	//for(int i=0;i<GameInstance::GetInstance()->inventory.getSize();i++){	//i++ = (i = i+1)
	//		if(GameInstance::GetInstance()->inventory.getSize() != 0){
	//			GameObject* inventoryBar = new GameObject();
	//			inventoryBar->SetTexture("../Resource/Texture/inventoryBar.png");
	//			inventoryBar->SetSize(100.0f, -100.0f);
	//			uiList.push_back(inventoryBar);
	//		}
	// }


	
	TextObject* objUiText = new TextObject();
	SDL_Color textColor = { 0, 0, 0 }; //(0 to 255)
	objUiText->LoadText("Hello??? anybody?", textColor, 100);
	objUiText->SetPosition(glm::vec3(960.0f, 200.0f, 0.0f));
	objUiText->SetSize(500.0f, -100.0f);
	uiList.push_back(objUiText);

	



	uiText = objUiText;
	button1 = testButton;
	button2 = testButton2;
	cursor = objCursor;
	//player = objPlayer;
	player = Girl;

	floatyGlobe = floatyEarth;


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
	//uiText->SetPosition(glm::vec3(960.0f, 200.0f, 0.0f));
	if (SDL_GetTicks() > playerCurrentTime + playerFrameDelay) {
		if (playerWalkSide != 0) {
			if (player->GetX() > 960 && player->GetX() < (mapWidth-960.0f)) {										//set camera limit here
				GameEngine::GetInstance()->SetDrawArea(player->GetX() - 960, 960 + player->GetX(), 0, 1080);
				uiText->SetPosition(glm::vec3(player->GetX(), 200.0f, 0.0f));
			}
			else if(player->GetX()<100) {
				GameInstance::GetInstance()->PlayerFrom = 1;
				GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL2;
			}
			else if (player->GetX() > (mapWidth-100)) {
				GameInstance::GetInstance()->PlayerFrom = 2;
				GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL2;
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
	case 'w':
		if (player->GetY() < 320){player->Translate(glm::vec3(0, 3.0, 0));}
		break;
	case 's': 
		if (player->GetY() > 200) { player->Translate(glm::vec3(0, -3.0, 0)); }
		break;
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
	
	float trueX = x;
	if (player->GetX() > 960 && player->GetX() < (mapWidth - 960.0f)) {
		trueX = (x-960) + player->GetX();
	}
	else if (player->GetX() >= (mapWidth - 960.0f)) {
		trueX = x+((mapWidth - 1920.0f));
	}
	else {
		trueX = x;
	}
	
	
	//printf("print work  ");

	cursor->SetPosition(glm::vec3(trueX, y, 0));

	for (int i = 0; i < interactableList.size(); i++) {
		if (interactableList[i]->GetClick(trueX, y)) {
			interactableList[i]->Interact();
		}
	}
	if (button1->Interacted == true) {
		SDL_Color button1TextColor = { 255, 255, 255 };
		uiText->LoadText("button pressed", button1TextColor, 100);
		uiText->SetSize(700.0f, -100.0f);
		button1->Interacted = false;
	}
	if (button2->Interacted == true) {
		//string st = "You now have " + GameInstance::GetInstance()->testIntInstance + "keys";
		GameInstance::GetInstance()->testIntInstance = GameInstance::GetInstance()->testIntInstance + 1;
		SDL_Color button1TextColor = { 255, 255, 255 };
		uiText->LoadText("pick up key", button1TextColor, 100);
		uiText->SetSize(700.0f, -100.0f);
		button2->Interacted = false;
		//test = test + 1;
		
	}
		
	if (floatyGlobe->Interacted == true) {
		SDL_Color button3TextColor = { 0, 0, 0 };
		uiText->LoadText("Interact with earth thingy", button3TextColor, 100);
		uiText->SetSize(700.0f, -100.0f);
		floatyGlobe->Interacted = false;
	}
	


	if (y > 990) {
		printf("test:%d\n", GameInstance::GetInstance()->testIntInstance);
	}
	//playerWalkTo = x;

}