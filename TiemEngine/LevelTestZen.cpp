#include "LevelTestZen.h"

void LevelTestZen::LevelLoad()
{
	SquareMeshVbo * square = new SquareMeshVbo();
	square->LoadData();
	GameEngine::GetInstance()->AddMesh(SquareMeshVbo::MESH_NAME, square);

	//cout << "Load Level" << endl;
}

void LevelTestZen::LevelInit()
{
	GameObject * obj = new GameObject();
	obj->SetColor(0.0, 1.0, 0.0);
	objectsList.push_back(obj);

	player = obj;

	GameObject * obj2 = new GameObject();
	obj2->SetColor(0.0, 1.0, 0.0);
	obj2->SetPosition(glm::vec3(2.0f, 2.0f, 0.0f));
	objectsList.push_back(obj2);

	GameObject * obj3 = new GameObject();
	obj3->SetColor(0.0, 1.0, 0.0);
	obj3->SetPosition(glm::vec3(-2.0f, -2.0f, 0.0f));
	objectsList.push_back(obj3);

	//cout << "Init Level" << endl;
}

void LevelTestZen::LevelUpdate()
{
	//cout << "Update Level" << endl;
}

void LevelTestZen::LevelDraw()
{
	GameEngine::GetInstance()->Render(objectsList);
	//cout << "Draw Level" << endl;
}

void LevelTestZen::LevelFree()
{
	for (DrawableObject* obj : objectsList) {
		delete obj;
	}
	objectsList.clear();
	//cout << "Free Level" << endl;
}

void LevelTestZen::LevelUnload()
{
	GameEngine::GetInstance()->ClearMesh();
	//cout << "Unload Level" << endl;
}

void LevelTestZen::HandleKey(char key)
{

	switch (key)
	{
	case 'w': player->Translate(glm::vec3(0, 0.3, 0)); break;
	case 's': player->Translate(glm::vec3(0, -0.3, 0)); break;
	case 'a': player->Translate(glm::vec3(-0.3, 0, 0)); break;
	case 'd': player->Translate(glm::vec3(0.3, 0, 0)); break;
	case 'q': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_QUIT; ; break;
	case 'r': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_RESTART; ; break;
	case 'e': GameEngine::GetInstance()->GetStateController()->gameStateNext = GameState::GS_LEVEL1; ; break;
	}
}

void LevelTestZen::HandleMouse(int type, int x, int y)
{
	float realX, realY;

	// Calculate Real X Y 
	realX = x;
	realY = y;

	player->SetPosition(glm::vec3(realX, realY, 0));
}