
#include "GameObject.h"
#include "GameEngine.h"
#include "SquareMeshVbo.h"
#include "SpriteObject.h"

GameObject::GameObject()
{
	
}


GameObject::~GameObject()
{
}

void GameObject::UpdateFrame() {
	//CalculateUV(0,0);
	
}
void GameObject::SetTexture(string path)
{
	texture = GameEngine::GetInstance()->GetRenderer()->LoadTexture(path);
	textures.push_back(texture);
}

void GameObject::Render(glm::mat4 globalModelTransform)
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
		glUniform1i(renderModeId, renderMode);
		glBindTexture(GL_TEXTURE_2D, texture);
		squareMesh->ResetUV();
		squareMesh->Render();

	}
}

void GameObject::AddTextures(const char* path) {
	unsigned int tex = GameEngine::GetInstance()->GetRenderer()->LoadTexture(path);
	textures.push_back(tex);
}
void GameObject::ChangeTextures(int texIndex) {
	texture = textures[texIndex];
}

