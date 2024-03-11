#include "Level2.h"
#include "sdl.h"
#include "SpriteObject.h"

#define GIRL_SCALE 2

void Level2::LevelLoad()
{
	SquareMeshVbo * square = new SquareMeshVbo();
	square->LoadData();
	GameEngine::GetInstance()->AddMesh(SquareMeshVbo::MESH_NAME, square);

	//cout << "Load Level" << endl;
}

void Level2::LevelInit()
{
	mapWidth = 7764.5f;
	holdedItemIndex = -1;

	GameObject* background = new GameObject();
	background->SetTexture("../Resource/Texture/testVillage.jpeg");
	background->SetSize(mapWidth, -1080.0f);
	background->SetPosition(glm::vec3(3882.25f, 540.0f, 0.0f));
	backgroundList.push_back(background);


	
	ButtonObject* theChest1 = new ButtonObject();
	if(GameInstance::GetInstance()->gameEvent[0]<2) {
		theChest1->SetTexture("../Resource/Texture/chest1.png");
	}
	else {
		theChest1->SetTexture("../Resource/Texture/chest1Open.png");
	}
	theChest1->SetSize(330.0f, -330.0f);
	theChest1->SetPosition(glm::vec3(6000.25f, 584.0f, 0.0f));
	objectsList.push_back(theChest1);
	interactableList.push_back(theChest1);
	

	ButtonObject* testButton = new ButtonObject();
	testButton->SetTexture("../Resource/Texture/DoNotPress.png");
	testButton->SetSize(100.0f, -200.0f);
	testButton->SetPosition(glm::vec3(500.0f, 800.0f, 0.0f));
	objectsList.push_back(testButton);
	interactableList.push_back(testButton);

	ButtonObject* testButton2 = new ButtonObject();
	testButton2->SetTexture("../Resource/Texture/DoNotPress.png");
	testButton2->SetSize(200.0f, -100.0f);
	testButton2->SetPosition(glm::vec3(1200.0f, 800.0f, 0.0f));
	objectsList.push_back(testButton2);
	interactableList.push_back(testButton2);

	GameObject* objPlayer = new GameObject();
	objPlayer->SetTexture("../Resource/Texture/penguin.png");
	objPlayer->SetPosition(glm::vec3(950.0f, 300.0f, 0.0f));
	objPlayer->SetSize(100.0f, -100.0f);
	objectsList.push_back(objPlayer);

	GameObject* objCursor = new GameObject();
	//objCursor->SetTexture("../Resource/Texture/uglyHand.png");
	objCursor->SetTexture("../Resource/Texture/invisible.png");
	objCursor->SetSize(100.0f, -100.0f);
	uiList.push_back(objCursor);

	SpriteObject* Girl = new SpriteObject("../Resource/Texture/AveryIdle.png", 1, 6);
	Girl->SetSize(64.0f * 2, 128.0f * 2);
	objectsList.push_back(Girl);
	if (GameInstance::GetInstance()->PlayerFrom == PlayerFrom::Right) {
		Girl->SetPosition(glm::vec3(mapWidth - 300.0f, 300.0f, 0.0f));
		GameEngine::GetInstance()->SetDrawArea(7764.5f - 1980.0f, mapWidth, 0, 1080);
	}
	else if(GameInstance::GetInstance()->PlayerFrom == PlayerFrom::Left){
		Girl->SetPosition(glm::vec3(300.0f, 300.0f, 0.0f));
		GameEngine::GetInstance()->SetDrawArea(0, 1920, 0, 1080);
	}
	else{ Girl->SetPosition(glm::vec3(950.0f, 300.0f, 0.0f)); }
	


		//inventory display stuff
	GameObject* inventoryBarUi = new GameObject();
	inventoryBarUi->SetPosition(glm::vec3(960.0f, 100.0f, 0.0f));
	inventoryBarUi->SetTexture("../Resource/Texture/inventoryBar.png");
	inventoryBarUi->SetSize(1980.0f, -200.0f);
	uiList.push_back(inventoryBarUi);

	GameObject* selectDisplayUi = new GameObject();
	selectDisplayUi->SetPosition(glm::vec3(1000.0f, 100.0f, 0.0f));
	selectDisplayUi->SetTexture("../Resource/Texture/selectionOutline.png");
	selectDisplayUi->SetSize(120.0f, -120.0f);
	uiList.push_back(selectDisplayUi);

	inventoryBar = inventoryBarUi;
	////selectUi = selectDisplayUi;

	ItemUi* itemSlot0 = new ItemUi();
	//itemSlot0->SetTexture(GameInstance::GetInstance()->inventory[0].fileName);
	itemSlot0->SetSize(100.0f, -100.0f);
	itemSlot0->SetPosition(glm::vec3(100.0f, 100.0f, 0.0f));
	uiList.push_back(itemSlot0);
	interactableList.push_back(itemSlot0);

	ItemUi* itemSlot1 = new ItemUi();
	//itemSlot1->SetTexture(GameInstance::GetInstance()->inventory[1].fileName); 
	itemSlot1->SetSize(100.0f, -100.0f);
	itemSlot1->SetPosition(glm::vec3(300.0f, 100.0f, 0.0f));
	uiList.push_back(itemSlot1);
	interactableList.push_back(itemSlot1);
	
	ItemUi* itemSlot2 = new ItemUi();
	//itemSlot2->SetTexture(GameInstance::GetInstance()->inventory[1].fileName);
	itemSlot2->SetSize(100.0f, -100.0f);
	itemSlot2->SetPosition(glm::vec3(500.0f, 100.0f, 0.0f));
	uiList.push_back(itemSlot2);
	interactableList.push_back(itemSlot2);

	ItemUi* itemSlot3 = new ItemUi();
	//itemSlot3->SetTexture(GameInstance::GetInstance()->inventory[3].fileName);
	itemSlot3->SetSize(100.0f, -100.0f);
	itemSlot3->SetPosition(glm::vec3(700.0f, 100.0f, 0.0f));
	uiList.push_back(itemSlot3);
	interactableList.push_back(itemSlot3);

	ItemUi* itemSlot4 = new ItemUi();
	//itemSlot4->SetTexture(GameInstance::GetInstance()->inventory[1].fileName);
	itemSlot4->SetSize(100.0f, -100.0f);
	itemSlot4->SetPosition(glm::vec3(900.0f, 100.0f, 0.0f));
	uiList.push_back(itemSlot4);
	interactableList.push_back(itemSlot4);

	ItemUi* itemSlot5 = new ItemUi();
	//itemSlot5->SetTexture(GameInstance::GetInstance()->inventory[1].fileName);
	itemSlot5->SetSize(100.0f, -100.0f);
	itemSlot5->SetPosition(glm::vec3(1100.0f, 100.0f, 0.0f));
	uiList.push_back(itemSlot5);
	interactableList.push_back(itemSlot5);

	ItemUi* itemSlot6 = new ItemUi();
	//itemSlot6->SetTexture(GameInstance::GetInstance()->inventory[1].fileName);
	itemSlot6->SetSize(100.0f, -100.0f);
	itemSlot6->SetPosition(glm::vec3(1300.0f, 100.0f, 0.0f));
	uiList.push_back(itemSlot6);
	interactableList.push_back(itemSlot6);
	
	ItemUi* itemSlot7 = new ItemUi();
	//itemSlot7->SetTexture(GameInstance::GetInstance()->inventory[1].fileName);
	itemSlot7->SetSize(100.0f, -100.0f);
	itemSlot7->SetPosition(glm::vec3(1500.0f, 100.0f, 0.0f));
	uiList.push_back(itemSlot7);
	interactableList.push_back(itemSlot7);

	inventoryL[0] = itemSlot0;
	inventoryL[1] = itemSlot1;
	inventoryL[2] = itemSlot2;
	inventoryL[3] = itemSlot3;
	inventoryL[4] = itemSlot4;
	inventoryL[5] = itemSlot5;
	inventoryL[6] = itemSlot6;
	inventoryL[7] = itemSlot7; 

	for (int i = 0; i < 8; i++) {
		if (i >= GameInstance::GetInstance()->inventory.size()) {
			inventoryL[i]->SetTexture("../Resource/Texture/invisible.png");
		}
		else{
			inventoryL[i]->SetTexture(GameInstance::GetInstance()->inventory[i].fileName);
		}
	}




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
	button1 = testButton;
	button2 = testButton2;
	cursor = objCursor;
	//player = objPlayer;
	player = Girl;

	chest1 = theChest1;


	playerWalkTo = player->GetX();
	playerCurrentTime = 0;




	//--------------------- walk speed editer----------------------------
	playerFrameDelay = 0.1;
	playerStepPerFrame = 10;
	//---------------------------------------------------------------------
	//cout << "Init Level" << endl;

}




void Level2::LevelUpdate()
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
				inventoryBar->SetPosition(glm::vec3(player->GetX(), 100.0f, 0.0f));
				//selectUi->SetPosition(glm::vec3((player->GetX() - 960) + 100.0f + (200 * holdedItemIndex), 100.0f, 0.0f));
				for (int i = 0; i < 8; i++) {
					inventoryL[i]->SetPosition(glm::vec3((player->GetX() - 960) + 100.0f + (200 * i), 100.0f, 0.0f));
				}
			}
			else if (player->GetX() < 100) {
				GameInstance::GetInstance()->PlayerFrom = PlayerFrom::Right;
				GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL1;
			}
			else if (player->GetX() > mapWidth-100) {
				GameInstance::GetInstance()->PlayerFrom = PlayerFrom::Left;
				GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL1;
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

void Level2::LevelDraw()
{
	GameEngine::GetInstance()->Render(backgroundList,true);
	GameEngine::GetInstance()->Render(playerList,false);
	GameEngine::GetInstance()->Render(objectsList,false);
	GameEngine::GetInstance()->Render(uiList, false);

	//cout << "Draw Level" << endl;
}

void Level2::LevelFree()
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

void Level2::LevelUnload()
{
	GameEngine::GetInstance()->ClearMesh();
	//cout << "Unload Level" << endl;
}

void Level2::HandleKey(char key)
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

void Level2::HandleMouse(int type, int x, int y)
{
	


	float trueX = x;
	if (player->GetX() > 960 && player->GetX() < (mapWidth - 960.0f)) {
		trueX = (x - 960) + player->GetX();
	}
	else if (player->GetX() >= (mapWidth - 960.0f)) {
		trueX = x + ((mapWidth - 1920.0f));
	}
	else {
		trueX = x;
	}



	if (talk.talking == false) {	//no talk


		for (int i = 0; i < interactableList.size(); i++) {
			if (interactableList[i]->GetClick(trueX, y)) {
				interactableList[i]->Interact();
			}
		}
																																		/////////////will be gone soon end
		//Logic Here

	}//no talk

	if (talk.talking == true) { //do talk
		talk.count = talk.count + 1;


		if (talk.event == "Example") {				//tutorial
			switch (talk.count) {
			case 1: talk.d("example 1"); box(true); talk.f = 70; break;
			case 2:	talk.d("example 2"); talk.f = 40;  break;
			case 3: talk.event = " ";  talk.nd(" ", " "); talk.talking = false; box(false); talk.count = 0; break;
			}
		}


		setDialoguePosition();
		dialogueCharacter->SetTexture(talk.pictureFileName);			//SetPosition(glm::vec3(0, 0, 0));
		uiText->LoadText(talk.dialogue, blackText, talk.f);
		nameText->LoadText(talk.name, blackText, talk.nf);

	}

	inventoryLogic();


}