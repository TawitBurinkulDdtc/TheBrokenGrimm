#include "Level1.h"


void Level1::LevelLoad()
{
	SquareMeshVbo * square = new SquareMeshVbo();
	square->LoadData();
	GameEngine::GetInstance()->AddMesh(SquareMeshVbo::MESH_NAME, square);

	//cout << "Load Level" << endl;
}

void Level1::LevelInit()
{

	ImageObject* background = new ImageObject();
	background->SetTexture("../Resource/Texture/testVillage.jpeg");
	background->SetSize(20.0f, -4.0f);
	background->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	BackgroundList.push_back(background);

	GameObject * obj = new GameObject();
	obj->SetColor(0.0, 1.0, 0.0);
	obj->SetPosition(glm::vec3(2.5f, 2.0f, 0.0f));
	ObjectList.push_back(obj);

	GameObject * obj2 = new GameObject();
	obj2->SetColor(0.0, 0.0, 1.0);
	obj2->SetPosition(glm::vec3(2.5f, -2.0f, 0.0f));
	ObjectList.push_back(obj2);

	ImageObject* testButton = new ImageObject();
	testButton->SetTexture("../Resource/Texture/DoNotPress.png");
	testButton->SetSize(1.0f, -1.0f);
	testButton->SetPosition(glm::vec3(-2.0f, -2.0f, 0.0f));
	UIList.push_back(testButton);

	ImageObject* objCursor = new ImageObject();
	objCursor->SetTexture("../Resource/Texture/uglyHand.png");
	objCursor->SetSize(4.0f, -4.0f);
	UIList.push_back(objCursor);

	player = objCursor;

	//cout << "Init Level" << endl;
}

void Level1::LevelUpdate()
{
	//cout << "Update Level" << endl;
}

void Level1::LevelDraw()
{
	GameEngine::GetInstance()->Render(BackgroundList,true);
	GameEngine::GetInstance()->Render(PlayerList,false);
	GameEngine::GetInstance()->Render(ObjectList,false);
	GameEngine::GetInstance()->Render(UIList, false);

	//cout << "Draw Level" << endl;
}

void Level1::LevelFree()
{
	for (DrawableObject* obj : BackgroundList) {
		delete obj;
	}
	BackgroundList.clear();
	for (DrawableObject* obj : PlayerList) {
		delete obj;
	}
	PlayerList.clear();
	for (DrawableObject* obj : ObjectList) {
		delete obj;
	}
	ObjectList.clear();
	for (DrawableObject* obj : UIList) {
		delete obj;
	}
	UIList.clear();
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

	if (realX > -2.5f && realX < -1.5f && realY > -2.5f && realY < -1.5f) { // Size 1.0f, -1.0f    Pos -2.0f, -2.0f        x> (PosX-(sizeX/2))    x< (PosX+(sizeX/2))     y> (PosY-(sizeY/2))    y< (PosY+(sizeY/2))
		printf("\nbutton was press");
	}
}