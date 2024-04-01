#include "Level1.h"
#include "SpriteObject.h"
#include "string"
#include "iostream"

void Level1::LevelLoad()
{
	SquareMeshVbo * square = new SquareMeshVbo();
	square->LoadData();
	GameEngine::GetInstance()->AddMesh(SquareMeshVbo::MESH_NAME, square);

	//cout << "Load Level" << endl;
}

void Level1::LevelInit()
{


	mapWidth = 6326.6f;	//Require in every level          RIQL					need custom
	holdedItemIndex = -1;	//Require in every level          RIQL

	//Require in every level          RIQL		start
	GameObject* background = new GameObject();
	background->SetTexture("../Resource/Texture/Back_library.png");	//need custom
	background->SetSize(mapWidth, -880.0f);//1080 + 200.0f
	background->SetPosition(glm::vec3(mapWidth/2, 540.0f+100.0f, 0.0f));
	backgroundList.push_back(background);
	//Require in every level          RIQL			end



	////////////////////////////////////////////////////////////// might to change after finish main stuff 
	GameObject* floatyEarthPic = new GameObject();
	floatyEarthPic->SetTexture("../Resource/Texture/Interact_1.png");
	floatyEarthPic->SetSize(mapWidth, -880.0f);
	floatyEarthPic->SetPosition(glm::vec3(mapWidth / 2, 540.0f + 100.0f, 0.0f));
	backgroundList.push_back(floatyEarthPic);

	

	ButtonObject* floatyEarth = new ButtonObject();
	floatyEarth->SetTexture("../Resource/Texture/invisible.png");
	floatyEarth->SetSize(300.0f, -300.0f);
	floatyEarth->SetPosition(glm::vec3((mapWidth / 2)+90, 675.0f, 0.0f));
	objectsList.push_back(floatyEarth);
	interactableList.push_back(floatyEarth);

	GameObject* bookPic = new GameObject();
	bookPic->SetTexture("../Resource/Texture/Interact_6.png");
	bookPic->SetSize(mapWidth, -880.0f);//1080 + 200.0f
	bookPic->SetPosition(glm::vec3(mapWidth / 2, 540.0f + 100.0f, 0.0f));
	backgroundList.push_back(bookPic);

	ButtonObject* bookInter = new ButtonObject();
	bookInter->SetTexture("../Resource/Texture/test.png");
	bookInter->SetSize(400.0f, -240.0f);
	bookInter->SetPosition(glm::vec3(1000.0f, 680.0f, 0.0f));
	objectsList.push_back(bookInter);
	interactableList.push_back(bookInter);

	GameObject* mapPic = new GameObject();
	mapPic->SetTexture("../Resource/Texture/Interact_5.png");
	mapPic->SetSize(mapWidth, -880.0f);//1080 + 200.0f
	mapPic->SetPosition(glm::vec3(mapWidth / 2, 540.0f + 100.0f, 0.0f));
	backgroundList.push_back(mapPic);

	ButtonObject* mapInter = new ButtonObject();
	mapInter->SetTexture("../Resource/Texture/test.png");
	mapInter->SetPosition(glm::vec3(5167.0f, 872.0f, 0.0f));
	mapInter->SetSize(140.0f, -100.0f);
	objectsList.push_back(mapInter);
	interactableList.push_back(mapInter);

	mirrorPic = new GameObject();
	mirrorPic->SetTexture("../Resource/Texture/Interact_4.png");
	mirrorPic->SetSize(mapWidth, -880.0f);//1080 + 200.0f
	mirrorPic->SetPosition(glm::vec3(mapWidth / 2, 540.0f + 100.0f, 0.0f));
	backgroundList.push_back(mirrorPic);

	
	mirrorInter = new ButtonObject();
	mirrorInter->SetTexture("../Resource/Texture/test.png");
	mirrorInter->SetSize(560.0f, -340.0f);
	mirrorInter->SetPosition(glm::vec3(1536.0f, 775.0f, 0.0f));
	objectsList.push_back(mirrorInter);
	interactableList.push_back(mirrorInter);

	ButtonObject* testButton = new ButtonObject();
	testButton->SetTexture("../Resource/Texture/test.png");
	testButton->SetSize(100.0f, -100.0f);
	testButton->SetPosition(glm::vec3(3500.25f, 800.0f, 0.0f));
	objectsList.push_back(testButton);
	interactableList.push_back(testButton);

	ButtonObject* testButton2 = new ButtonObject();
	testButton2->SetTexture("../Resource/Texture/test.png");
	testButton2->SetSize(100.0f, -100.0f);
	testButton2->SetPosition(glm::vec3(1200.0f, 800.0f, 0.0f));
	objectsList.push_back(testButton2);
	interactableList.push_back(testButton2);

	ButtonObject* lv1Key1 = new ButtonObject();
	lv1Key1->SetTexture("../Resource/Texture/test.png");
	lv1Key1->SetSize(60.0f, -60.0f);
	lv1Key1->SetPosition(glm::vec3(1800.0f, 600.0f, 0.0f));
	objectsList.push_back(lv1Key1);
	interactableList.push_back(lv1Key1);

	key1 = lv1Key1;
	
	if (GameInstance::GetInstance()->key1 == GameEventType::AlreadyPick) {
		lv1Key1->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
	}






	/*																//Example of picture that not need to be interact or change
	GameObject* book2Pic = new GameObject();
	book2Pic->SetTexture("../Resource/Texture/Lv1_book2.png");
	book2Pic->SetSize(mapWidth, -880.0f);//1080 + 200.0f
	book2Pic->SetPosition(glm::vec3(mapWidth / 2, 540.0f + 100.0f, 0.0f));
	backgroundList.push_back(book2Pic);
	*/

	book1Pic = new GameObject();
	book1Pic->SetTexture("../Resource/Texture/Lv1_book1.png");
	book1Pic->SetSize(mapWidth, -880.0f);//1080 + 200.0f
	book1Pic->SetPosition(glm::vec3(mapWidth / 2, 540.0f + 100.0f, 0.0f));
	backgroundList.push_back(book1Pic);
	//book1Pic->renderMode = 2;

	book2Pic = new GameObject();
	book2Pic->SetTexture("../Resource/Texture/Lv1_book2.png");
	book2Pic->SetSize(mapWidth, -880.0f);//1080 + 200.0f
	book2Pic->SetPosition(glm::vec3(mapWidth / 2, 540.0f + 100.0f, 0.0f));
	backgroundList.push_back(book2Pic);

	book3Pic = new GameObject();
	book3Pic->SetTexture("../Resource/Texture/Lv1_book3.png");
	book3Pic->SetSize(mapWidth, -880.0f);//1080 + 200.0f
	book3Pic->SetPosition(glm::vec3(mapWidth / 2, 540.0f + 100.0f, 0.0f));
	backgroundList.push_back(book3Pic);

	bookHGPic = new GameObject();
	bookHGPic->SetTexture("../Resource/Texture/Lv1_Hansel__Gretel_book.png");
	bookHGPic->SetSize(mapWidth, -880.0f);//1080 + 200.0f
	bookHGPic->SetPosition(glm::vec3(mapWidth /2 , 540.0f + 100.0f, 0.0f));
	backgroundList.push_back(bookHGPic);

	book1 = new ButtonObject();
	book1->SetTexture("../Resource/Texture/test.png");
	book1->SetSize(90, -100.0f);
	book1->SetPosition(glm::vec3(528.0f, 763.0f, 0.0f));
	objectsList.push_back(book1);
	interactableList.push_back(book1);

	book2 = new ButtonObject();
	book2->SetTexture("../Resource/Texture/test.png");
	book2->SetSize(300, -130.0f);
	book2->SetPosition(glm::vec3(921.0f, 649.0f, 0.0f));
	objectsList.push_back(book2);
	interactableList.push_back(book2);

	book3 = new ButtonObject();
	book3->SetTexture("../Resource/Texture/test.png");
	book3->SetSize(70, -130.0f);
	book3->SetPosition(glm::vec3(5397.0f, 850.0f, 0.0f));
	objectsList.push_back(book3);
	interactableList.push_back(book3);

	bookHunselAndGretel = new ButtonObject();
	bookHunselAndGretel->SetTexture("../Resource/Texture/test.png");
	bookHunselAndGretel->SetSize(70, -130.0f);
	bookHunselAndGretel->SetPosition(glm::vec3(mapWidth - 565.0f, 675.0f, 0.0f));
	objectsList.push_back(bookHunselAndGretel);
	interactableList.push_back(bookHunselAndGretel);

	/*book2 = new ButtonObject();
	book2->SetTexture("../Resource/Texture/protobook1.png");
	book2->SetSize(300, -450.0f);
	book2->SetPosition(glm::vec3(mapWidth / 2, 4000.0f, 0.0f));
	backgroundList.push_back(book2);
	*/



	birdAnim = new SpriteObject("../Resource/Texture/birdIdle.png", 1, 6); //("..Resource/Texture/FileName.png")
	//birdAnim = new GameObject(); 
	//birdAnim->SetTexture("../Resource/Texture/protoBird.png");
	birdAnim->SetSize(-167, 225.0f); //in animation y gotta be +
	birdAnim->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
	objectsList.push_back(birdAnim);

	bird = new ButtonObject();	
	bird->SetTexture("../Resource/Texture/test.png");
	bird->SetSize(167, -225.0f);
	bird->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
	objectsList.push_back(bird);
	interactableList.push_back(bird);			

	/*GameObject* objCursor = new GameObject();
	objCursor->SetTexture("../Resource/Texture/uglyHand.png");
	objCursor->SetSize(100.0f, -100.0f);
	uiList.push_back(objCursor);*/


	button1 = testButton;
	button2 = testButton2;
	//cursor = objCursor;
	//player = objPlayer;

	floatyGlobe = floatyEarth;



	// Require in every level          RIQL start		1
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
	// RIQL end			1


	GameObject* backgroundPillar = new GameObject();
	backgroundPillar->SetTexture("../Resource/Texture/Level1_Library_Pillar.png");
	backgroundPillar->SetSize(mapWidth, -880.0f);//1080 + 200.0f
	backgroundPillar->SetPosition(glm::vec3(mapWidth / 2, 540.0f + 100.0f, 0.0f));
	objectsList.push_back(backgroundPillar);



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
	dialogueBox->SetPosition(glm::vec3(960.0f, 200.0f, 0.0f));
	dialogueBox->SetTexture("../Resource/Texture/invisible.png");
	dialogueBox->SetSize(1144.0f, -434.0f);
	uiList.push_back(dialogueBox);

	uiText = new TextObject();
	SDL_Color textColor = { 0, 0, 0 }; //(0 to 255)
	uiText->LoadText(" ", textColor, 100);
	uiText->SetPosition(glm::vec3(960.0f, 880.0f, 0.0f));
	uiText->SetSize(500.0f, -100.0f);
	uiList.push_back(uiText);

	nameText = new TextObject();
	nameText->LoadText(" ", textColor, 100);
	nameText->SetPosition(glm::vec3(960.0f, 990.0f, 0.0f));
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

	readExcel.open("../Resource/Excel/Book1.csv");
	excelRec.clear();
}







void Level1::LevelUpdate()
{	
	if (playerWalkSide != 0) {
		if (player->GetX() > ((mapWidth / 2) - 600) && GameInstance::GetInstance()->birdTalking == 0 && talk.talking == false) {
			uiText->LoadText("I am bird    Fix my BOOK", blackText, 100);
			nameText->LoadText("Bird", blackText, 100);
			bird->SetPosition(glm::vec3(mapWidth / 2, 700.0f, 0.0f));
			birdAnim->SetPosition(glm::vec3(mapWidth / 2, 700.0f, 0.0f));
			talk.event = "bird talking first";
			box(true);
			talk.talking = true;
		}
		if (player->GetX() < 250) {
			player->SetPosition(glm::vec3(250, Avery_y_Position, 0.0f));
		}
		else if (player->GetX() > mapWidth - 250) {
			player->SetPosition(glm::vec3(mapWidth - 250, Avery_y_Position, 0.0f));	//
		}//mapWidth - 250
	}
	playerMovement(); //Require in every level          RIQL
	player->UpdateFrame();
	birdAnim->UpdateFrame();
}

//SpriteObject* Girl = new SpriteObject("../Resource/Texture/AveryWalk.png", 1, 6);
//Girl->SetSize(540.0f * 0.5f, 695.0f * 0.5f);

void Level1::LevelDraw()
{
	GameEngine::GetInstance()->Render(backgroundList,true);
	GameEngine::GetInstance()->Render(playerList,false);
	GameEngine::GetInstance()->Render(objectsList,false);
	GameEngine::GetInstance()->Render(uiList, false);

	//cout << "Draw Level" << endl;
}

void Level1::LevelFree()
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

void Level1::LevelUnload()
{
	GameEngine::GetInstance()->ClearMesh();
	//cout << "Unload Level" << endl;
}

void Level1::HandleKey(char key)
{

	switch (key)
	{
	case 'w':	//Avery   y max 530   min 360
		//if (player->GetY() < 530 && talk.talking == false){player->Translate(glm::vec3(0, 3.0, 0));}
		break;
	case 's': 
		//if (player->GetY() > 360 && talk.talking == false) { player->Translate(glm::vec3(0, -3.0, 0)); }
		break;
	case 'a': if (talk.talking == false) { playerWalkSide = 1; }
		//player->Translate(glm::vec3(-50, 0, 0)); 
		//GameEngine::GetInstance()->SetDrawArea(player->GetX() - 960, 960 + player->GetX(), 0, 1080);
		break;
	case 'd': if (talk.talking == false) { playerWalkSide = 2; }
		//player->Translate(glm::vec3(50, 0, 0)); 
		//GameEngine::GetInstance()->SetDrawArea(player->GetX() - 960, 960 + player->GetX(), 0, 1080); 
		break;
	case 'q': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_QUIT; ; break;
	case 'r': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_RESTART; ; break;
	//case 'e': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL_Template; ; break; //LVC. Level change testing add by Zen d13m9y2023
	}
}

void Level1::HandleMouse(int type, int x, int y)
{

	float trueX = x;
	if (player->GetX() > 960 && player->GetX() < (mapWidth - 960.0f)) {
		trueX = (x-960) + player->GetX();
	}
	else if (player->GetX() >= (mapWidth - 960.0f)) {
		trueX = x+((mapWidth - 1920.0f));
	}
	else {
		trueX = x;
	}
	

	cout << "pos: x " << trueX << " y " << y << endl;    //set to 1920 x 1200 to see display

	
	//printf("print work  ");
	


	if (talk.talking == false) {	//no talk

	
		for (int i = 0; i < interactableList.size(); i++) {
			if (interactableList[i]->GetClick(trueX, y)) {
				interactableList[i]->Interact();
			}
		}
		/*if (button1->Interacted == true) {	//showText(string word,SDL_Color textColor,int fontSize,int sizeX,int size Y); /////////////will be gone soon start
			uiText->LoadText("curse u with this", whiteText, 100);
			uiText->SetSize(700.0f, -100.0f);
			button1->Interacted = false;
			if (GameInstance::GetInstance()->inventory.size() < 8) {
				Item tomatoItem;
				tomatoItem.fileName = "../Resource/Texture/tomato.png";
				tomatoItem.name = "tomato from god";
				tomatoItem.showText = "Tomato";
				GameInstance::GetInstance()->inventory.push_back(tomatoItem);
				refreshInventoryPic();
			}
		}
		if (button2->Interacted == true) {
			GameInstance::GetInstance()->testIntInstance = GameInstance::GetInstance()->testIntInstance + 1;
			showText("a fire match drop from the ceiling",whiteText, 100, 700.0f, 100.0f);
			getItem("fire match", "It's fire match", "../Resource/Texture/fireMatch.png");
			button2->Interacted = false;
			//test = test + 1;
		
		}
		
		if (floatyGlobe->Interacted == true) {
			if (GameInstance::GetInstance()->inventory.size() < 8) {
				Item potatoItem;
				potatoItem.fileName = "../Resource/Texture/potato.png";
				potatoItem.name = "potato from god";
				potatoItem.showText = "Potato";
				GameInstance::GetInstance()->inventory.push_back(potatoItem);
				refreshInventoryPic();
			}
			talk.event = "talk to globe thingy";
			talk.talking = true;
			floatyGlobe->Interacted = false;
		} 

		
		if (key1->Interacted == true) {
			showText("Grabing Key", whiteText, 100, 700.0f, 100.0f);
			getItem("key1", "it is a key", "../Resource/Texture/key1.png");
			GameInstance::GetInstance()->key1 = GameEventType::AlreadyPick;
			key1->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
			key1->Interacted = false;
		}	

		//if (chest1->Interacted == true) {
		//if (holdedItemIndex >= 0 && holdedItemIndex < GameInstance::GetInstance()->inventory.size()) {
		//	if (GameInstance::GetInstance()->inventory[holdedItemIndex].name == "key1") { }
		//}
		//}
		*/																																	/////////////will be gone soon end


		if (book1->Interacted == true) {	//not read yet				GameInstance::GetInstance()->birdTalking = 1
			if (GameInstance::GetInstance()->birdTalking == 1) {
				talk.event = "read book 1";
				talk.talking = true;
			}
			else {
				talk.event = "not read yet";
				talk.talking = true;
			}
				book1->Interacted = false;
		}	
		if (book2->Interacted == true) {	
			if (GameInstance::GetInstance()->birdTalking == 1) {
				talk.event = "read book 2";
				talk.talking = true;
			}
			else {
				talk.event = "not read yet";
				talk.talking = true;
			}
			book2->Interacted = false;
		}
		if (book3->Interacted == true) {
			if (GameInstance::GetInstance()->birdTalking == 1) {
				talk.event = "read book 3";
				talk.talking = true;
			}
			else {
				talk.event = "not read yet";
				talk.talking = true;
			}
			book3->Interacted = false;
		}
		
		if (bookHunselAndGretel->Interacted == true) {
			if (GameInstance::GetInstance()->birdTalking == 1) {
				talk.event = "read Hansel and Gretel";
				talk.talking = true;
			}
			else {
				talk.event = "not read yet";
				talk.talking = true;
			}
			bookHunselAndGretel->Interacted = false;
		}
		
		if (mirrorInter->Interacted == true) {
			talk.event = "sceneMirror";
			talk.talking = true;
			mirrorInter->Interacted = false;
		}
		if (bird->Interacted == true) {
			for (int i = 0; i < GameInstance::GetInstance()->inventory.size(); i++) {
				if (GameInstance::GetInstance()->inventory[i].name == "bookH&G") {
					checkBookInInventory = true;
				}
			}
			if (holdedItemIndex >= 0 && holdedItemIndex < GameInstance::GetInstance()->inventory.size()) {
				if (GameInstance::GetInstance()->inventory[holdedItemIndex].name == "bookH&G") {
					talk.event = "enter the book";
					talk.talking = true;
				}
				else if (GameInstance::GetInstance()->inventory[holdedItemIndex].name != "bookH&G" && checkBookInInventory == true) {
					talk.event = "tutorial";
					talk.talking = true;
				}
				else {
					talk.event = "bird remind objective";
					talk.talking = true;
				}
			}
			else if (checkBookInInventory == true) {
				talk.event = "tutorial";
				talk.talking = true;
			}
			else {
				talk.event = "bird remind objective";
				talk.talking = true;
			}
			//cout << "Bird work" << endl;
			bird->Interacted = false;
		}

		//objectPickableItem(key1, GameInstance::GetInstance()->key1,"key1", "it is a key", "../Resource/Texture/key1.png","Grabing Key", whiteText, 100, 700.0f, 100.0f);   //alternative code
		//inventoryLogic();
	}//no talk

	if (talk.talking == true) { //do talk
		talk.count = talk.count + 1;
		


		if (talk.event == "not read yet") {
			switch (talk.count) {
			case 1: talk.nd("Avery", "I want to check this place first before reading"); talk.f = 60;  box(true);  break;
			case 2: talk.event = " "; talk.nd(" ", " "); talk.talking = false; talk.count = 0; box(false); break;
			}
		}



		if (talk.event == "bird talking first") {		//SetPosition(glm::vec3(3500.25f, 800.0f, 0.0f));
			switch (talk.count) {
			case 1: //excelRecRecording("scene2");
				talk.nd("Graf", "Hello, Young child."); talk.f = 35; break;
			case 2: talk.nd("Graf", "My name is Graf, the librarian of this forest."); talk.f = 35; break;//box.(true); in update func
			//case 2: talk.nd(excelRec[2].name, excelRec[2].dialogue); talk.f = 35; break;
			case 3: talk.nd("Avery", "B-Bird can talk?! "); talk.f = 35; break;
			case 4: talk.nd("Graf", "My name is Graf, the librarian of this forest."); talk.f = 35; break;
			case 5:	talk.nd("Avery", "What "); talk.f = 35;   break;
			case 6:	talk.d("Sorry but how can I leave this place?"); talk.f = 35;  break;
			case 7:	talk.d("I'm sorry but I cannot lets you leave"); talk.f = 35;  break;
			case 8: talk.nd("Avery", "Ok..."); talk.f = 100;  GameInstance::GetInstance()->birdTalking = 1; break;
			case 9: talk.event = " "; talk.nd(" ", " "); talk.talking = false; box(false); talk.count = 0;   break;
			}
		}
	


		if (talk.event == "bird remind objective") {		//SetPosition(glm::vec3(3500.25f, 800.0f, 0.0f));
			switch (talk.count) {
			case 1: talk.nd("Graf","Find a book where the story are weird");  box(true);  talk.f = 60; break;
			case 2: talk.d("Look at the bookshelf around here"); talk.f = 60; break;
			case 3: talk.event = " "; talk.nd(" "," "); talk.talking = false; box(false); talk.count = 0; break;
			}

		}

		if (talk.event == "read book 1") {		
			switch (talk.count) {
			case 1: talk.d("Story about a kid who got lost in the forest"); box(true); talk.f = 60; picGlow(book1Pic, true); break;
			case 2: talk.d("and got the help from a fairy to bring him back home.");  talk.f = 60; break;
			case 3: talk.event = " ";  talk.d(" "); talk.talking = false; talk.count = 0; box(false); picGlow(book1Pic, false); break;
			}
		}if (talk.event == "read book 2") {		
			switch (talk.count) {
			case 1: talk.d("The book is about witch history and detail about witch"); box(true); talk.f = 60; picGlow(book2Pic, true); break;
			case 2: talk.d("So horrify"); box(true); talk.f = 60; break;
			case 3: talk.event = " ";  talk.d(" "); talk.talking = false; talk.count = 0; box(false); picGlow(book2Pic, false); break;
			}
		}if (talk.event == "read book 3") {		
			switch (talk.count) {
			case 1: talk.d("The history book about the medieval age"); box(true); talk.f = 60; picGlow(book3Pic, true); break;
			case 2: talk.d("It shows that there are age that people are starving");  talk.f = 60; break;
			case 3: talk.d("due to the crisis that crops are hard to grow.");  talk.f = 60; break;
			case 4: talk.event = " ";  talk.d(" "); talk.talking = false; talk.count = 0; box(false); picGlow(book3Pic, false); break;
			}
		}		
		if (talk.event == "sceneMirror") {			//use swichcase for item and event instead
			if (talk.count == 1) { excelRecRecording(talk.event); box(true);}
			if(finishRead == true && excelRec[talk.count - 1].name != "end") {
				if (excelRec[talk.count-1].name != "\0") {
					talk.n(excelRec[talk.count-1].name);
				}
				if (excelRec[talk.count-1].dialogue != "\0") {
					talk.d(excelRec[talk.count-1].dialogue);
				}
				if (excelRec[talk.count - 1].pictureFileName != "\0"){
					talk.p(excelRec[talk.count - 1].pictureFileName);
				}
				if (excelRec[talk.count - 1].sNFont != "\0") {
					talk.nf = excelRec[talk.count - 1].nf;
				}
				if (excelRec[talk.count - 1].sFont != "\0") {
					talk.f = excelRec[talk.count - 1].f;
				}
			}
			if(excelRec.empty()==false){
				if (excelRec[talk.count - 1].name == "end") {
					talk.talking = false; talk.count = 0; box(false); finishRead = false; picGlow(mirrorPic, false); excelRecClear(); talk.ndp(" ", " ", "../Resource/Texture/invisible.png");
				}
			}
		}

		if (talk.event == "tutorial") {				//tutorial
			switch (talk.count) {
			case 1: talk.nd("Graf","Well good job, Avery."); box(true); talk.f = 50; break;
			case 2:	talk.d("Okay, then left-click on the book on the inventory bar�"); talk.f = 50;  break;
			case 3:	talk.d("and click on me to give book to me"); talk.f = 60; break;
			case 4: talk.event = " ";  talk.nd(" "," "); talk.talking = false; box(false); talk.count = 0; break;
			}
		}


		if (talk.event == "read Hansel and Gretel") {
			switch (talk.count) {
			case 1: talk.dp("It's Hansel and Gretel story", "../Resource/Texture/invisible.png"); box(true); talk.f = 60; bookHGPic->renderMode = 2;  break;
			case 2:	talk.d("What a classic story"); talk.f = 60;  break;
			case 3:	talk.d("Wait why does the ending look like this?"); talk.f = 60; break;
			case 4:	talk.d("This is the book it talked about");  break;
			case 5: talk.event = " ";  talk.dp(" ", "../Resource/Texture/invisible.png"); talk.talking = false; box(false); talk.count = 0; 
				getItem("bookH&G", "A distorted story of Hansel and Gretel", "../Resource/Texture/HanselAndGretelBook.png"); 
				bookHunselAndGretel->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f)); bookHGPic->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
				bookHGPic->renderMode = 1;
				break;
			}
		}

		if (talk.event == "enter the book") {
			switch (talk.count) {
			case 1: talk.nd("Bird", "Good job, Avery");  box(true);  talk.f = 60;  break;
			case 2:	talk.d("Okay, hmm �Hansel and Gretel.�"); talk.f = 60;  break;
			case 3:	talk.d("That�s a good pick."); talk.f = 60;  break;
			case 4:	talk.d("Now let me explain the rules"); talk.f = 60; break;
			case 5:	talk.d("There are two thoundsand rul");  break;
			case 6:	talk.d("wait, I can't remember all!");  break;
			case 7:	talk.d("Please tell me breifly");  break;
			case 8:	talk.ndp(" "," ", "../Resource/Texture/Level1AverySuxInBuk.png"); box(false); break;
			case 9: talk.event = " ";  talk.dp(" ", "../Resource/Texture/Level1AverySuxInBuk.png"); talk.talking = false; 
				talk.count = 0; GameInstance::GetInstance()->PlayerFrom = PlayerFrom::Right; 
				GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL2; break;
			}
		}

		setDialoguePosition();
		dialogueCharacter->SetTexture(talk.pictureFileName);			//SetPosition(glm::vec3(0, 0, 0));
		uiText->LoadText(talk.dialogue, blackText, talk.f);
		nameText->LoadText(talk.name, blackText, talk.nf);

	}//do talk

	//talk.dp("give my potato back", "../Resource/Texture/talkingGlobeTest1.png"); uiText->SetSize(700.0f, -100.0f); dialogueCharacter->SetPosition(glm::vec3(player->GetX(), 540.0f, 0.0f));
	//dialogueCharacter->SetTexture(talk.pictureFileName);			//SetPosition(glm::vec3(0, 0, 0));
	//uiText->LoadText(talk.dialogue, whiteText, 100);


	//inventory logic
	inventoryLogic();
	
	//playerWalkTo = x;

}






void Level1::refreshInventoryPic() {
	for (int i = 0; i < 8; i++) { if (i >= GameInstance::GetInstance()->inventory.size()) { inventoryL[i]->SetTexture("../Resource/Texture/invisible.png"); } else { inventoryL[i]->SetTexture(GameInstance::GetInstance()->inventory[i].fileName); } }
}
void Level1::createInventory() {
	//inventory display stuff
	inventoryBar = new GameObject();
	inventoryBar->SetPosition(glm::vec3(960.0f, 540.0f, 0.0f));
	inventoryBar->SetTexture("../Resource/Texture/invisible.png");
	inventoryBar->SetSize(1920.0f, -1080.0f);
	uiList.push_back(inventoryBar);

	
	
	for (int i = 0; i < 8; i++) {
		inventoryL[i] = new ItemUi();
		inventoryL[i]->SetSize(120.0f, -120.0f);
		inventoryL[i]->SetPosition(glm::vec3(250.0f+(200.0f*i), 100.0f, 0.0f));
		uiList.push_back(inventoryL[i]);
		interactableList.push_back(inventoryL[i]);
		if (i >= GameInstance::GetInstance()->inventory.size()) {
			inventoryL[i]->SetTexture("../Resource/Texture/invisible.png");
		}
		else {
			inventoryL[i]->SetTexture(GameInstance::GetInstance()->inventory[i].fileName);
		}
	}
	for (int i = 0; i < 8; i++) {
		inventoryBox[i] = new GameObject();
		inventoryBox[i]->SetSize(230.0f, -230.0f);
		inventoryBox[i]->SetPosition(glm::vec3(250.0f + (200.0f * i), 110.0f, 0.0f));
		inventoryBox[i]->SetTexture("../Resource/Texture/UIred.png");
		uiList.push_back(inventoryBox[i]);
	}
}
void Level1::inventoryLogic() {
	for (int i = 0; i < GameInstance::GetInstance()->inventory.size(); i++) {
		if (inventoryL[i]->Interacted == true) {
			holdedItemIndex = i;
			inventoryBox[holdedItemIndex]->SetTexture("../Resource/Texture/UI_Grreenn.png");
			uiText->LoadText(GameInstance::GetInstance()->inventory[i].showText, GameInstance::GetInstance()->inventory[i].textColor, GameInstance::GetInstance()->inventory[i].textFontSize);
			uiText->SetSize(GameInstance::GetInstance()->inventory[i].textSizeX, -(GameInstance::GetInstance()->inventory[i].textSizeY));
			lastHold[i] = true;
			inventoryL[i]->Interacted = false;
		}
	}
	for (int i = 0; i < GameInstance::GetInstance()->inventory.size(); i++) {
		if (i!= holdedItemIndex && lastHold[i]==true){
			inventoryBox[i]->SetTexture("../Resource/Texture/UIred.png");
			lastHold[i] = false;
		}
	}

}


//string interact = "../Resource/Texture/UI_Grreenn.png";
	//string uninteract = "../Resource/Texture/UIred.png";


void Level1::showText(string word, SDL_Color textColor, int fontSize, float sizeX, float sizeY){
	uiText->LoadText(word, textColor, fontSize);
	uiText->SetSize(sizeX, -sizeY);
}	


void Level1::setDialoguePosition(){
	if (player->GetX() >= 960 && player->GetX() <= mapWidth-960) {
		dialogueCharacter->SetPosition(glm::vec3(player->GetX(), 540.0f, 0.0f));
	}
	else if (player->GetX() < 960) {
		dialogueCharacter->SetPosition(glm::vec3(960, 540.0f, 0.0f));
	}
	else if (player->GetX() > mapWidth - 960) {
		dialogueCharacter->SetPosition(glm::vec3(mapWidth - 960, 540.0f, 0.0f));
	}
}





void Level1::getItem(string name, string displayText, string fileName) {
	if (GameInstance::GetInstance()->inventory.size() < 8) {	
		Item theItem;
		theItem.fileName = fileName;
		theItem.name = name;
		theItem.showText = displayText;
		GameInstance::GetInstance()->inventory.push_back(theItem);
		refreshInventoryPic();
	}
}




void Level1::objectPickableItem(ButtonObject *object, GameEventType ge,/*getItem info*/ string name, string displayText, string fileName,/*showText info*/string word, SDL_Color textColor, int fontSize, float sizeX, float sizeY){
	if (object->Interacted == true) {
		showText(word, textColor, fontSize, sizeX, sizeY);
		getItem(name, displayText, fileName);
		ge = GameEventType::AlreadyPick;
		object->SetPosition(glm::vec3(0.0f, 5000.0f, 0.0f));
		object->Interacted = false;
	}
}

//nameText->LoadText("Avery", whiteText, 100);

void Level1::name(string input) {
	nameText->LoadText(input, whiteText, 100);
}


void Level1::box(bool open){
	if(open == true) {
		dialogueBox->SetTexture("../Resource/Texture/dialogueBox.png");
		if (player->GetX() > 960 && player->GetX() < (mapWidth - 960.0f)) {
			dialogueBox->SetPosition(glm::vec3(player->GetX(), 880.0f, 0.0f));
		}
		else if(player->GetX() <= 960){ dialogueBox->SetPosition(glm::vec3(960, 880.0f, 0.0f)); }
		else if (player->GetX() >= (mapWidth - 960.0f)) { dialogueBox->SetPosition(glm::vec3((mapWidth - 960.0f), 880.0f, 0.0f)); }
	}
	else {
		dialogueBox->SetTexture("../Resource/Texture/invisible.png");
	}
}

void Level1::setUiPos() {
	uiText->SetPosition(glm::vec3(player->GetX(), 880.0f, 0.0f));
	nameText->SetPosition(glm::vec3(player->GetX(), 990.0f, 0.0f));
	inventoryBar->SetPosition(glm::vec3(player->GetX(), 540.0f, 0.0f));
	for (int i = 0; i < 8; i++) {
		inventoryL[i]->SetPosition(glm::vec3((player->GetX() - 960) + 250.0f + (200 * i), 100.0f, 0.0f));		
	}
	for (int i = 0; i < 8; i++) {
		inventoryBox[i]->SetPosition(glm::vec3((player->GetX() - 960) + 250.0f + (200 * i), 110.0f, 0.0f));
	}

	//inventoryBox[i]
}


void Level1::picGlow(GameObject* go, bool b) {
	if (b == true) {
		go->renderMode = 2;
	}
	else {
		go->renderMode = 1;
	}
}



void Level1::createPlayer(){
	player = new SpriteObject("../Resource/Texture/AveryIdle.png", 1, 6);
	player->SetSize(540.0f * AverySizeRatio, 695.0f * AverySizeRatio);
	objectsList.push_back(player);
}


//GameInstance::GetInstance()->PlayerFrom = PlayerFrom::Right;


void Level1::playerMovement() {
	if (SDL_GetTicks() > playerCurrentTime + playerFrameDelay) {
		
		if (playerWalkSide != 0) {

			if (pSpriteInt == 0) {
				player->SetTexture("../Resource/Texture/AveryWalk.png");
				pSpriteInt = 1;
			}
			else if (playerWalkSide == 1) {
				player->Translate(glm::vec3(-playerStepPerFrame, 0, 0));
				if (player->GetX() > 960 && player->GetX() < (mapWidth - 960.0f)) { //&& player->GetX() < (mapWidth - 960.0f)										//set camera limit here
					GameEngine::GetInstance()->SetDrawArea(player->GetX() - 960, 960 + player->GetX(), 0, 1080);
					setUiPos();
				}
				player->SetSize(540.0f * AverySizeRatio, 695.0f * AverySizeRatio);
				playerWalkSide = 0;
			}
			else if (playerWalkSide == 2) {	//player walk here
				player->Translate(glm::vec3(playerStepPerFrame, 0, 0));
				if (player->GetX() > 960 && player->GetX() < (mapWidth - 960.0f)) { //&& player->GetX() < (mapWidth - 960.0f)										//set camera limit here
					GameEngine::GetInstance()->SetDrawArea(player->GetX() - 960, 960 + player->GetX(), 0, 1080);
					setUiPos();
				}

				player->SetSize(-540.0f * AverySizeRatio, 695.0f * AverySizeRatio);
				playerWalkSide = 0;
			}

			playerStartStandStill = SDL_GetTicks();
		}
		else if (pSpriteInt == 1 && SDL_GetTicks() > playerStartStandStill + playerStandStillDelay) {
			player->SetTexture("../Resource/Texture/AveryIdle.png");
			pSpriteInt = 0;
		}
		playerCurrentTime = SDL_GetTicks();
	}
}



void Level1::excelRecRecording(string sceneName){
	string temp_read;
	talkExcelRecord tempExR;
	while (readExcel.good()) {
		getline(readExcel, temp_read, ',');
		//cout<< temp_read<<endl;
		if (temp_read == sceneName) {   //temp_read == "poop never die"
			int i = 0;
			excelRec.push_back(tempExR);
			getline(readExcel, excelRec[i].name, ',');
			getline(readExcel, excelRec[i].dialogue, ',');
			getline(readExcel, excelRec[i].pictureFileName, ',');
			getline(readExcel, excelRec[i].sNFont, ',');
			getline(readExcel, excelRec[i].sFont, ',');
			getline(readExcel, excelRec[i].bug, ',');
			if (excelRec[i].sNFont != "\0") {
				excelRec[i].nf = stoi(excelRec[i].sNFont);
			}
			if (excelRec[i].sFont != "\0") {
				excelRec[i].f = stoi(excelRec[i].sFont);
			}
			while (excelRec[i].name != "end") {
				excelRec.push_back(tempExR);
				i = i + 1;
				readExcel.ignore(1, ',');
				getline(readExcel, excelRec[i].name, ',');
				getline(readExcel, excelRec[i].dialogue, ',');
				getline(readExcel, excelRec[i].pictureFileName, ',');
				getline(readExcel, excelRec[i].sNFont, ',');
				getline(readExcel, excelRec[i].sFont, ',');
				getline(readExcel, excelRec[i].bug, ',');
				if (excelRec[i].sNFont != "\0") {
					excelRec[i].nf = stoi(excelRec[i].sNFont);
				}
				if (excelRec[i].sFont != "\0") {
					excelRec[i].f = stoi(excelRec[i].sFont);
				}
				talkEndAt = i;
			}
		}
	}
	finishRead = true;
}
void Level1::excelRecClear(){
	excelRec.clear();
	//readExcel.clear();
	readExcel.seekg(0, readExcel.beg);
}