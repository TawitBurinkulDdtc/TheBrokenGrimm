#include "LevelTemplate.h"
#include "sdl.h"
#include "SpriteObject.h"

#define GIRL_SCALE 2

void LevelTemplate::LevelLoad()
{
	SquareMeshVbo * square = new SquareMeshVbo();
	square->LoadData();
	GameEngine::GetInstance()->AddMesh(SquareMeshVbo::MESH_NAME, square);

	//cout << "Load Level" << endl;
}

void LevelTemplate::LevelInit()
{
	mapWidth = 3000.0f;
	holdedItemIndex = -1;

	GameObject* background = new GameObject();
	background->SetTexture("../Resource/Texture/testBackGround.png");
	background->SetSize(mapWidth, -880.0f);//1080 + 200.0f
	background->SetPosition(glm::vec3(mapWidth/2, 540.0f+100.0f, 0.0f));
	backgroundList.push_back(background);












	ButtonObject* keyTemplate = new ButtonObject();
	keyTemplate->SetTexture("../Resource/Texture/testItem.png");
	keyTemplate->SetSize(200.0f, -200.0f);
	keyTemplate->SetPosition(glm::vec3(500.0f, 800.0f, 0.0f));
	objectsList.push_back(keyTemplate);
	interactableList.push_back(keyTemplate);

	keyTem = keyTemplate;


	ButtonObject* chestTemplate = new ButtonObject();
	chestTemplate->SetTexture("../Resource/Texture/chestTem.png");
	chestTemplate->SetSize(200.0f, -200.0f);
	chestTemplate->SetPosition(glm::vec3(1000.00f, 800.0f, 0.0f));
	objectsList.push_back(chestTemplate);
	interactableList.push_back(chestTemplate);

	chestTem = chestTemplate;

	
	ButtonObject* talkTemplate = new ButtonObject();
	talkTemplate->SetTexture("../Resource/Texture/testItem.png");
	talkTemplate->SetSize(200.0f, -200.0f);
	talkTemplate->SetPosition(glm::vec3(1500.25f, 800.0f, 0.0f));
	objectsList.push_back(talkTemplate);
	interactableList.push_back(talkTemplate);

	talkTem = talkTemplate;












	GameObject* objCursor = new GameObject();
	objCursor->SetTexture("../Resource/Texture/uglyHand.png");
	//objCursor->SetTexture("../Resource/Texture/invisible.png");
	objCursor->SetSize(100.0f, -100.0f);
	uiList.push_back(objCursor);


	//Avery   y max 530   min 360
	SpriteObject* Girl = new SpriteObject("../Resource/Texture/AveryIdle.png", 1, 6);	
	Girl->SetSize(540.0f * 0.5f, 695.0f * 0.5f);
	objectsList.push_back(Girl);
	if (GameInstance::GetInstance()->PlayerFrom == 1) {
		Girl->SetPosition(glm::vec3(950.0f, 400.0f, 0.0f));
		GameEngine::GetInstance()->SetDrawArea(0, 1920, 0, 1080);
	}
	else if (GameInstance::GetInstance()->PlayerFrom == 2) {
		Girl->SetPosition(glm::vec3(mapWidth - 950.0f, 400.0f, 0.0f));
		GameEngine::GetInstance()->SetDrawArea(mapWidth - 1980.0f, mapWidth, 0, 1080);
	}
	else { Girl->SetPosition(glm::vec3(950.0f, 400.0f, 0.0f)); GameEngine::GetInstance()->SetDrawArea(0, 1920, 0, 1080);}


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




	GameObject* talkingChar = new GameObject();			//(char for character)							///////////////
	talkingChar->SetTexture("../Resource/Texture/invisible.png");
	talkingChar->SetSize(1980, -1080.0f);//1080 + 200.0f
	talkingChar->SetPosition(glm::vec3(0, 0, 0));
	uiList.push_back(talkingChar);


	dialogueCharacter = talkingChar;
	uiText = objUiText;
	cursor = objCursor;
	player = Girl;


	playerWalkTo = player->GetX();
	playerCurrentTime = 0;




	//--------------------- walk speed editer----------------------------
	playerFrameDelay = 1;
	playerStepPerFrame = 60; //10
	//---------------------------------------------------------------------
	

	// ---------------------manage animation stuff-------------------------
	playerStandStillDelay = 100;
	//---------------------------------------------------------------------
	//cout << "Init Level" << endl;

}








void LevelTemplate::LevelUpdate()
{	
	
	//uiText->SetPosition(glm::vec3(960.0f, 200.0f, 0.0f));
	if (SDL_GetTicks() > playerCurrentTime + playerFrameDelay) {
		if (playerWalkSide != 0) {

			if (pSpriteInt == 0) {
				player->SetTexture("../Resource/Texture/AveryWalk.png");
				pSpriteInt = 1;
			}

			if (playerWalkSide == 2) {
				player->Translate(glm::vec3(playerStepPerFrame, 0, 0));
				if (player->GetX() > 960 && player->GetX() < (mapWidth - 960.0f)) {										//set camera limit here
					GameEngine::GetInstance()->SetDrawArea(player->GetX() - 960, 960 + player->GetX(), 0, 1080);
					uiText->SetPosition(glm::vec3(player->GetX(), 200.0f, 0.0f));
					inventoryBar->SetPosition(glm::vec3(player->GetX(), 100.0f, 0.0f));
					
					for (int i = 0; i < 8; i++) {
						inventoryL[i]->SetPosition(glm::vec3((player->GetX() - 960) + 100.0f + (200 * i), 100.0f, 0.0f));
					}
				}
				else if (player->GetX() < 100) {
					GameInstance::GetInstance()->PlayerFrom = PlayerFrom::Left;
					GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL2;
				}
				else if (player->GetX() > (mapWidth - 100)) {
					GameInstance::GetInstance()->PlayerFrom = PlayerFrom::Right;
					GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL2;
				}
				player->SetSize(-540.0f * 0.5f, 695.0f * 0.5f);
				playerWalkSide = 0;
			}
			else if (playerWalkSide == 1) {
				player->Translate(glm::vec3(-playerStepPerFrame, 0, 0));
				if (player->GetX() > 960 && player->GetX() < (mapWidth - 960.0f)) {										//set camera limit here
					GameEngine::GetInstance()->SetDrawArea(player->GetX() - 960, 960 + player->GetX(), 0, 1080);
					uiText->SetPosition(glm::vec3(player->GetX(), 200.0f, 0.0f));
					inventoryBar->SetPosition(glm::vec3(player->GetX(), 100.0f, 0.0f));
					//selectUi->SetPosition(glm::vec3((player->GetX() - 960) + 100.0f + (200 * holdedItemIndex), 100.0f, 0.0f));
					for (int i = 0; i < 8; i++) {
						inventoryL[i]->SetPosition(glm::vec3((player->GetX() - 960) + 100.0f + (200 * i), 100.0f, 0.0f));
					}
				}
				else if (player->GetX() < 100) {
					GameInstance::GetInstance()->PlayerFrom = PlayerFrom::Left;
					GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL2;
				}
				else if (player->GetX() > (mapWidth - 100)) {
					GameInstance::GetInstance()->PlayerFrom = PlayerFrom::Right;
					GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL2;
				}
				player->SetSize(540.0f * 0.5f, 695.0f * 0.5f);
				playerWalkSide = 0;
			}
			playerStartStandStill = SDL_GetTicks();
		}
		else if (pSpriteInt == 1 && SDL_GetTicks() > playerStartStandStill+playerStandStillDelay) {
			player->SetTexture("../Resource/Texture/AveryIdle.png");
			pSpriteInt = 0;
		}
		playerCurrentTime = SDL_GetTicks();
	}


	player->UpdateFrame();

}



void LevelTemplate::LevelDraw()
{
	GameEngine::GetInstance()->Render(backgroundList,true);
	GameEngine::GetInstance()->Render(playerList,false);
	GameEngine::GetInstance()->Render(objectsList,false);
	GameEngine::GetInstance()->Render(uiList, false);

}

void LevelTemplate::LevelFree()
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
}

void LevelTemplate::LevelUnload()
{
	GameEngine::GetInstance()->ClearMesh();
}

void LevelTemplate::HandleKey(char key)
{

	switch (key)
	{
	case 'w':	
		if (player->GetY() < 500 && talk.talking == false){player->Translate(glm::vec3(0, 3.0, 0));}
		break;
	case 's': 
		if (player->GetY() > 360 && talk.talking == false) { player->Translate(glm::vec3(0, -3.0, 0)); }
		break;
	case 'a': if (talk.talking == false) { playerWalkSide = 1; }
		break;
	case 'd': if (talk.talking == false) { playerWalkSide = 2; }
		break;
	case 'q': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_QUIT; ; break;
	case 'r': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_RESTART; ; break;
	case 'e': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL1; ; break; //LVC. Level change testing add by Zen d13m9y2023
	}
}

void LevelTemplate::HandleMouse(int type, int x, int y)
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
	
	//cout << "pos: x " << trueX << " y " << y << endl;    //set to 1920 x 1200 to see display
	
	SDL_Color whiteText = { 255, 255, 255 };

	cursor->SetPosition(glm::vec3(trueX, y, 0));

	if (talk.talking == false) {	//no talk

		for (int i = 0; i < interactableList.size(); i++) {
			if (interactableList[i]->GetClick(trueX, y)) {
				interactableList[i]->Interact();
			}
		}


		if (keyTem->Interacted == true) {
			uiText->LoadText("Grabing Key template", whiteText, 100);
			uiText->SetSize(700.0f, -100.0f);

			if (GameInstance::GetInstance()->inventory.size() < 8) {
				Item keyTemItem;
				keyTemItem.fileName = "../Resource/Texture/testItem.png";
				keyTemItem.name = "keyTem";
				keyTemItem.showText = "Key template";
				GameInstance::GetInstance()->inventory.push_back(keyTemItem);
				for (int i = 0; i < 8; i++) { if (i >= GameInstance::GetInstance()->inventory.size()) { inventoryL[i]->SetTexture("../Resource/Texture/invisible.png"); } else { inventoryL[i]->SetTexture(GameInstance::GetInstance()->inventory[i].fileName); } }
			}
			GameInstance::GetInstance()->gameEvent[499] = 1;
			keyTem->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
			keyTem->Interacted = false;
		}


		/*
		if (chestTem->Interacted == true) {
			SDL_Color button3TextColor = { 255, 255, 255 };
			if (holdedItemIndex >= 0 && holdedItemIndex < GameInstance::GetInstance()->inventory.size() && GameInstance::GetInstance()->gameEvent[0] == 1) {
				if (GameInstance::GetInstance()->inventory[holdedItemIndex].name == "key1") {
					if (GameInstance::GetInstance()->inventory.size() < 8) {
						uiText->LoadText("You get a paper note", button3TextColor, 100);
						uiText->SetSize(700.0f, -100.0f);
						GameInstance::GetInstance()->inventory.erase(GameInstance::GetInstance()->inventory.begin() + holdedItemIndex);
						Item EngineDemoNoteThingy;
						EngineDemoNoteThingy.fileName = "../Resource/Texture/endOfEngineDemo.png";
						EngineDemoNoteThingy.name = "endOfDemoNote";
						GameInstance::GetInstance()->inventory.push_back(EngineDemoNoteThingy);
						for (int i = 0; i < 8; i++) { if (i >= GameInstance::GetInstance()->inventory.size()) { inventoryL[i]->SetTexture("../Resource/Texture/invisible.png"); } else { inventoryL[i]->SetTexture(GameInstance::GetInstance()->inventory[i].fileName); } }
						GameInstance::GetInstance()->gameEvent[0] = 2;
						chestTem->SetTexture("../Resource/Texture/chestTemOpen.png");
					}
					else {
						uiText->LoadText("You got no inventory space", button3TextColor, 100);
						uiText->SetSize(700.0f, -100.0f);
					}
				}
				else if (GameInstance::GetInstance()->inventory[holdedItemIndex].name == "fire match") {
					uiText->LoadText("when in doubt   commit arson    lol just kidding", button3TextColor, 100);
					uiText->SetSize(1400.0f, -100.0f);
				}
				else {
					uiText->LoadText("no key", button3TextColor, 100);
					uiText->SetSize(700.0f, -100.0f);
				}
			}
			else if (GameInstance::GetInstance()->gameEvent[0] == 1) { uiText->LoadText("no key", button3TextColor, 100); uiText->SetSize(700.0f, -100.0f); }
			chestTem->Interacted = false;
		}*/
	
	}//no talk





	if (talk.talking == true) { //do talk
		talk.count = talk.count + 1;



		if (talk.event == "talk to globe thingy") {		//SetPosition(glm::vec3(3500.25f, 800.0f, 0.0f));
			switch (talk.count) {
				case 1: talk.dp("give my potato back", "../Resource/Texture/talkingGlobeTest1.png"); uiText->SetSize(700.0f, -100.0f); dialogueCharacter->SetPosition(glm::vec3(player->GetX(), 540.0f, 0.0f)); break;
				case 2:	talk.dp("No", "../Resource/Texture/stickAvery.png"); uiText->SetSize(400.0f, -100.0f); break;
				case 3:	talk.dp("you monster", "../Resource/Texture/talkingGlobeTest2.png"); uiText->SetSize(700.0f, -100.0f); break;
				case 4: talk.event = ""; talk.dp(" ", "../Resource/Texture/invisible.png"); talk.talking = false; talk.count = 0; break;
			}

		}


		
		dialogueCharacter->SetTexture(talk.pictureFileName);			//SetPosition(glm::vec3(0, 0, 0));
		uiText->LoadText(talk.dialogue, whiteText, 100);
		

	}//do talk





	//inventory logic
	for (int i = 0; i < GameInstance::GetInstance()->inventory.size(); i++) {
		if(inventoryL[i]->Interacted == true){
				holdedItemIndex = i;
				//selectUi->SetPosition(glm::vec3((player->GetX() - 960) + 100.0f + (200 * holdedItemIndex), 100.0f, 0.0f));
				uiText->LoadText(GameInstance::GetInstance()->inventory[i].showText, GameInstance::GetInstance()->inventory[i].textColor, GameInstance::GetInstance()->inventory[i].textFontSize);
				uiText->SetSize(GameInstance::GetInstance()->inventory[i].textSizeX, -(GameInstance::GetInstance()->inventory[i].textSizeY));
				inventoryL[i]->Interacted = false;
			
		}
	}

	
	//playerWalkTo = x;

}



