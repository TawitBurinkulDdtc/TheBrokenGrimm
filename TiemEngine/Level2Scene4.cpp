#include "Level2Scene4.h"
#include "SpriteObject.h"

void Level2Scene4::LevelLoad()
{
	SquareMeshVbo* square = new SquareMeshVbo();
	square->LoadData();
	GameEngine::GetInstance()->AddMesh(SquareMeshVbo::MESH_NAME, square);

	//cout << "Load Level" << endl;
}

void Level2Scene4::LevelInit()
{


	mapWidth = 5975.0f;	//Require in every level          RIQL					need custom
	holdedItemIndex = -1;	//Require in every level          RIQL

	//Require in every level          RIQL		start
	GameObject* background = new GameObject();
	background->SetTexture("../Resource/Texture/Inside_H_And_G_House_Night.jpg");	//need custom
	background->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	background->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	backgroundList.push_back(background);
	//Require in every level          RIQL			end




	Gretel = new ButtonObject();
	Gretel->SetTexture("../Resource/Texture/Gretel.png");
	Gretel->SetSize(167, -225.0f);
	Gretel->SetPosition(glm::vec3(1500.0f, 500.0f, 0.0f));
	objectsList.push_back(Gretel);
	interactableList.push_back(Gretel);


	Hansel = new ButtonObject();
	Hansel->SetTexture("../Resource/Texture/Hansel.png");
	Hansel->SetSize(167, -225.0f);
	Hansel->SetPosition(glm::vec3(100.0f, 500.0f, 0.0f));
	objectsList.push_back(Hansel);
	interactableList.push_back(Hansel);


	Chair = new ButtonObject();
	Chair->SetTexture("../Resource/Texture/test.png");
	Chair->SetSize(167, -225.0f);
	Chair->SetPosition(glm::vec3(2000.0f, 500.0f, 0.0f));
	objectsList.push_back(Chair);
	interactableList.push_back(Chair);

	HnGKey = new ButtonObject();
	HnGKey->SetTexture("../Resource/Texture/test.png");
	HnGKey->SetSize(167, -225.0f);
	HnGKey->SetPosition(glm::vec3(2300.0f, 500.0f, 0.0f));
	objectsList.push_back(HnGKey);
	interactableList.push_back(HnGKey);

	


	ChairPlacerArea = new ButtonObject();
	ChairPlacerArea->SetTexture("../Resource/Texture/test.png");
	ChairPlacerArea->SetSize(400, -400.0f);
	ChairPlacerArea->SetPosition(glm::vec3(2300.0f, 500.0f, 0.0f));
	objectsList.push_back(ChairPlacerArea);
	interactableList.push_back(ChairPlacerArea);

	
	frontDoor = new ButtonObject();
	frontDoor->SetTexture("../Resource/Texture/test.png");
	frontDoor->SetSize(400, -500.0f);
	frontDoor->SetPosition(glm::vec3(mapWidth, 500.0f, 0.0f));
	objectsList.push_back(frontDoor);
	interactableList.push_back(frontDoor);








	// Require in every level          RIQL start		1
	/*
	createPlayer();
	if (GameInstance::GetInstance()->PlayerFrom == PlayerFrom::Left) {		//Require customization start
		player->SetPosition(glm::vec3(300.0f, Avery_y_Position, 0.0f));
		GameEngine::GetInstance()->SetDrawArea(0, 1920, 0, 1080);
	}
	else if (GameInstance::GetInstance()->PlayerFrom == PlayerFrom::Right) {
		player->SetPosition(glm::vec3(mapWidth - 300.0f, Avery_y_Position, 0.0f));
		GameEngine::GetInstance()->SetDrawArea(mapWidth - 1980.0f, mapWidth, 0, 1080);
	}
	else { player->SetPosition(glm::vec3(950.0f, Avery_y_Position, 0.0f)); }	//Require customization end
	*/
	createPlayer(1);
	player->SetPosition(glm::vec3(950.0f, Avery_y_Position, 0.0f));

	GameEngine::GetInstance()->SetDrawArea(0, 1920, 0, 1080);
	// RIQL end			1



	// Require in every level          RIQL start		2
	//create inventory here
	createInventory();
	dialogueCharacter = new GameObject();			//(char for character)							///////////////
	dialogueCharacter->SetTexture("../Resource/Texture/invisible.png");
	dialogueCharacter->SetSize(1980, -1080.0f);//1080 + 200.0f
	dialogueCharacter->SetPosition(glm::vec3(0, 0, 0));
	uiList.push_back(dialogueCharacter);
	talk.p("../Resource/Texture/invisible.png");


	dialogueBox = new GameObject();
	dialogueBox->SetPosition(glm::vec3(960.0f, 540.0f + 600, 0.0f));
	dialogueBox->SetTexture("../Resource/Texture/invisible.png");
	dialogueBox->SetSize(1920.0f * 0.75f, -1080.0f * 0.75f);
	uiList.push_back(dialogueBox);

	uiText = new TextObject();
	uiText->LoadText(" ", dialogueTextColor, 100);
	uiText->SetPosition(glm::vec3(960, 150.0f + 700, 0.0f));
	uiText->SetSize(500.0f, -100.0f);
	uiList.push_back(uiText);

	nameText = new TextObject();
	nameText->LoadText(" ", dialogueTextColor, 100);
	nameText->SetPosition(glm::vec3(960 - 470, 320.0f + 650, 0.0f));
	nameText->SetSize(500.0f, -100.0f);
	uiList.push_back(nameText);


	playerWalkTo = player->GetX();
	playerCurrentTime = 0;




	//--------------------- walk speed editer----------------------------
	playerFrameDelay = 1.0f;
	playerStepPerFrame = 50; //10 real   // 60 debug (60 will have some interact area bug abit)
	//---------------------------------------------------------------------


	// ---------------------manage animation stuff-------------------------
	playerStandStillDelay = 100;
	//---------------------------------------------------------------------
	//cout << "Init Level" << endl;
	// RIQL end			2
	readExcel.open("../Resource/Excel/Level2.csv");
	excelRec.clear();

	inventoryOpen();
}







void Level2Scene4::LevelUpdate()
{
	if (playerWalkSide != 0) {
		if (player->GetX() < 250) {
			player->SetPosition(glm::vec3(250, Avery_y_Position, 0.0f));
		}
		else if (player->GetX() > mapWidth - 250) {//frontDoor
			if (GameInstance::GetInstance()->LV2frontDoorLock == true) {
				player->SetPosition(glm::vec3(mapWidth - 250, Avery_y_Position, 0.0f));
				setDialoguePosition();
				uiText->LoadText("Door lock", dialogueTextColor, 50);
			}
			else {
				GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL2;
			}
		}
		if (uiText->currentText == "Door lock" && player->GetX() < mapWidth - 350) {
			uiText->LoadText(" ", dialogueTextColor, 50);
		}
	}
	playerMovement(1); //Require in every level          RIQL1
	player->UpdateFrame();
}

//SpriteObject* Girl = new SpriteObject("../Resource/Texture/AveryWalk.png", 1, 6);
//Girl->SetSize(540.0f * 0.5f, 695.0f * 0.5f);

void Level2Scene4::LevelDraw()
{
	GameEngine::GetInstance()->Render(backgroundList, true);
	GameEngine::GetInstance()->Render(playerList, false);
	GameEngine::GetInstance()->Render(objectsList, false);
	GameEngine::GetInstance()->Render(uiList, false);

	//cout << "Draw Level" << endl;
}

void Level2Scene4::LevelFree()
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

void Level2Scene4::LevelUnload()
{
	GameEngine::GetInstance()->ClearMesh();
	//cout << "Unload Level" << endl;
}

void Level2Scene4::HandleKey(char key)
{

	switch (key)
	{
	case '=':
		inventoryOpen();
		break;
	case 'a': if (talk.talking == false) { playerWalkSide = 1; }
			break;
	case 'd': if (talk.talking == false) { playerWalkSide = 2; } 
			break;
	case 'q': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_QUIT; ; break;
	//case 'r': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_RESTART; ; break;
	}
}

void Level2Scene4::HandleMouse(int type, int x, int y)
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


	//cout << "pos: x " << trueX << " y " << y << endl;    //set to 1920 x 1200 to see display
	//cout <<"p:"<< player->GetX() << endl;
	//cout << "mw-960:" << (mapWidth - 960.0f) << endl;

	//printf("print work  ");



	if (talk.talking == false) {	//no talk


		for (int i = 0; i < interactableList.size(); i++) {
			if (interactableList[i]->GetClick(trueX, y)) {
				interactableList[i]->Interact();
			}
		}
		
		if (Hansel->Interacted == true) {
			talk.talking = true;
			talk.event = "sceneHansel";
			Hansel->Interacted = false;
		}

		if (Gretel->Interacted == true) {
			talk.talking = true;
			talk.event = "sceneGretel";
			Gretel->Interacted = false;
		}

		if (Chair->Interacted == true) {
			//talk.talking = true;
			getItem("chair", "I could reach something high with this", "../Resource/Texture/HanselAndGretelBook.png");
			talk.event = "grabChair";
			Chair->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
			Chair->Interacted = false;
		}

		if (HnGKey->Interacted == true) {
			if (GameInstance::GetInstance()->LV2chairAtCabinet == false) {
				//talk.talking = true;
				//talk.event = "tooHigh";
			}

			else if (GameInstance::GetInstance()->LV2chairAtCabinet == true) {
				getItem("HnGkey", "A key for front door", "../Resource/Texture/Items/Key.png");
				HnGKey->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
			}
			talk.event = "sceneGretel";
			HnGKey->Interacted = false;
		} //ChairPlacerArea
		if (ChairPlacerArea->Interacted == true) {
			//talk.talking = true;
			//talk.event = "placed down chair";
			if (holdedItemIndex >= 0 && holdedItemIndex < GameInstance::GetInstance()->inventory.size()) {
				if (GameInstance::GetInstance()->inventory[holdedItemIndex].name == "chair") {
					GameInstance::GetInstance()->LV2chairAtCabinet = true;
					loseHoldedItem();
					refreshInventoryPic();
					//Move chair texture to this possition
				}
			}
			ChairPlacerArea->Interacted = false;
		}

		if (frontDoor->Interacted == true) {
			if (holdedItemIndex >= 0 && holdedItemIndex < GameInstance::GetInstance()->inventory.size()) {
				if (GameInstance::GetInstance()->inventory[holdedItemIndex].name == "HnGkey") {
					GameInstance::GetInstance()->LV2frontDoorLock = false;
					loseHoldedItem();
					refreshInventoryPic();
				}
			}
		}

	}

	if (talk.talking == true) { //do talk
		talk.count = talk.count + 1;

		if (talk.count == 1) { excelRecRecording(talk.event); box(true); }
		if (finishRead == true && excelRec[talk.count - 1].name != "end") {
			cout << "Error?: " << talk.count << endl;
			if (excelRec[talk.count - 1].name != "\0") {
				talk.n(excelRec[talk.count - 1].name);
			}
			if (excelRec[talk.count - 1].dialogue != "\0") {
				talk.d(excelRec[talk.count - 1].dialogue);
			}
			if (excelRec[talk.count - 1].pictureFileName != "\0") {
				talk.p(excelRec[talk.count - 1].pictureFileName);
			}
			if (excelRec[talk.count - 1].sNFont != "\0") {
				talk.nf = excelRec[talk.count - 1].nf;
			}
			if (excelRec[talk.count - 1].sFont != "\0") {
				talk.f = excelRec[talk.count - 1].f;
			}
		}
		if (excelRec.empty() == false) {
			if (excelRec[talk.count - 1].name == "end") {
				talk.talking = false; talk.count = 0; box(false); finishRead = false; excelRecClear(); talk.ndp(" ", " ", "../Resource/Texture/invisible.png");
			}
		}




		if (talk.event == "not read yet") {
			switch (talk.count) {
			case 1: talk.nd("Avery", "I want to check this place first before reading"); talk.f = 60;  box(true);  break;
			case 2: talk.event = " "; talk.nd(" ", " "); talk.talking = false; talk.count = 0; box(false); break;
			}
		}

		setDialoguePosition();
		dialogueCharacter->SetTexture(talk.pictureFileName);			//SetPosition(glm::vec3(0, 0, 0));
		uiText->LoadText(talk.dialogue, dialogueTextColor, talk.f);
		nameText->LoadText(talk.name, dialogueTextColor, talk.nf);

	}//do talk

	//talk.dp("give my potato back", "../Resource/Texture/talkingGlobeTest1.png"); uiText->SetSize(700.0f, -100.0f); dialogueCharacter->SetPosition(glm::vec3(player->GetX(), 540.0f, 0.0f));
	//dialogueCharacter->SetTexture(talk.pictureFileName);			//SetPosition(glm::vec3(0, 0, 0));
	//uiText->LoadText(talk.dialogue, whiteText, 100);


	//inventory logic
	inventoryLogic();

	//playerWalkTo = x;

}




