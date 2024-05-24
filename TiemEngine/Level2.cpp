#include "Level2.h"
#include "SpriteObject.h"

void Level2::LevelLoad()
{
	SquareMeshVbo* square = new SquareMeshVbo();
	square->LoadData();
	GameEngine::GetInstance()->AddMesh(SquareMeshVbo::MESH_NAME, square);

	//cout << "Load Level" << endl;
}

void Level2::LevelInit()
{

	mapWidth = 2309.75f;	//Require in every level          RIQL					need custom
	holdedItemIndex = -1;	//Require in every level          RIQL

	//Require in every level          RIQL		start
	GameObject* background = new GameObject();
	background->SetTexture("../Resource/Texture/H_And_G_Bedroom_Morning.jpg");	//need custom
	background->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	background->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	backgroundList.push_back(background);
	//Require in every level          RIQL			end


	Gretel = new ButtonObject();
	Gretel->SetTexture("../Resource/Texture/test.png");
	Gretel->SetSize(540.0f * AverySizeRatio, -695.0f * AverySizeRatio);
	Gretel->SetPosition(glm::vec3(1700.0f, 350.0f, 0.0f));
	objectsList.push_back(Gretel);
	interactableList.push_back(Gretel);
	
	GretelPic = new SpriteObject("../Resource/Texture/Characters/Gretel_Idle.png", 1, 6);
	GretelPic->SetSize(540.0f * AverySizeRatio, 695.0f * AverySizeRatio); //in animation y gotta be +
	GretelPic->SetPosition(glm::vec3(1700.0f, 350.0f, 0.0f));
	objectsList.push_back(GretelPic);
	
	HanselPic = new SpriteObject("../Resource/Texture/Characters/Hansel_Idle.png", 1, 6);
	HanselPic->SetSize(540.0f * AverySizeRatio, 695.0f * AverySizeRatio); //in animation y gotta be +
	HanselPic->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
	objectsList.push_back(HanselPic);

	
	//Chipmunk = new SpriteObject("../Resource/Texture/Characters/Squirrel_PlaceholderforAvery.png", 1, 6);
	Chipmunk = new SpriteObject("../Resource/Texture/Characters/Squirrel_Avery.png", 1, 4);
	//Chipmunk->SetTexture("../Resource/Texture/Squirrel_PlaceholderforAvery.png");
	Chipmunk->SetSize(-267.0f * 0.7f, 274.0f * 0.7f); //in animation y gotta be +
	Chipmunk->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
	objectsList.push_back(Chipmunk);


	door = new ButtonObject();
	door->SetTexture("../Resource/Texture/test.png");
	door->SetSize(367, -525.0f);
	door->SetPosition(glm::vec3(411.0f, 500.0f, 0.0f));
	objectsList.push_back(door);
	interactableList.push_back(door);



	UnlikeableWomen = new SpriteObject("../Resource/Texture/Characters/Mom.png", 1, 4);
	UnlikeableWomen->SetSize(540.0f * AverySizeRatio, 900.0f * AverySizeRatio); //in animation y gotta be +
	UnlikeableWomen->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
	objectsList.push_back(UnlikeableWomen);








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
	createPlayer(3);
	player->SetPosition(glm::vec3(960, Avery_y_Position, 0.0f));


	GameEngine::GetInstance()->SetDrawArea(0, 1920, 0, 1080);
	// RIQL end			1



	// Require in every level          RIQL start		2
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
	readExcel.open("../Resource/Excel/ScriptDialogueBrokenGrimm_HGHouse_Outside.csv");
	excelRec.clear();

	//sceneIntro
	/*
	talk.talking = true;
	talk.event = "sceneIntro";
	*/
	inventoryOpen();

	

	if(GameInstance::GetInstance()->PuzzleCollectPebbleDone == false){
		player->SetPosition(glm::vec3(950.0f, 5000, 0.0f));
		Chipmunk->SetPosition(glm::vec3(1000.0f, 500.0f, 0.0f));
		HanselPic->SetPosition(glm::vec3(1400.0f, 350.0f, 0.0f));
		box(true);
		talk.event = "Enter_Story";
		talk.talking = true;
	}

	else if (GameInstance::GetInstance()->PuzzleCollectPebbleDone == true) {
		box(true);
		talk.event = "Family_Out";
		talk.talking = true;
	}
	//SoundEngine->drop();
	SoundEngine = createIrrKlangDevice();
	SoundEngine->play2D("../Resource/Sound/Level2_DayTime.mp3", true);
}







void Level2::LevelUpdate()
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
	GretelPic->UpdateFrame();
	HanselPic->UpdateFrame();
	Chipmunk->UpdateFrame();
	UnlikeableWomen->UpdateFrame();
}

//SpriteObject* Girl = new SpriteObject("../Resource/Texture/AveryWalk.png", 1, 6);
//Girl->SetSize(540.0f * 0.5f, 695.0f * 0.5f);

void Level2::LevelDraw()
{
	GameEngine::GetInstance()->Render(backgroundList, true);
	GameEngine::GetInstance()->Render(playerList, false);
	GameEngine::GetInstance()->Render(objectsList, false);
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
	case '=':
		inventoryOpen();
		break;
	case 'a': if (talk.talking == false) { playerWalkSide = 1; }
			break;
	case 'd': if (talk.talking == false) { playerWalkSide = 2; } 
			break;
	//case 'q': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_QUIT; ; break;
	//case 'r': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_RESTART; ; break;
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
		/*
		if (Hansel->Interacted == true) {
			talk.talking = true;
			talk.event = "sceneHansel";
			Hansel->Interacted = false;
		}
		*/
		if (Gretel->Interacted == true) {
			//talk.talking = true;
			//talk.event = "sceneGretel";
			if (GameInstance::GetInstance()->PuzzleCollectPebbleDone == false) {
				talk.talking = true;
				talk.event = "g1";
			}
			else if (GameInstance::GetInstance()->PuzzleCollectPebbleDone == true) {
				talk.talking = true;
				talk.event = "g4";
			}
			Gretel->Interacted = false; 
		}
		if (door->Interacted == true) {
			if(GameInstance::GetInstance()->PuzzleCollectPebbleDone == false){
				GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL2Scene2;
				SoundEngine->drop();
			}
			else {
				talk.talking = true;
				talk.eventz = "skip";
			}
			door->Interacted = false;
		}
	}

	if (talk.talking == true) { //do talk
		talk.count = talk.count + 1;

		if (talk.event != " ") {
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
					talk.event = " "; talk.talking = false; talk.count = 0; box(false); finishRead = false; excelRecClear(); talk.ndp(" ", " ", "../Resource/Texture/invisible.png");
				}
			}
		}
		if (talk.event == "Enter_Story") {
			switch (talk.count) {
			//case 1:    break;
			case 20:UnlikeableWomen->SetPosition(glm::vec3(450.0f, 400.0f, 0.0f)); Chipmunk->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f)); player->SetPosition(glm::vec3(960.0f, Avery_y_Position, 0.0f)); HanselPic->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f)); break;
			case 22:UnlikeableWomen->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f)); break;
				//dialogueBox->SetPosition(glm::vec3(player->GetX(), 540.0f + 600, 0.0f));
			//GameEngine::GetInstance()->SetDrawArea(mapWidth - 1920, mapWidth, 0, 1080); setUiPos(); break;
			}
		}

		if (talk.eventz == "skip") {
			switch (talk.count) {
			case 1: talk.p("../Resource/Texture/skipScene.png"); talk.f = 60;  box(false);  break;
			case 2: SoundEngine->drop(); talk.eventz = " "; talk.nd(" ", " "); talk.talking = false; talk.count = 0; box(false); GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL3; break;
			}
		}
		
		setDialoguePosition();
		screenPic->SetTexture(talk.pictureFileName);			//SetPosition(glm::vec3(0, 0, 0));
		uiText->LoadText(talk.dialogue, dialogueTextColor, 40);
		nameText->LoadText(talk.name, dialogueTextColor, 40);

	}//do talk

	//talk.dp("give my potato back", "../Resource/Texture/talkingGlobeTest1.png"); uiText->SetSize(700.0f, -100.0f); screenPic->SetPosition(glm::vec3(player->GetX(), 540.0f, 0.0f));
	//screenPic->SetTexture(talk.pictureFileName);			//SetPosition(glm::vec3(0, 0, 0));
	//uiText->LoadText(talk.dialogue, whiteText, 100);


	//inventory logic
	inventoryLogic();

	//playerWalkTo = x;

}




