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
	testButton->SetSize(1.0f, -1.0f);
	testButton->SetPosition(glm::vec3(-2.0f, -2.0f, 0.0f));
	objectsList.push_back(testButton);
	interactableList.push_back(testButton);

	GameObject* objCursor = new GameObject();
	objCursor->SetTexture("../Resource/Texture/uglyHand.png");
	objCursor->SetSize(4.0f, -4.0f);
	uiList.push_back(objCursor);

	player = objCursor;

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
	float realX, realY;
	float windowSizeX, windowSizeY;
	windowSizeX = GameEngine::GetInstance()->GetWindowWidth();
	windowSizeY = GameEngine::GetInstance()->GetWindowHeight();
	realX = (x - (windowSizeX / 2)) / (windowSizeX / 6.0f);
	realY = -(y - (windowSizeY / 2)) / (windowSizeY / 6.0f);

	player->SetPosition(glm::vec3(realX, realY, 0));
	
	
	//printf("print work  ");

	for (int i = 0; i < interactableList.size(); i++) {
		if (interactableList[i]->GetClick(realX, realY)) {
			interactableList[i]->Interact();
		}
	}

}