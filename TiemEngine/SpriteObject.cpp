#include "SpriteObject.h"
#include "GameEngine.h"
#include "SquareMeshVbo.h"

SpriteObject::SpriteObject(const char* path,int MaxR, int MaxC) {
	this->row = row;
	this->col = col;
	MaxRow = MaxR;
	MaxCol = MaxC;
	texture = GameEngine::GetInstance()->GetRenderer()->LoadTexture(path);
	textures.push_back(texture);
	CalculateUV(0, 0);
}

void SpriteObject::updateAnimate() {
	if (animated) {

	}
}

void SpriteObject::CalculateUV(int r, int c) {
	
	float texData[8];
	//float texData[] = 
	//{
	//  /*0.0f / 10.0f, 3.0f / 4.0f,
	//  1.0f / 10.0f, 3.0f / 4.0f,
	//  1.0f / 10.0f, 4.0f / 4.0f,
	//  0.0f / 10.0f, 4.0f / 4.0f*/
	//};

	float rows = r;
	float column = c;

	// HARD CODING FOR NOW
	// CALCULATING 4 COORDINATES
	// #1
	texData[0] = column / MaxCol, texData[1] = ((MaxRow - rows) + 1 )/ MaxRow;
	// #2
	texData[2] = (column + 1.0f) / MaxCol, texData[3] = ((MaxRow - rows) + 1)  / MaxRow;
	// #3
	texData[4] = (column + 1.0f) / MaxCol, texData[5] = (MaxRow - rows) / MaxRow;
	// #4
	texData[6] = column / MaxCol, texData[7] = (MaxRow - rows) / MaxRow;

	/*for (int i = 0; i < 8; i++) {
		texData[i] = column / 10.0f;
		texData[i + 1] = rows / 4.0f;
	}*/
	
	for (int i = 0; i < 8; i++)
	{
		newUV[i] = texData[i];
	}
}

void SpriteObject::UpdateFrame() {

	frames++;
	if (frames > speed) {
		frames = 0;
		
		col++;
		CalculateUV(row, col);
	}
	
}

void SpriteObject::Render(glm::mat4 globalModelTransform)
{
	SquareMeshVbo* squareMesh = dynamic_cast<SquareMeshVbo*> (GameEngine::GetInstance()->GetRenderer()->GetMesh(SquareMeshVbo::MESH_NAME));

	GLuint modelMatixId = GameEngine::GetInstance()->GetRenderer()->GetModelMatrixAttrId();
	GLuint renderModeId = GameEngine::GetInstance()->GetRenderer()->GetModeUniformId();

	if (modelMatixId == -1) {
		cout << "Error: Can't perform transformation " << endl;
		return;
	}
	if (renderModeId == -1) {
		cout << "Error: Can't set renderMode in ImageObject " << endl;
		return;
	}

	vector <glm::mat4> matrixStack;

	glm::mat4 currentMatrix = this->getTransform();

	if (squareMesh != nullptr) {

		currentMatrix = globalModelTransform * currentMatrix;
		glUniformMatrix4fv(modelMatixId, 1, GL_FALSE, glm::value_ptr(currentMatrix));
		glUniform1i(renderModeId, 1);
		glBindTexture(GL_TEXTURE_2D, texture);

		//UpdateFrame();
		//CalculateUV(0, 2);

		squareMesh->ChangeUV(newUV);
		squareMesh->Render();
	}
}


