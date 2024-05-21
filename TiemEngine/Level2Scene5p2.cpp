#include "Level2Scene5p2.h"
#include "SpriteObject.h"

void Level2Scene5p2::LevelLoad()
{
	SquareMeshVbo* square = new SquareMeshVbo();
	square->LoadData();
	GameEngine::GetInstance()->AddMesh(SquareMeshVbo::MESH_NAME, square);

	//cout << "Load Level" << endl;
}

void Level2Scene5p2::LevelInit()
{

	mapWidth = 4779.15f;	//Require in every level          RIQL					need custom
	holdedItemIndex = -1;	//Require in every level          RIQL



	//Require in every level          RIQL		start
	GameObject* background = new GameObject();
	background->SetTexture("../Resource/Texture/Spider_forest/forest_spider_web.jpg");	//need custom
	background->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	background->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	backgroundList.push_back(background);
	//Require in every level          RIQL			end

	

	//Gretel

	Spider = new ButtonObject();
	Spider->SetTexture("../Resource/Texture/Characters/spiderL.png");
	Spider->SetSize(2055*0.3f,-1668 * 0.3f);
	Spider->SetPosition(glm::vec3(2880.0f, 350.0f, 0.0f));
	objectsList.push_back(Spider);
	interactableList.push_back(Spider);
	/*
	pebble = new ButtonObject();
	pebble->SetTexture("../Resource/Texture/test.png");
	pebble->SetSize(540.0f * AverySizeRatio, -695.0f * AverySizeRatio);
	pebble->SetPosition(glm::vec3(1500.0f, 350.0f, 0.0f));
	objectsList.push_back(pebble);
	interactableList.push_back(pebble);
	*/


	pebblePic = new GameObject();
	pebblePic->SetTexture("../Resource/Texture/Items/pebble.png");	//need custom
	pebblePic->SetSize(100, -100.0f);//1080 + 200.0f
	pebblePic->SetPosition(glm::vec3(2893.0f, 183.0f, 0.0f));
	objectsList.push_back(pebblePic);


	insect = new ButtonObject();
	insect->SetTexture("../Resource/Texture/insect_PlaceHolder.png");
	insect->SetSize(200,-100);
	insect->SetPosition(glm::vec3(1000.0f, 350.0f, 0.0f));
	objectsList.push_back(insect);
	interactableList.push_back(insect);
	
	//SpiderPic = new SpriteObject("../Resource/Texture/Characters/Spider_PlaceHolder.png", 1, 6);
	/*SpiderPic = new GameObject();
	SpiderPic->SetTexture("../Resource/Texture/Spider_PlaceHolder.png");
	SpiderPic->SetSize(540.0f * AverySizeRatio, -695.0f * AverySizeRatio); //in animation y gotta be +
	SpiderPic->SetPosition(glm::vec3(1500.0f, 350.0f, 0.0f));
	objectsList.push_back(SpiderPic);
	*/


	if (GameInstance::GetInstance()->pebbelCollect[3] == true) {
		pebblePic->SetPosition(glm::vec3(0, 5000.0f, 0.0f));
	}
	if (GameInstance::GetInstance()->insectCollect == true) {
		insect->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
	}


	createPlayer(3);
	player->SetPosition(glm::vec3(400.0f, Avery_y_Position, 0.0f));






	GameEngine::GetInstance()->SetDrawArea(0, 1920, 0, 1080);








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
	readExcel.open("../Resource/Excel/Level2Scene5p2.csv");
	excelRec.clear();

	//sceneIntro
	/*
	talk.talking = true;
	talk.event = "sceneIntro";
	*/
	inventoryOpen();
}







void Level2Scene5p2::LevelUpdate()
{
	if (playerWalkSide != 0) {
		if (player->GetX() < 250) {
			GameInstance::GetInstance()->PlayerFrom = PlayerFrom::Middle;
			GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL2Scene5;
		}
		else if (player->GetX() > mapWidth - 250) {
			player->SetPosition(glm::vec3(mapWidth - 250, Avery_y_Position, 0.0f));	//
		}
	}
	playerMovement(3); //Require in every level          RIQL
	player->UpdateFrame();
}

//SpriteObject* Girl = new SpriteObject("../Resource/Texture/AveryWalk.png", 1, 6);
//Girl->SetSize(540.0f * 0.5f, 695.0f * 0.5f);

void Level2Scene5p2::LevelDraw()
{
	GameEngine::GetInstance()->Render(backgroundList, true);
	GameEngine::GetInstance()->Render(playerList, false);
	GameEngine::GetInstance()->Render(objectsList, false);
	GameEngine::GetInstance()->Render(uiList, false);

	//cout << "Draw Level" << endl;
}

void Level2Scene5p2::LevelFree()
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

void Level2Scene5p2::LevelUnload()
{
	GameEngine::GetInstance()->ClearMesh();
	//cout << "Unload Level" << endl;
}

void Level2Scene5p2::HandleKey(char key)
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
	
	case 'r': 
		GameInstance::GetInstance()->PuzzleCollectPebbleDone = true;
		GameInstance::GetInstance()->PlayerFrom = Right;
		GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL2Scene4; 
		break;
	}
}

void Level2Scene5p2::HandleMouse(int type, int x, int y)
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
		
		if (Spider->Interacted == true) {
			if (holdedItemIndex >= 0 && holdedItemIndex < GameInstance::GetInstance()->inventory.size()) {
				if (GameInstance::GetInstance()->inventory[holdedItemIndex].name == "insect" && GameInstance::GetInstance()->pebbelCollect[3] == false) {
					loseHoldedItem();
					getItem("pebble", "Pebbles for our plan", "../Resource/Texture/Items/pebble.png");
					GameInstance::GetInstance()->pebbleAmount++;
					GameInstance::GetInstance()->pebbelCollect[3] = true;
					pebblePic->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
				}
			}
			Spider->Interacted = false; 
		}
		if (insect->Interacted == true) {
			if (GameInstance::GetInstance()->insectCollect == false) {
				insect->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
				getItem("insect", "An insect! I name him Kevin", "../Resource/Texture/insect_PlaceHolder.png");
				GameInstance::GetInstance()->insectCollect = true;
			}
			insect->Interacted = false;
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




