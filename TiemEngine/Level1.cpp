#include "Level1.h"
#include "ButtonObject.h"


void Level1::LevelLoad()
{
	SquareMeshVbo * square = new SquareMeshVbo();
	square->LoadData();
	GameEngine::GetInstance()->AddMesh(SquareMeshVbo::MESH_NAME, square);

	//cout << "Load Level" << endl;
}

void Level1::LevelInit()
{

	

	GameObject* background = new GameObject();
	background->SetTexture("../Resource/Texture/testVillage.jpeg");
	background->SetSize(20.0f, -4.0f);
	background->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	backgroundList.push_back(background);

	GameObject * obj = new GameObject();
	obj->SetTexture("../Resource/Texture/penguin.png");
	obj->SetPosition(glm::vec3(2.5f, 2.0f, 0.0f));
	objectsList.push_back(obj);

	GameObject * obj2 = new GameObject();
	obj2->SetTexture("../Resource/Texture/penguin.png");
	obj2->SetPosition(glm::vec3(2.5f, -2.0f, 0.0f));
	objectsList.push_back(obj2);

	ButtonObject* testButton = new ButtonObject();
	testButton->SetTexture("../Resource/Texture/DoNotPress.png");
	testButton->SetSize(100.0f, -100.0f);
	testButton->SetPosition(glm::vec3(500.0f, 800.0f, 0.0f));
	objectsList.push_back(testButton);
	interactableList.push_back(testButton);

	GameObject* objPlayer = new GameObject();
	objPlayer->SetTexture("../Resource/Texture/penguin.png");
	objPlayer->SetPosition(glm::vec3(950.0f, 300.0f, 0.0f));
	objPlayer->SetSize(100.0f, -100.0f);
	objectsList.push_back(objPlayer);

	GameObject* objCursor = new GameObject();
	objCursor->SetTexture("../Resource/Texture/uglyHand.png");
	objCursor->SetSize(100.0f, -100.0f);
	uiList.push_back(objCursor);

	cursor = objCursor;

	//cout << "Init Level" << endl;
}

void Level1::LevelUpdate()
{
	//cout << "Update Level" << endl;
}

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
	case 'w': player->Translate(glm::vec3(0, 0.3, 0)); break;
	case 's': player->Translate(glm::vec3(0, -0.3, 0)); break;
	case 'a': player->Translate(glm::vec3(-0.3, 0, 0)); break;
	case 'd': player->Translate(glm::vec3(0.3, 0, 0)); break;
	case 'q': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_QUIT; ; break;
	case 'r': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_RESTART; ; break;
	case 'e': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL_test1; ; break; //LVC. Level change testing add by Zen d13m9y2023
	}
}

void Level1::HandleMouse(int type, int x, int y)
{
	

	
	
	
	//printf("print work  ");

	cursor->SetPosition(glm::vec3(x, y, 0));

	for (int i = 0; i < interactableList.size(); i++) {
		if (interactableList[i]->GetClick(x, y)) {
			interactableList[i]->Interact();
		}
	}



}