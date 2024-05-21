#include "LevelArtGallery.h"
#include "SpriteObject.h"

void LevelArtGallery::LevelLoad()
{
	SquareMeshVbo* square = new SquareMeshVbo();
	square->LoadData();
	GameEngine::GetInstance()->AddMesh(SquareMeshVbo::MESH_NAME, square);

	//cout << "Load Level" << endl;
}

void LevelArtGallery::LevelInit()
{

	mapWidth = 20269.0f;	//Require in every level          RIQL					need custom
	holdedItemIndex = -1;	//Require in every level          RIQL


	//Require in every level          RIQL		start
	/*GameObject* background = new GameObject();
	background->SetTexture("../Resource/Texture/Forrest.jpg");	//need custom
	background->SetSize(mapWidth, -1080.0f);//1080 + 200.0f
	background->SetPosition(glm::vec3(mapWidth / 2, 540.0f, 0.0f));
	backgroundList.push_back(background);*/
	//Require in every level          RIQL			end










	GameObject* e = new GameObject();
	e->SetTexture("../Resource/Texture/ArtGal/0exit.png");	//need custom
	e->SetSize(250, -1080.0f);//1080 + 200.0f
	e->SetPosition(glm::vec3(100, 540.0f, 0.0f));
	objectsList.push_back(e);

	GameObject* e2 = new GameObject();
	e2->SetTexture("../Resource/Texture/ArtGal/0exit.png");	//need custom
	e2->SetSize(250, -1080.0f);//1080 + 200.0f
	e2->SetPosition(glm::vec3(mapWidth - 100, 540.0f, 0.0f));
	objectsList.push_back(e2);

	GameObject* sign = new GameObject();
	sign->SetTexture("../Resource/Texture/ArtGal/0sign.png");	//need custom
	sign->SetSize(1408 * 0.7f, -408.0f * 0.7f);//1080 + 200.0f
	sign->SetPosition(glm::vec3(1300, 840.0f, 0.0f));
	objectsList.push_back(sign);

	GameObject* a1 = new GameObject();
	a1->SetTexture("../Resource/Texture/ArtGal/6D290CD9-7DEA-45E8-95BC-4552C0523BB8.jpg");	//need custom
	a1->SetSize(3878, -1080);//1080 + 200.0f
	a1->SetPosition(glm::vec3(3859, 540.0f, 0.0f));
	objectsList.push_back(a1);





	

	createPlayer(1);
	player->SetPosition(glm::vec3(950.0f, Avery_y_Position, 0.0f));
	
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
	readExcel.open("../Resource/Excel/Level3.csv");
	excelRec.clear();

	inventoryOpen();

	
}







void LevelArtGallery::LevelUpdate()
{
	if (playerWalkSide != 0) {
		if (player->GetX() < 100) {
			//player->SetPosition(glm::vec3(250, Avery_y_Position, 0.0f));
			GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_QUIT;
		}
		else if (player->GetX() > mapWidth - 100) {
			GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_QUIT;	//
		}
	}
	playerMovement(3); //Require in every level          RIQL
	player->UpdateFrame();
}

//SpriteObject* Girl = new SpriteObject("../Resource/Texture/AveryWalk.png", 1, 6);
//Girl->SetSize(540.0f * 0.5f, 695.0f * 0.5f);

void LevelArtGallery::LevelDraw()
{
	GameEngine::GetInstance()->Render(backgroundList, true);
	GameEngine::GetInstance()->Render(playerList, false);
	GameEngine::GetInstance()->Render(objectsList, false);
	GameEngine::GetInstance()->Render(uiList, false);

	//cout << "Draw Level" << endl;
}

void LevelArtGallery::LevelFree()
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

void LevelArtGallery::LevelUnload()
{
	GameEngine::GetInstance()->ClearMesh();
	//cout << "Unload Level" << endl;
}

void LevelArtGallery::HandleKey(char key)
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

void LevelArtGallery::HandleMouse(int type, int x, int y)
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
	

	


	if (talk.talking == false) {	//no talk

		for (int i = 0; i < interactableList.size(); i++) {
			if (interactableList[i]->GetClick(trueX, y)) {
				interactableList[i]->Interact();
			}
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




