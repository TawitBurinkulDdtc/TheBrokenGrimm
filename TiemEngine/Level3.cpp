#include "Level3.h"
#include "SpriteObject.h"

void Level3::LevelLoad()
{
	SquareMeshVbo* square = new SquareMeshVbo();
	square->LoadData();
	GameEngine::GetInstance()->AddMesh(SquareMeshVbo::MESH_NAME, square);

	//cout << "Load Level" << endl;
}

void Level3::LevelInit()
{

	mapWidth = 3269.0f;	//Require in every level          RIQL					need custom
	holdedItemIndex = -1;	//Require in every level          RIQL


	//Require in every level          RIQL		start
	GameObject* background = new GameObject();
	background->SetTexture("../Resource/Texture/Forrest.jpg");	//need custom
	background->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	background->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	backgroundList.push_back(background);
	//Require in every level          RIQL			end

	
	GameObject* pebblesPic = new GameObject();
	pebblesPic->SetTexture("../Resource/Texture/test.png");	//need custom
	pebblesPic->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	pebblesPic->SetPosition(glm::vec3(0, 5000.0f, 0.0f));
	objectsList.push_back(pebblesPic);
	




	Hansel = new ButtonObject();
	Hansel->SetTexture("../Resource/Texture/test.png");
	Hansel->SetSize(540.0f * AverySizeRatio, -695.0f * AverySizeRatio);
	Hansel->SetPosition(glm::vec3(1500.0f, 350.0f, 0.0f));
	objectsList.push_back(Hansel);
	interactableList.push_back(Hansel);


	//placedPebblesHere

	campsite = new ButtonObject();
	campsite->SetTexture("../Resource/Texture/test.png");
	campsite->SetSize(400, -400);
	campsite->SetPosition(glm::vec3(700, 150.0f, 0.0f));
	objectsList.push_back(campsite);
	interactableList.push_back(campsite);


	placedPebblesHere = new ButtonObject();
	placedPebblesHere->SetTexture("../Resource/Texture/test.png");
	placedPebblesHere->SetSize(mapWidth, -400);
	placedPebblesHere->SetPosition(glm::vec3(mapWidth / 2, 150.0f, 0.0f));
	objectsList.push_back(placedPebblesHere);
	interactableList.push_back(placedPebblesHere);

	
	HanselPic = new SpriteObject("../Resource/Texture/Characters/Hansel_Idle.png", 1, 6);
	HanselPic->SetSize(540.0f * AverySizeRatio, 695.0f * AverySizeRatio); //in animation y gotta be +
	HanselPic->SetPosition(glm::vec3(1500.0f, 350.0f, 0.0f));
	objectsList.push_back(HanselPic);
	
	

	sticks[0] = new ButtonObject();
	sticks[0]->SetTexture("../Resource/Texture/test.png");
	sticks[0]->SetSize(100.0f, -100.0f);
	sticks[0]->SetPosition(glm::vec3(1845.0f, 310.0f, 0.0f));
	objectsList.push_back(sticks[0]);
	interactableList.push_back(sticks[0]);

	
	createPlayer(2);
	player->SetPosition(glm::vec3(950.0f, Avery_y_Position, 0.0f));

	GameEngine::GetInstance()->SetDrawArea(0, 1920, 0, 1080);
	
	if (GameInstance::GetInstance()->PlayerFrom == PlayerFrom::Right) {
		player->SetPosition(glm::vec3(mapWidth-400, Avery_y_Position, 0.0f));
		GameEngine::GetInstance()->SetDrawArea(mapWidth-1920, mapWidth, 0, 1080);
	}


	


	

	










	



	//create inventory here
	createInventory();

	screenPic = new GameObject();			//(char for character)							///////////////
	screenPic->SetTexture("../Resource/Texture/invisible.png");
	screenPic->SetSize(1980, -1080.0f);//1080 + 200.0f
	screenPic->SetPosition(glm::vec3(0, 0, 0));
	uiList.push_back(screenPic);
	talk.p("../Resource/Texture/invisible.png");


	dialogueBox = new GameObject();
	dialogueBox->SetPosition(glm::vec3(960.0f, 540.0f+600, 0.0f));
	dialogueBox->SetTexture("../Resource/Texture/invisible.png");
	dialogueBox->AddTextures("../Resource/Texture/Dialogue_UI.png");
	dialogueBox->SetSize(1920.0f * 0.75f, -1080.0f * 0.75f);
	uiList.push_back(dialogueBox);

	uiText = new TextObject();
	uiText->LoadText(" ", dialogueTextColor, 100);
	uiText->SetPosition(glm::vec3(960, 150.0f+700, 0.0f));
	uiText->SetSize(500.0f, -100.0f);
	uiList.push_back(uiText);

	nameText = new TextObject();
	nameText->LoadText(" ", dialogueTextColor, 100);
	nameText->SetPosition(glm::vec3(960 - 470, 320.0f +650, 0.0f));
	nameText->SetSize(500.0f, -100.0f);
	uiList.push_back(nameText);


	playerWalkTo = player->GetX();
	playerCurrentTime = 0;




	//--------------------- walk speed editer----------------------------
	playerFrameDelay = 1.0f;
	playerStepPerFrame = 10; //10 real   // 60 debug (60 will have some interact area bug abit)
	//---------------------------------------------------------------------


	// ---------------------manage animation stuff-------------------------
	playerStandStillDelay = 100;
	//---------------------------------------------------------------------
	//cout << "Init Level" << endl;
	// RIQL end			2
	readExcel.open("../Resource/Excel/Level3.csv");
	excelRec.clear();

	//sceneIntro
	/*
	talk.talking = true;
	talk.event = "sceneIntro";
	*/
	inventoryOpen();

	getItem("Bread", "Bread for our plan", "../Resource/Texture/Items/honey.png");
}







void Level3::LevelUpdate()
{
	if (playerWalkSide != 0) {
		if (player->GetX() < 250) {
			player->SetPosition(glm::vec3(250, Avery_y_Position, 0.0f));
		}
		else if (player->GetX() > mapWidth - 250) {
			//player->SetPosition(glm::vec3(mapWidth - 250, Avery_y_Position, 0.0f));	//
			GameInstance::GetInstance()->PlayerFrom = PlayerFrom::Left;
			GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL3Scene2;
		}
	}
	playerMovement(3); //Require in every level          RIQL
	player->UpdateFrame();
	HanselPic->UpdateFrame();
}

//SpriteObject* Girl = new SpriteObject("../Resource/Texture/AveryWalk.png", 1, 6);
//Girl->SetSize(540.0f * 0.5f, 695.0f * 0.5f);

void Level3::LevelDraw()
{
	GameEngine::GetInstance()->Render(backgroundList, true);
	GameEngine::GetInstance()->Render(playerList, false);
	GameEngine::GetInstance()->Render(objectsList, false);
	GameEngine::GetInstance()->Render(uiList, false);

	//cout << "Draw Level" << endl;
}

void Level3::LevelFree()
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

void Level3::LevelUnload()
{
	GameEngine::GetInstance()->ClearMesh();
	//cout << "Unload Level" << endl;
}

void Level3::HandleKey(char key)
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

void Level3::HandleMouse(int type, int x, int y)
{

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


	cout << "pos: x " << trueX << " y " << y << endl;    //set to 1920 x 1200 to see display
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
			cout << "Hansel like eatting squeral" << endl;
			Hansel->Interacted = false; 
		}
		if (placedPebblesHere->Interacted == true) {
			if (holdedItemIndex >= 0 && holdedItemIndex < GameInstance::GetInstance()->inventory.size()) {
				if (GameInstance::GetInstance()->inventory[holdedItemIndex].name == "Bread") {
					//get to cut scene where bird eat bread crumb.
				}
			}
			placedPebblesHere->Interacted = false;
		}


		if (campsite->Interacted == true) {
			if (holdedItemIndex >= 0 && holdedItemIndex < GameInstance::GetInstance()->inventory.size()) {
				if (GameInstance::GetInstance()->inventory[holdedItemIndex].name == "stick" || GameInstance::GetInstance()->inventory[holdedItemIndex].name == "stone") {
					loseHoldedItem();
					refreshInventoryPic();
					GameInstance::GetInstance()->campSiteRequirement++;
				}
				if (GameInstance::GetInstance()->campSiteRequirement >= 8) {
					//cut scene bla bla bla, change level.
					//GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL2Scene2;
				}
			}
			campsite->Interacted = false;
		}


		/*for (int j = 0; j < 3; j++) {
			if (sticks[j]->Interacted == true) {
				getItem("pebble", "Pebbles for our plan", "../Resource/Texture/Items/pebble.png");
				sticks[j]->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
				GameInstance::GetInstance()->pebbleAmount++;
				//sticksPic[j]->SetPosition(glm::vec3(0, 5000, 0.0f));
				GameInstance::GetInstance()->pebbelCollect[j] = true;
				sticks[j]->Interacted = false;
			}
		}*/

		if (sticks[0]->Interacted == true) {
			getItem("stick", "Stick for fire", "../Resource/Texture/Items/pebble.png");
			GameInstance::GetInstance()->pebbelCollect[0] = true;
			sticks[0]->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
			sticks[0]->Interacted = false;
		}

	}

	if (talk.talking == true) { //do talk
		talk.count = talk.count + 1;


		if (talk.count == 1) { excelRecRecording(talk.event); box(true); }
		if (finishRead == true && excelRec[talk.count - 1].name != "end") {
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
		screenPic->SetTexture(talk.pictureFileName);			//SetPosition(glm::vec3(0, 0, 0));
		uiText->LoadText(talk.dialogue, dialogueTextColor, talk.f);
		nameText->LoadText(talk.name, dialogueTextColor, talk.nf);

	}//do talk

	//talk.dp("give my potato back", "../Resource/Texture/talkingGlobeTest1.png"); uiText->SetSize(700.0f, -100.0f); screenPic->SetPosition(glm::vec3(player->GetX(), 540.0f, 0.0f));
	//screenPic->SetTexture(talk.pictureFileName);			//SetPosition(glm::vec3(0, 0, 0));
	//uiText->LoadText(talk.dialogue, whiteText, 100);


	//inventory logic
	inventoryLogic();

	//playerWalkTo = x;

}




