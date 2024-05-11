#include "Level2Scene5.h"
#include "SpriteObject.h"

void Level2Scene5::LevelLoad()
{
	SquareMeshVbo* square = new SquareMeshVbo();
	square->LoadData();
	GameEngine::GetInstance()->AddMesh(SquareMeshVbo::MESH_NAME, square);

	//cout << "Load Level" << endl;
}

void Level2Scene5::LevelInit()
{

	mapWidth = 4779.15f;	//Require in every level          RIQL					need custom
	holdedItemIndex = -1;	//Require in every level          RIQL




	GameObject* skyBackground = new GameObject();
	skyBackground->SetTexture("../Resource/Texture/Hansel&Gretel_outside House_Night/Sky_BG.png");	//need custom
	skyBackground->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	skyBackground->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	backgroundList.push_back(skyBackground);


	GameObject* en = new GameObject();
	en->SetTexture("../Resource/Texture/Hansel&Gretel_outside House_Night/Entrance_forest.png");	//need custom
	en->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	en->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	backgroundList.push_back(en);

	/*
	GameObject* light = new GameObject();
	light->SetTexture("../Resource/Texture/Hansel&Gretel_outside House_Night/Light.png");	//need custom
	light->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	light->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	backgroundList.push_back(light);
	*/

	//Require in every level          RIQL		start
	GameObject* background = new GameObject();
	background->SetTexture("../Resource/Texture/Hansel&Gretel_outside House_Night/BG.png");	//need custom
	background->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	background->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	backgroundList.push_back(background);
	//Require in every level          RIQL			end

	

	GameObject* house1 = new GameObject();
	house1->SetTexture("../Resource/Texture/Hansel&Gretel_outside House_Night/House.png");	//need custom
	house1->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	house1->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	backgroundList.push_back(house1);

	GameObject* doorPic = new GameObject();
	doorPic->SetTexture("../Resource/Texture/Hansel&Gretel_outside House_Night/Door.png");	//need custom
	doorPic->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	doorPic->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	backgroundList.push_back(doorPic);

	
	door = new ButtonObject();
	door->SetTexture("../Resource/Texture/test.png");
	door->SetSize(367, -525.0f);
	door->SetPosition(glm::vec3(411.0f, 500.0f, 0.0f));
	objectsList.push_back(door);
	interactableList.push_back(door);




	Gretel = new ButtonObject();
	Gretel->SetTexture("../Resource/Texture/test.png");
	Gretel->SetSize(540.0f * AverySizeRatio, -695.0f * AverySizeRatio);
	Gretel->SetPosition(glm::vec3(1500.0f, 350.0f, 0.0f));
	objectsList.push_back(Gretel);
	interactableList.push_back(Gretel);
	
	GretelPic = new SpriteObject("../Resource/Texture/Characters/Gretel_Idle.png", 1, 6);
	GretelPic->SetSize(540.0f * AverySizeRatio, 695.0f * AverySizeRatio); //in animation y gotta be +
	GretelPic->SetPosition(glm::vec3(1500.0f, 350.0f, 0.0f));
	objectsList.push_back(GretelPic);
	


	createPlayer(3);
	player->SetPosition(glm::vec3(950.0f, Avery_y_Position, 0.0f));

	



	GameObject* ml = new GameObject();
	ml->SetTexture("../Resource/Texture/Hansel&Gretel_outside House_Night/Middle_light.png");	//need custom
	ml->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	ml->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	objectsList.push_back(ml);

	GameObject* fg = new GameObject();
	fg->SetTexture("../Resource/Texture/Hansel&Gretel_outside House_Night/Frontground.png");	//need custom
	fg->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	fg->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	objectsList.push_back(fg);


	/*
	GameObject* light = new GameObject();
	light->SetTexture("../Resource/Texture/Hansel&Gretel_outside House_Night/Light.png");	//need custom
	light->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	light->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	backgroundList.push_back(light);
	*/


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
	readExcel.open("../Resource/Excel/Level2Scene5.csv");
	excelRec.clear();

	//sceneIntro
	/*
	talk.talking = true;
	talk.event = "sceneIntro";
	*/
	inventoryOpen();
}







void Level2Scene5::LevelUpdate()
{
	if (playerWalkSide != 0) {
		if (player->GetX() < 250) {
			player->SetPosition(glm::vec3(250, Avery_y_Position, 0.0f));
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

void Level2Scene5::LevelDraw()
{
	GameEngine::GetInstance()->Render(backgroundList, true);
	GameEngine::GetInstance()->Render(playerList, false);
	GameEngine::GetInstance()->Render(objectsList, false);
	GameEngine::GetInstance()->Render(uiList, false);

	//cout << "Draw Level" << endl;
}

void Level2Scene5::LevelFree()
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

void Level2Scene5::LevelUnload()
{
	GameEngine::GetInstance()->ClearMesh();
	//cout << "Unload Level" << endl;
}

void Level2Scene5::HandleKey(char key)
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

void Level2Scene5::HandleMouse(int type, int x, int y)
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
		/*
		if (Hansel->Interacted == true) {
			talk.talking = true;
			talk.event = "sceneHansel";
			Hansel->Interacted = false;
		}
		*/
		if (Gretel->Interacted == true) {
			talk.talking = true;
			talk.event = "sceneGretel";
			cout << "Gretel like eatting squeral" << endl;
			Gretel->Interacted = false; 
		}
		if (door->Interacted == true) {
			GameInstance::GetInstance()->PuzzleCollectPebbleDone = true;
			GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL2Scene2;
			door->Interacted = false;
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




