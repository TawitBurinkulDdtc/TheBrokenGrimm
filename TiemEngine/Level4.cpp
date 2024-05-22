#include "Level4.h"
#include "SpriteObject.h"

void Level4::LevelLoad()
{
	SquareMeshVbo* square = new SquareMeshVbo();
	square->LoadData();
	GameEngine::GetInstance()->AddMesh(SquareMeshVbo::MESH_NAME, square);

	//cout << "Load Level" << endl;
}

void Level4::LevelInit()
{

	mapWidth = 3680.0f;	//Require in every level          RIQL					need custom
	holdedItemIndex = -1;	//Require in every level          RIQL


	//Require in every level          RIQL		start
	GameObject* background = new GameObject();
	background->SetTexture("../Resource/Texture/WItch_House_Outside.jpg");	//need custom
	background->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	background->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	backgroundList.push_back(background);
	//Require in every level          RIQL			end

	

	createPlayer(2);
	player->SetPosition(glm::vec3(950.0f, Avery_y_Position, 0.0f));
	player->SetSize(-540.0f * AverySizeRatio, 695.0f * AverySizeRatio);
	

	

	GameEngine::GetInstance()->SetDrawArea(0, 1920, 0, 1080);





	door = new ButtonObject();
	door->SetTexture("../Resource/Texture/test.png");
	door->SetSize(300, -300.0f);
	door->SetPosition(glm::vec3(3117.0f, 458.0f, 0.0f));
	objectsList.push_back(door);
	interactableList.push_back(door);




	



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
	readExcel.open("../Resource/Excel/Level3.csv");
	excelRec.clear();

	inventoryOpen();

	//SoundEngine->drop();
	SoundEngine = createIrrKlangDevice();
	SoundEngine->play2D("../Resource/Sound/MainMenu.mp3", true);
}







void Level4::LevelUpdate()
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

void Level4::LevelDraw()
{
	GameEngine::GetInstance()->Render(backgroundList, true);
	GameEngine::GetInstance()->Render(playerList, false);
	GameEngine::GetInstance()->Render(objectsList, false);
	GameEngine::GetInstance()->Render(uiList, false);

	//cout << "Draw Level" << endl;
}

void Level4::LevelFree()
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

void Level4::LevelUnload()
{
	GameEngine::GetInstance()->ClearMesh();
	//cout << "Unload Level" << endl;
}

void Level4::HandleKey(char key)
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

void Level4::HandleMouse(int type, int x, int y)
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
	

	


	if (talk.talking == false) {	//no talk

		for (int i = 0; i < interactableList.size(); i++) {
			if (interactableList[i]->GetClick(trueX, y)) {
				interactableList[i]->Interact();
			}
		}
		
		
		if (door->Interacted == true) {
			talk.eventz = "ending";
			talk.talking = true;
			door->Interacted = false;
		}

		//Logic here



	}//no talk

	if (talk.talking == true) { //do talk
		talk.count = talk.count + 1;

		if(talk.event != " "){
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
		}
		if (talk.eventz == "ending") {
			switch (talk.count) {
			case 1: talk.d("This is the end of first chapter"); box(true); break;
			case 2: talk.d("Thank for playing"); break;
			case 3: talk.d(" "); SoundEngine->drop(); talk.talking = false; talk.eventz = " "; box(false); talk.count = 0; GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVELArtGallery; break;
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




