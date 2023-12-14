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
	mapWidth = 6326.6f;
	holdedItemIndex = -1;

	GameObject* background = new GameObject();
	background->SetTexture("../Resource/Texture/BackGround.png");
	background->SetSize(mapWidth, -880.0f);//1080 + 200.0f
	background->SetPosition(glm::vec3(mapWidth/2, 540.0f+100.0f, 0.0f));
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
	testButton->SetPosition(glm::vec3(3500.25f, 800.0f, 0.0f));
	objectsList.push_back(testButton);
	interactableList.push_back(testButton);

	ButtonObject* testButton2 = new ButtonObject();
	testButton2->SetTexture("../Resource/Texture/DoNotPress.png");
	testButton2->SetSize(100.0f, -100.0f);
	testButton2->SetPosition(glm::vec3(1200.0f, 800.0f, 0.0f));
	objectsList.push_back(testButton2);
	interactableList.push_back(testButton2);

	ButtonObject* lv1Key1 = new ButtonObject();
	if (GameInstance::GetInstance()->gameEvent[0] < 1) {
		lv1Key1->SetTexture("../Resource/Texture/key1.png");
		lv1Key1->SetSize(60.0f, -60.0f);
		lv1Key1->SetPosition(glm::vec3(1800.0f, 600.0f, 0.0f));
		objectsList.push_back(lv1Key1);
		interactableList.push_back(lv1Key1);
	}

	GameObject* objPlayer = new GameObject();
	objPlayer->SetPosition(glm::vec3(950.0f, 300.0f, 0.0f));
	objPlayer->SetTexture("../Resource/Texture/penguin.png");
	objPlayer->SetSize(100.0f, -100.0f);
	objectsList.push_back(objPlayer);

	
	GameObject* objCursor = new GameObject();
	//objCursor->SetTexture("../Resource/Texture/uglyHand.png");
	objCursor->SetTexture("../Resource/Texture/invisible.png");
	objCursor->SetSize(100.0f, -100.0f);
	uiList.push_back(objCursor);


	//Avery   y max 530   min 360
	SpriteObject* Girl = new SpriteObject("../Resource/Texture/AveryIdle.png", 1, 6);
	Girl->SetSize(540.0f * 0.5f, 695.0f * 0.5f);
	objectsList.push_back(Girl);
	if (GameInstance::GetInstance()->PlayerFrom == 1) {
		Girl->SetPosition(glm::vec3(950.0f, 600.0f, 0.0f));
		GameEngine::GetInstance()->SetDrawArea(0, 1920, 0, 1080);
	}
	else if (GameInstance::GetInstance()->PlayerFrom == 2) {
		Girl->SetPosition(glm::vec3(mapWidth - 950.0f, 600.0f, 0.0f));
		GameEngine::GetInstance()->SetDrawArea(mapWidth - 1980.0f, mapWidth, 0, 1080);
	}
	else { Girl->SetPosition(glm::vec3(950.0f, 400.0f, 0.0f)); }


	






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
	selectUi = selectDisplayUi;

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

	



	uiText = objUiText;
	button1 = testButton;
	button2 = testButton2;
	cursor = objCursor;
	//player = objPlayer;
	player = Girl;

	floatyGlobe = floatyEarth;
	key1 = lv1Key1;


	playerWalkTo = player->GetX();
	playerCurrentTime = 0;




	//--------------------- walk speed editer----------------------------
	playerFrameDelay = 1;
	playerStepPerFrame = 10;
	//---------------------------------------------------------------------
	

	// ---------------------manage animation stuff-------------------------
	playerStandStillDelay = 100;
	//---------------------------------------------------------------------
	//cout << "Init Level" << endl;

}








void Level1::LevelUpdate()
{	
	
	//uiText->SetPosition(glm::vec3(960.0f, 200.0f, 0.0f));
	if (SDL_GetTicks() > playerCurrentTime + playerFrameDelay) {
		if (playerWalkSide != 0) {

			if (pSpriteInt == 0) {
				player->SetTexture("../Resource/Texture/AveryWalk.png");
				pSpriteInt = 1;
			}

			if (player->GetX() > 960 && player->GetX() < (mapWidth-960.0f)) {										//set camera limit here
				GameEngine::GetInstance()->SetDrawArea(player->GetX() - 960, 960 + player->GetX(), 0, 1080);
				uiText->SetPosition(glm::vec3(player->GetX(), 200.0f, 0.0f));
				inventoryBar->SetPosition(glm::vec3(player->GetX(), 100.0f, 0.0f));
				selectUi->SetPosition(glm::vec3((player->GetX() - 960) + 100.0f + (200 * holdedItemIndex), 100.0f, 0.0f));
				for (int i = 0; i < 8; i++) {
					inventoryL[i]->SetPosition(glm::vec3((player->GetX()-960)+100.0f+(200*i), 100.0f, 0.0f));
				}
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
				player->SetSize(-540.0f * 0.5f, 695.0f * 0.5f);
				playerWalkSide = 0;
			}
			else if (playerWalkSide == 1) {
				player->Translate(glm::vec3(-playerStepPerFrame, 0, 0));
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

//SpriteObject* Girl = new SpriteObject("../Resource/Texture/AveryWalk.png", 1, 6);
//Girl->SetSize(540.0f * 0.5f, 695.0f * 0.5f);

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
	case 'w':	//Avery   y max 530   min 360
		if (player->GetY() < 530){player->Translate(glm::vec3(0, 3.0, 0));}
		break;
	case 's': 
		if (player->GetY() > 360) { player->Translate(glm::vec3(0, -3.0, 0)); }
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
	SDL_Color whiteText = { 255, 255, 255 };

	cursor->SetPosition(glm::vec3(trueX, y, 0));

	for (int i = 0; i < interactableList.size(); i++) {
		if (interactableList[i]->GetClick(trueX, y)) {
			interactableList[i]->Interact();
		}
	}
	if (button1->Interacted == true) {
		uiText->LoadText("curse u with this", whiteText, 100);
		uiText->SetSize(700.0f, -100.0f);
		button1->Interacted = false;
		if (GameInstance::GetInstance()->inventory.size() < 8) {
			Item tomatoItem;
			tomatoItem.fileName = "../Resource/Texture/tomato.png";
			tomatoItem.name = "tomato from god";
			GameInstance::GetInstance()->inventory.push_back(tomatoItem);
			for (int i = 0; i < 8; i++) { if (i >= GameInstance::GetInstance()->inventory.size()) { inventoryL[i]->SetTexture("../Resource/Texture/invisible.png"); } else { inventoryL[i]->SetTexture(GameInstance::GetInstance()->inventory[i].fileName); } }
		}
	}
	if (button2->Interacted == true) {
		//string st = "You now have " + GameInstance::GetInstance()->testIntInstance + "keys";
		GameInstance::GetInstance()->testIntInstance = GameInstance::GetInstance()->testIntInstance + 1;
		uiText->LoadText("a fire match drop from the ceiling", whiteText, 100);
		uiText->SetSize(700.0f, -100.0f);
		if (GameInstance::GetInstance()->inventory.size() < 8) {
			Item fireMatchItem;
			fireMatchItem.fileName = "../Resource/Texture/fireMatch.png";
			fireMatchItem.name = "fire match";
			GameInstance::GetInstance()->inventory.push_back(fireMatchItem);
			for (int i = 0; i < 8; i++) { if (i >= GameInstance::GetInstance()->inventory.size()) { inventoryL[i]->SetTexture("../Resource/Texture/invisible.png"); } else { inventoryL[i]->SetTexture(GameInstance::GetInstance()->inventory[i].fileName); } }
		}
		button2->Interacted = false;
		//test = test + 1;
		
	}
		
	if (floatyGlobe->Interacted == true) {
		uiText->LoadText("Getting potato", whiteText, 100);
		uiText->SetSize(700.0f, -100.0f);

		if (GameInstance::GetInstance()->inventory.size() < 8) {
			Item potatoItem;
			potatoItem.fileName = "../Resource/Texture/potato.png";
			potatoItem.name = "potato from god";
			GameInstance::GetInstance()->inventory.push_back(potatoItem);
			for (int i = 0; i < 8; i++) { if (i >= GameInstance::GetInstance()->inventory.size()) { inventoryL[i]->SetTexture("../Resource/Texture/invisible.png"); } else { inventoryL[i]->SetTexture(GameInstance::GetInstance()->inventory[i].fileName); } }
		}
		floatyGlobe->Interacted = false;
	} 
	if (key1->Interacted == true) {
		uiText->LoadText("Grabing Key", whiteText, 100);
		uiText->SetSize(700.0f, -100.0f);

		if (GameInstance::GetInstance()->inventory.size() < 8) {
			Item key1Item;
			key1Item.fileName = "../Resource/Texture/key1.png";
			key1Item.name = "key1";
			GameInstance::GetInstance()->inventory.push_back(key1Item);
			for (int i = 0; i < 8; i++) { if (i >= GameInstance::GetInstance()->inventory.size()) { inventoryL[i]->SetTexture("../Resource/Texture/invisible.png"); } else { inventoryL[i]->SetTexture(GameInstance::GetInstance()->inventory[i].fileName); } }
		}
		GameInstance::GetInstance()->gameEvent[0] = 1;
		key1->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
		key1->Interacted = false;
	}
	
	//inventory logic
	for (int i = 0; i < GameInstance::GetInstance()->inventory.size(); i++) {
		if(inventoryL[i]->Interacted == true){
			if(GameInstance::GetInstance()->inventory[i].name == "potato from god") {
				GameInstance::GetInstance()->inventory.erase(GameInstance::GetInstance()->inventory.begin() + i);
				for (int j = 0; j < 8; j++) { if (j >= GameInstance::GetInstance()->inventory.size()) { inventoryL[j]->SetTexture("../Resource/Texture/invisible.png"); } else { inventoryL[j]->SetTexture(GameInstance::GetInstance()->inventory[j].fileName); } }
			
				GameInstance::GetInstance()->potatoEaten = GameInstance::GetInstance()->potatoEaten + 1;
				string potatoEatenText[2] = { "you have eated ", " potatos" };
				uiText->LoadText(potatoEatenText[0] + to_string(GameInstance::GetInstance()->potatoEaten) + potatoEatenText[1], whiteText, 100);
				uiText->SetSize(700.0f, -100.0f);
				inventoryL[i]->Interacted = false;
			}
			else if (GameInstance::GetInstance()->inventory[i].name == "tomato from god") {
				GameInstance::GetInstance()->inventory.erase(GameInstance::GetInstance()->inventory.begin() + i);
				for (int j = 0; j < 8; j++) { if (j >= GameInstance::GetInstance()->inventory.size()) { inventoryL[j]->SetTexture("../Resource/Texture/invisible.png"); } else { inventoryL[j]->SetTexture(GameInstance::GetInstance()->inventory[j].fileName); } }

				uiText->LoadText("Tomato is too sour", whiteText, 100);
				uiText->SetSize(700.0f, -100.0f);

				inventoryL[i]->Interacted = false;
			}
			else if (GameInstance::GetInstance()->inventory[i].name == "fire match") {
				holdedItemIndex = i;
				selectUi->SetPosition(glm::vec3((player->GetX() - 960) + 100.0f + (200 * holdedItemIndex), 100.0f, 0.0f));
				uiText->LoadText("a fire match", whiteText, 100);
				uiText->SetSize(700.0f, -100.0f);

				inventoryL[i]->Interacted = false;
			}
			else if (GameInstance::GetInstance()->inventory[i].name == "key1") {
				holdedItemIndex = i;
				selectUi->SetPosition(glm::vec3((player->GetX() - 960) + 100.0f + (200 * holdedItemIndex), 100.0f, 0.0f));
				uiText->LoadText("a key", whiteText, 100);
				uiText->SetSize(700.0f, -100.0f);

				inventoryL[i]->Interacted = false;
			}
			else if (GameInstance::GetInstance()->inventory[i].name == "endOfDemoNote") {
				holdedItemIndex = i;
				selectUi->SetPosition(glm::vec3((player->GetX() - 960) + 100.0f + (200 * holdedItemIndex), 100.0f, 0.0f));
				uiText->LoadText("END OF ENGINE DEMO", whiteText, 100);
				uiText->SetSize(700.0f, -100.0f);

				inventoryL[i]->Interacted = false;
			}
		}
	}

	
	//playerWalkTo = x;

}