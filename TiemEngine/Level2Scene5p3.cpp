#include "Level2Scene5p3.h"
#include "SpriteObject.h"

void Level2Scene5p3::LevelLoad()
{
	SquareMeshVbo* square = new SquareMeshVbo();
	square->LoadData();
	GameEngine::GetInstance()->AddMesh(SquareMeshVbo::MESH_NAME, square);

	//cout << "Load Level" << endl;
}

void Level2Scene5p3::LevelInit()
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

	stick = new ButtonObject();
	stick->SetTexture("../Resource/Texture/test.png");
	stick->SetSize(350, -150);
	stick->SetPosition(glm::vec3(2989.0f, 257.0f, 0.0f));
	objectsList.push_back(stick);
	interactableList.push_back(stick);

	stickPic = new GameObject();
	stickPic->SetTexture("../Resource/Texture/OutsideBirdnest/Long_stick.png");	//need custom
	stickPic->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	stickPic->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	objectsList.push_back(stickPic);

	GameObject* tee = new GameObject();
	tee->SetTexture("../Resource/Texture/OutsideBirdnest/tree.png");	//need custom
	tee->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	tee->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	objectsList.push_back(tee);

	pebble = new ButtonObject();
	pebble->SetTexture("../Resource/Texture/Items/pebbleOnTree.png");
	pebble->SetSize(350, -350);
	pebble->SetPosition(glm::vec3(2588.0f, 867.0f, 0.0f));
	objectsList.push_back(pebble);
	interactableList.push_back(pebble);

	createPlayer(3);
	player->SetPosition(glm::vec3(350.0f, Avery_y_Position, 0.0f));

	if(GameInstance::GetInstance()->pebbelCollect[4] == true){
		pebble->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
	}
	if (GameInstance::GetInstance()->stickCollect == true) {
		stick->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
		stickPic->SetPosition(glm::vec3(0, 5000.0f, 0.0f));
	}
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
	
	// RIQL end			2
	readExcel.open("../Resource/Excel/ScriptDialogueBrokenGrimm_HGHouse_Outside.csv");
	excelRec.clear();

	inventoryOpen();

	//SoundEngine->drop();
	SoundEngine = createIrrKlangDevice();
	SoundEngine->play2D("../Resource/Sound/Level2_NightTime.mp3", true);
	
}







void Level2Scene5p3::LevelUpdate()
{
	if (playerWalkSide != 0) {
		if (player->GetX() < 250) {
			SoundEngine->drop();
			GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL2Scene5;
			GameInstance::GetInstance()->PlayerFrom = PlayerFrom::Right;
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

void Level2Scene5p3::LevelDraw()
{
	GameEngine::GetInstance()->Render(backgroundList, true);
	GameEngine::GetInstance()->Render(playerList, false);
	GameEngine::GetInstance()->Render(objectsList, false);
	GameEngine::GetInstance()->Render(uiList, false);

	//cout << "Draw Level" << endl;
}

void Level2Scene5p3::LevelFree()
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

void Level2Scene5p3::LevelUnload()
{
	GameEngine::GetInstance()->ClearMesh();
	//cout << "Unload Level" << endl;
}

void Level2Scene5p3::HandleKey(char key)
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

void Level2Scene5p3::HandleMouse(int type, int x, int y)
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
	

	


	if (talk.talking == false) {	//no talk

		for (int i = 0; i < interactableList.size(); i++) {
			if (interactableList[i]->GetClick(trueX, y)) {
				interactableList[i]->Interact();
			}
		}
		
	
		if (pebble->Interacted == true) {
			if (holdedItemIndex >= 0 && holdedItemIndex < GameInstance::GetInstance()->inventory.size()) {
				if (GameInstance::GetInstance()->inventory[holdedItemIndex].name == "stick" && GameInstance::GetInstance()->pebbelCollect[4] == false) {
					loseHoldedItem();
					getItem("pebble", "Pebbles for our plan", "../Resource/Texture/Items/pebble.png");
					GameInstance::GetInstance()->pebbleAmount++;
					GameInstance::GetInstance()->pebbelCollect[4] = true;
					pebble->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
				}
				else {
					talk.talking = true;
					talk.event = "high";
				}
			}
			else {
				talk.talking = true;
				talk.event = "high";
			}
			pebble->Interacted = false;
		}
		if (stick->Interacted == true) {
			stickPic->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
			getItem("stick", "Could use to reach high stuff", "../Resource/Texture/Items/stickDark.png");
			GameInstance::GetInstance()->stickCollect = true;
			stick->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
			stick->Interacted = false;
		}
		//Logic here



	}//no talk

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



		
		//Special here (switch case stuff)



		setDialoguePosition();
		screenPic->SetTexture(talk.pictureFileName);			//SetPosition(glm::vec3(0, 0, 0));
		uiText->LoadText(talk.dialogue, dialogueTextColor, talk.f);
		nameText->LoadText(talk.name, dialogueTextColor, talk.nf);

	}//do talk


	inventoryLogic();


}




