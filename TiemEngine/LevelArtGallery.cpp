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

	mapWidth = 36500.0f;	//Require in every level          RIQL					need custom
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
	e->SetPosition(glm::vec3(200, 540.0f, 0.0f));
	objectsList.push_back(e);

	GameObject* e2 = new GameObject();
	e2->SetTexture("../Resource/Texture/ArtGal/0exit.png");	//need custom
	e2->SetSize(250, -1080.0f);//1080 + 200.0f
	e2->SetPosition(glm::vec3(mapWidth - 200, 540.0f, 0.0f));
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

	GameObject* a2 = new GameObject();
	a2->SetTexture("../Resource/Texture/ArtGal/FBFD3F86-7CC5-45B2-9454-8A648FB48BD2.jpg");	//need custom
	a2->SetSize(2817, -1080);//1080 + 200.0f
	a2->SetPosition(glm::vec3(7206.5f, 540.0f, 0.0f));
	objectsList.push_back(a2);

	GameObject* a3 = new GameObject();
	a3->SetTexture("../Resource/Texture/ArtGal/Wood2.png");	//need custom
	a3->SetSize(600, -600);//1080 + 200.0f
	a3->SetPosition(glm::vec3(8806.5f, 400.0f, 0.0f));
	objectsList.push_back(a3);

	GameObject* a4 = new GameObject();
	a4->SetTexture("../Resource/Texture/ArtGal/Wood3.png");	//need custom
	a4->SetSize(600, -600);//1080 + 200.0f
	a4->SetPosition(glm::vec3(9306.5f, 400.0f, 0.0f));
	objectsList.push_back(a4);
	
	GameObject* a5 = new GameObject();
	a5->SetTexture("../Resource/Texture/ArtGal/Pond_with_bucket_.png");	//need custom
	a5->SetSize(700, -700);//1080 + 200.0f
	a5->SetPosition(glm::vec3(10000.5f, 540.0f, 0.0f));
	objectsList.push_back(a5);

	
	GameObject* a6 = new GameObject();
	a6->SetTexture("../Resource/Texture/ArtGal/a6.png");	//need custom
	a6->SetSize(1400*0.5f, -800*0.5f);//1080 + 200.0f
	a6->SetPosition(glm::vec3(11400.5f, 800.0f, 0.0f));
	objectsList.push_back(a6);
	
	GameObject* a7 = new GameObject();
	a7->SetTexture("../Resource/Texture/ArtGal/a7.png");	//need custom
	a7->SetSize(700, -500);//1080 + 200.0f
	a7->SetPosition(glm::vec3(12400, 600, 0.0f));
	objectsList.push_back(a7);

	GameObject* a8 = new GameObject();
	a8->SetTexture("../Resource/Texture/ArtGal/a8.png");	//need custom
	a8->SetSize(2026, -800);//1080 + 200.0f
	a8->SetPosition(glm::vec3(13800.5f, 600.0f, 0.0f));
	objectsList.push_back(a8);

	GameObject* a9 = new GameObject();
	a9->SetTexture("../Resource/Texture/ArtGal/a9.png");	//need custom
	a9->SetSize(1778, -1080);//1080 + 200.0f
	a9->SetPosition(glm::vec3(16000, 540, 0.0f));
	objectsList.push_back(a9);

	

	GameObject* a12 = new GameObject();
	a12->SetTexture("../Resource/Texture/ArtGal/a12a.png");	//need custom
	a12->SetSize(1000, -1000);//1080 + 200.0f
	a12->SetPosition(glm::vec3(19000, 560, 0.0f));
	objectsList.push_back(a12);

	GameObject* a13 = new GameObject();
	a13->SetTexture("../Resource/Texture/ArtGal/a13.png");	//need custom
	a13->SetSize(1182, -600);//1080 + 200.0f
	a13->SetPosition(glm::vec3(20300, 700, 0.0f));
	objectsList.push_back(a13);

	GameObject* a13a = new GameObject();
	a13a->SetTexture("../Resource/Texture/ArtGal/a13a.png");	//need custom
	a13a->SetSize(642.5f, -900);//1080 + 200.0f
	a13a->SetPosition(glm::vec3(21500, 600, 0.0f));
	objectsList.push_back(a13a);


	GameObject* a14 = new GameObject();
	a14->SetTexture("../Resource/Texture/ArtGal/a14.png");	//need custom
	a14->SetSize(1942, -900);//1080 + 200.0f
	a14->SetPosition(glm::vec3(23300, 600, 0.0f));
	objectsList.push_back(a14);

	GameObject* a18 = new GameObject();
	a18->SetTexture("../Resource/Texture/ArtGal/a18.png");	//need custom
	a18->SetSize(2187, -900);//1080 + 200.0f
	a18->SetPosition(glm::vec3(25800, 600, 0.0f));
	objectsList.push_back(a18);

	GameObject* a27 = new GameObject();
	a27->SetTexture("../Resource/Texture/ArtGal/a27.png");	//need custom
	a27->SetSize(1650, -900);//1080 + 200.0f
	a27->SetPosition(glm::vec3(28000, 600, 0.0f));
	objectsList.push_back(a27);

	GameObject* a28 = new GameObject();
	a28->SetTexture("../Resource/Texture/ArtGal/a28.jpg");	//need custom
	a28->SetSize(1135, -900);//1080 + 200.0f
	a28->SetPosition(glm::vec3(29800, 600, 0.0f));
	objectsList.push_back(a28);

	GameObject* a32 = new GameObject();
	a32->SetTexture("../Resource/Texture/ArtGal/a32.png");	//need custom
	a32->SetSize(1194, -900);//1080 + 200.0f
	a32->SetPosition(glm::vec3(31200, 600, 0.0f));
	objectsList.push_back(a32);

	GameObject* a33 = new GameObject();
	a33->SetTexture("../Resource/Texture/ArtGal/a33.png");	//need custom
	a33->SetSize(1116*0.7f, -786 * 0.7f);//1080 + 200.0f
	a33->SetPosition(glm::vec3(32200, 600, 0.0f));
	objectsList.push_back(a33);

	GameObject* a34 = new GameObject();
	a34->SetTexture("../Resource/Texture/ArtGal/a34.png");	//need custom
	a34->SetSize(1220 * 0.7f, -784 * 0.7f);//1080 + 200.0f
	a34->SetPosition(glm::vec3(33200, 600, 0.0f));
	objectsList.push_back(a34);

	GameObject* a41 = new GameObject();
	a41->SetTexture("../Resource/Texture/ArtGal/a41.png");	//need custom
	a41->SetSize(1200, -1200);//1080 + 200.0f
	a41->SetPosition(glm::vec3(35000, 500, 0.0f));
	objectsList.push_back(a41);

	i1 = new ButtonObject();
	i1->SetTexture("../Resource/Texture/ArtGal/0button.png");
	i1->SetSize(300, -150.0f);
	i1->SetPosition(glm::vec3(9000.0f, 800.0f, 0.0f));
	objectsList.push_back(i1);
	interactableList.push_back(i1);
	
	i2 = new ButtonObject();
	i2->SetTexture("../Resource/Texture/ArtGal/0button.png");
	i2->SetSize(300, -150.0f);
	i2->SetPosition(glm::vec3(10500.0f, 400.0f, 0.0f));
	objectsList.push_back(i2);
	interactableList.push_back(i2);

	createPlayer(1);
	player->SetPosition(glm::vec3(950.0f, Avery_y_Position, 0.0f));
	
	GameEngine::GetInstance()->SetDrawArea(0, 1920, 0, 1080);
	
	//player->SetPosition(glm::vec3(34400.0f, Avery_y_Position, 0.0f));
	





	


	GameObject* a11 = new GameObject();
	a11->SetTexture("../Resource/Texture/ArtGal/a11.jpg");	//need custom
	a11->SetSize(720, -1080);//1080 + 200.0f
	a11->SetPosition(glm::vec3(17700, 540, 0.0f));
	objectsList.push_back(a11);







	



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
		
		if (i1->Interacted == true) {
			talk.eventz = "i1";
			talk.talking = true;
			i1->Interacted = false;
		}
		if (i2->Interacted == true) {
			talk.eventz = "i2";
			talk.talking = true;
			i2->Interacted = false;
		}

		//Logic here



	}//no talk

	if (talk.talking == true) { //do talk
		talk.count = talk.count + 1;


		if (talk.eventz == "i1") {
			switch (talk.count) {
			case 1: talk.d("We have plan to make a puzzle where player have to avoid danger"); box(true); break;
			case 2: talk.d("The clue will be from looking for scrath mark on trees"); break;
			case 3: talk.d("Due to time limitation   we have to cut it out"); break;
			case 4: talk.d(" "); talk.talking = false; talk.eventz = " "; box(false); talk.count = 0;  break;
			}
		}

		if (talk.eventz == "i2") {
			switch (talk.count) {
			case 1: talk.d("Player once need to collect pebble from under the well"); box(true); break;
			case 2: talk.d("We also plan for bird to fly and hit pebble down the well"); break;
			case 3: talk.d("Due to time limitation   we have to cut it out"); break;
			case 4: talk.d(" "); talk.talking = false; talk.eventz = " "; box(false); talk.count = 0;  break;
			}
		}



		
		//Special here (switch case stuff)



		setDialoguePosition();
		screenPic->SetTexture(talk.pictureFileName);			//SetPosition(glm::vec3(0, 0, 0));
		uiText->LoadText(talk.dialogue, dialogueTextColor, 40);
		nameText->LoadText(talk.name, dialogueTextColor, 40);

	}//do talk


	inventoryLogic();


}




