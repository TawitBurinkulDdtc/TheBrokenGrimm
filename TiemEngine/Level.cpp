#include "Level.h"


void Level::LevelLoad()
{
	SquareMeshVbo * square = new SquareMeshVbo();
	square->LoadData();
	GameEngine::GetInstance()->AddMesh(SquareMeshVbo::MESH_NAME, square);

	//cout << "Load Level" << endl;
}

void Level::LevelInit()
{
	ImageObject * obj = new ImageObject();
	obj->SetTexture("../Resource/Texture/penguin.png");
	obj->SetSize(1.0f, -1.0f);
	objectsList.push_back(obj);

	player = obj;

	//cout << "Init Level" << endl;
}

void Level::LevelUpdate()
{
	//cout << "Update Level" << endl;
}

void Level::LevelDraw()
{
	GameEngine::GetInstance()->Render(objectsList);
	//cout << "Draw Level" << endl;
}

void Level::LevelFree()
{
	for (DrawableObject* obj : objectsList) {
		delete obj;
	}
	objectsList.clear();
	//cout << "Free Level" << endl;
}

void Level::LevelUnload()
{
	GameEngine::GetInstance()->ClearMesh();
	//cout << "Unload Level" << endl;
}

void Level::HandleKey(char key)
{

	switch (key)
	{
		case 'w': player->Translate(glm::vec3(0, 0.3, 0)); break;
		case 's': player->Translate(glm::vec3(0, -0.3, 0)); break;
		case 'a': player->Translate(glm::vec3(-0.3, 0, 0)); break;
		case 'd': player->Translate(glm::vec3(0.3, 0, 0)); break;
		case 'q': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_QUIT; ; break;
		case 'r': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_RESTART; ; break;
		case 'e': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL2; ; break;
	}
}

void Level::HandleMouse(int type, int x, int y)
{
	float realX, realY;

	// Calculate Real X Y 
	//sdl 0,0 it top left
	//sdl down right are 600,600
	//our cordinate 0,0 is mid screen.
	// top right 3,3   down left -3,-3
	//our input is sdl cordinate, we need output to be our coordinate.
	
	//realX = (x-300.0f)/100.0f;
	//realY = -(y-300.0f)/100.0f;


	//better version
	float windowSizeX, windowSizeY;
	windowSizeX = GameEngine::GetInstance()->GetWindowWidth();
	windowSizeY = GameEngine::GetInstance()->GetWindowHeight();
	realX = (x-(windowSizeX/2)) / (windowSizeX/6.0f);
	realY = -(y-(windowSizeY/2)) / (windowSizeY/6.0f);  

	player->SetPosition(glm::vec3(realX, realY, 0));
}