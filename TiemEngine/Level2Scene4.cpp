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
	background->SetTexture("../Resource/Texture/Inside_house_HG_night/Bg_Inside_HG.png");	//need custom
	background->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	background->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	backgroundList.push_back(background);
	//Require in every level          RIQL			end




	chairPic = new GameObject();
	chairPic->SetTexture("../Resource/Texture/Inside_house_HG_night/Chair1_Inside_HG.png");	//need custom
	chairPic->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	chairPic->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	objectsList.push_back(chairPic);

	chair2Pic = new GameObject();
	chair2Pic->SetTexture("../Resource/Texture/Inside_house_HG_night/Chair2_Inside_HG.png");	//need custom
	chair2Pic->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	chair2Pic->SetPosition(glm::vec3(mapWidth / 2, 5000.0f, 0.0f));
	objectsList.push_back(chair2Pic);


	cabinetPic = new GameObject();
	cabinetPic->SetTexture("../Resource/Texture/Inside_house_HG_night/Cabinet_close_Inside_HG.png");	//need custom
	cabinetPic->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	cabinetPic->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	objectsList.push_back(cabinetPic);


	frontDoorPic= new GameObject();
	frontDoorPic->SetTexture("../Resource/Texture/Inside_house_HG_night/Front_door_Inside_HG.png");	//need custom
	frontDoorPic->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	frontDoorPic->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	objectsList.push_back(frontDoorPic);

	GameObject* bedRoomDoor = new GameObject();
	bedRoomDoor->SetTexture("../Resource/Texture/Inside_house_HG_night/Bedroom_door_Inside_HG.png");	//need custom
	bedRoomDoor->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	bedRoomDoor->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	objectsList.push_back(bedRoomDoor);

	Gretel = new ButtonObject();
	Gretel->SetTexture("../Resource/Texture/test.png");
	Gretel->SetSize(167, -225.0f);
	Gretel->SetPosition(glm::vec3(1500.0f, 500.0f, 0.0f));
	objectsList.push_back(Gretel);
	interactableList.push_back(Gretel);


	GretelPic = new SpriteObject("../Resource/Texture/Characters/Gretel_Idle.png", 1, 6); 
	GretelPic->SetSize(-167, 225.0f); //in animation y gotta be +
	GretelPic->SetPosition(glm::vec3(1500.0f, 500.0f, 0.0f));
	objectsList.push_back(GretelPic);


	createPlayer(3);
	player->SetPosition(glm::vec3(950.0f, Avery_y_Position, 0.0f));

	GameEngine::GetInstance()->SetDrawArea(0, 1920, 0, 1080);
	//player->renderMode = 2;

	GameObject* frontGround = new GameObject();
	frontGround->SetTexture("../Resource/Texture/Inside_house_HG_night/Fg_Inside_HG.png");	//need custom
	frontGround->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	frontGround->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	objectsList.push_back(frontGround);

	/*
	GameObject* lighting = new GameObject();
	lighting->SetTexture("../Resource/Texture/Inside_house_HG_night/Light_Inside_HG.png");	//need custom
	lighting->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	lighting->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	objectsList.push_back(lighting);
	*/

	Chair = new ButtonObject();
	Chair->SetTexture("../Resource/Texture/test.png");
	Chair->SetSize(200, -285.0f);
	Chair->SetPosition(glm::vec3(455.0f, 310.0f, 0.0f));
	objectsList.push_back(Chair);
	interactableList.push_back(Chair);

	HnGKey = new ButtonObject();
	HnGKey->SetTexture("../Resource/Texture/test.png");
	HnGKey->SetSize(450, -200.0f);
	HnGKey->SetPosition(glm::vec3(5080.0f, 750.0f, 0.0f));
	objectsList.push_back(HnGKey);
	interactableList.push_back(HnGKey);

	


	ChairPlacerArea = new ButtonObject();
	ChairPlacerArea->SetTexture("../Resource/Texture/test.png");
	ChairPlacerArea->SetSize(1000, -1000.0f);
	ChairPlacerArea->SetPosition(glm::vec3(5080.0f, 413.0f, 0.0f));
	objectsList.push_back(ChairPlacerArea);
	interactableList.push_back(ChairPlacerArea);

	
	frontDoor = new ButtonObject();
	frontDoor->SetTexture("../Resource/Texture/test.png");
	frontDoor->SetSize(600, -2000.0f);
	frontDoor->SetPosition(glm::vec3(mapWidth, 500.0f, 0.0f));
	objectsList.push_back(frontDoor);
	interactableList.push_back(frontDoor);








	



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
	playerMovement(3); //Require in every level          RIQL1
	player->UpdateFrame();
	GretelPic->UpdateFrame();

	/*if (wahhhhhhhhhh == true) {
		dialogueBox->SetPosition(glm::vec3(player->GetX(), 540.0f + 600, 0.0f));
	}*/
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
	/*
	if(wahhhhhhhhhh = true){
		wahhhhhhhhhh = false;
		box(false);
		uiText->LoadText(" ", dialogueTextColor, 30.0f);
		nameText->LoadText(" ", dialogueTextColor, 30.0f);
	}*/
	uiText->LoadText(" ", dialogueTextColor, 30.0f);
	nameText->LoadText(" ", dialogueTextColor, 30.0f);

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

	cout << trueX << ":"<< y << endl;



	if (talk.talking == false) {	//no talk


		for (int i = 0; i < interactableList.size(); i++) {
			if (interactableList[i]->GetClick(trueX, y)) {
				interactableList[i]->Interact();
			}
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
			chairPic->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
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
				cabinetPic->SetTexture("../Resource/Texture/Inside_house_HG_night/Cabinet_open_Inside_HG.png");
				HnGKey->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
			}
			talk.event = "sceneGretel";
			HnGKey->Interacted = false;
		} //ChairPlacerArea
		if (ChairPlacerArea->Interacted == true) {
			if (holdedItemIndex >= 0 && holdedItemIndex < GameInstance::GetInstance()->inventory.size()) {
				if (GameInstance::GetInstance()->inventory[holdedItemIndex].name == "chair") {
					GameInstance::GetInstance()->LV2chairAtCabinet = true;
					chair2Pic->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
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
					frontDoorPic->SetPosition(glm::vec3(0, 5000.0f, 0.0f));
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



	//inventory logic
	inventoryLogic();


}




