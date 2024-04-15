#include "TextObject.h"
#include "GameEngine.h"
#include "SquareMeshVbo.h"

TextObject::TextObject()
{
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}


TextObject::~TextObject()
{

}

void TextObject::Render(glm::mat4 globalModelTransform)
{
	SquareMeshVbo *squareMesh = dynamic_cast<SquareMeshVbo *> (GameEngine::GetInstance()->GetRenderer()->GetMesh(SquareMeshVbo::MESH_NAME));

	GLuint modelMatixId = GameEngine::GetInstance()->GetRenderer()->GetModelMatrixAttrId();
	GLuint modeId = GameEngine::GetInstance()->GetRenderer()->GetModeUniformId();

	glBindTexture(GL_TEXTURE_2D, texture);
	//glBindTexture(GL_TEXTURE_2D, texNum);
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	

	//glBindTexture(GL_TEXTURE_2D, texture);
	//cout << "Render\n";


	if (modelMatixId == -1) {
		cout << "Error: Can't perform transformation " << endl;
		return;
	}

	glm::mat4 currentMatrix = this->getTransform();

	if (squareMesh != nullptr) {

		currentMatrix = globalModelTransform * currentMatrix;
		glUniformMatrix4fv(modelMatixId, 1, GL_FALSE, glm::value_ptr(currentMatrix));
		glUniform1i(modeId, 1);
		//squareMesh->resetTexcoord();
		squareMesh->Render();
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}

void TextObject::Update(float deltaTime)
{
}

void TextObject::LoadText(string text, SDL_Color textColor, int fontSize)
{
	currentText = text;
	
	glBindTexture( GL_TEXTURE_2D, texture);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//TTF_Font * font = TTF_OpenFont("airstrikeexpand.ttf", fontSize);
	TTF_Font* font = TTF_OpenFont(fontFileName, fontSize);//Gabilo Display Demo.otf	//ShortBaby-Mg2w.ttf
	
	if (font)
	{
		SDL_Surface* surfaceMessage = TTF_RenderText_Blended(font, text.c_str(), textColor);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surfaceMessage->w, surfaceMessage->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surfaceMessage->pixels);
		this->SetSize(surfaceMessage->w, -surfaceMessage->h);
		SDL_FreeSurface(surfaceMessage);
		TTF_CloseFont(font);
	}
	else
	{
		cout << "Error: " << TTF_GetError() << endl;
		return;
	}
	
}


void TextObject::setFont(const char* fontLocation) {
	fontFileName = fontLocation;
}