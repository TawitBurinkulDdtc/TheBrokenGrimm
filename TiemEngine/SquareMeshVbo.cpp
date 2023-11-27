
#include "SquareMeshVbo.h"

string const SquareMeshVbo::MESH_NAME = "square";

void SquareMeshVbo::LoadData()
{
	//VBO data
	GLfloat vertexData[] =
	{
	  -0.5f, -0.5f,
	  0.5f, -0.5f,
	  0.5f,  0.5f,
	  -0.5f,  0.5f
	};

	GLfloat texData[] =
	{
	  0.0f, 0.0f,
	  1.0f, 0.0f,
	  1.0f, 1.0f,
	  0.0f, 1.0f
	};

	//Create VBO
	glGenBuffers(1, &(this->posVboId));
	glBindBuffer(GL_ARRAY_BUFFER, this->posVboId);
	glBufferData(GL_ARRAY_BUFFER, 2 * 4 * sizeof(GLfloat), vertexData, GL_STATIC_DRAW);

	glGenBuffers(1, &(this->texVboId));
	glBindBuffer(GL_ARRAY_BUFFER, this->texVboId);
	glBufferData(GL_ARRAY_BUFFER, 2 * 4 * sizeof(GLfloat), texData, GL_STATIC_DRAW);


}

void SquareMeshVbo::ResetUV() {
	if (isUVchange == true) {
		GLfloat texData[] =
		{
		  0.0f, 0.0f,
		  1.0f, 0.0f,
		  1.0f, 1.0f,
		  0.0f, 1.0f
		};
		glBindBuffer(GL_ARRAY_BUFFER, this->texVboId);
		glBufferData(GL_ARRAY_BUFFER, 2 * 4 * sizeof(GLfloat), texData, GL_STATIC_DRAW);

		isUVchange = false;
	}
	
}
void SquareMeshVbo::ChangeUV(float* newUV){
	GLfloat texData[8];

	for (int i = 0; i < 8; i++) {
		texData[i] = newUV[i];
	}

	glBindBuffer(GL_ARRAY_BUFFER, this->texVboId);
	glBufferData(GL_ARRAY_BUFFER, 2 * 4 * sizeof(GLfloat), texData, GL_STATIC_DRAW);

	isUVchange = true;
}
void SquareMeshVbo::Animation() {
	//GLfloat texData[48]; // Since there are 4x6 = 24 sprites, and each sprite has 2 UV coordinates (U and V), you need 48 elements in the texData array.

	//// Loop through rows and columns to calculate UV coordinates
	//for (int row = 0; row < 6; row++) {
	//	for (int col = 0; col < 4; col++) {
	//		// Calculate UV coordinates for the current sprite
	//		float left = static_cast<float>(col) / 4.0f; // Calculate the left U coordinate
	//		float right = static_cast<float>(col + 1) / 4.0f; // Calculate the right U coordinate
	//		float top = 1.0f - (static_cast<float>(row) / 6.0f); // Calculate the top V coordinate
	//		float bottom = 1.0f - (static_cast<float>(row + 1) / 6.0f); // Calculate the bottom V coordinate

	//		// Store the UV coordinates in the texData array
	//		// The order here is (left, bottom), (right, bottom), (right, top), (left, top)
	//		texData[(row * 4 + col) * 8] = left;
	//		texData[(row * 4 + col) * 8 + 1] = bottom;
	//		texData[(row * 4 + col) * 8 + 2] = right;
	//		texData[(row * 4 + col) * 8 + 3] = bottom;
	//		texData[(row * 4 + col) * 8 + 4] = right; 
	//		texData[(row * 4 + col) * 8 + 5] = top;
	//		texData[(row * 4 + col) * 8 + 6] = left;
	//		texData[(row * 4 + col) * 8 + 7] = top;
	//	}
	//}

}
SquareMeshVbo::SquareMeshVbo()
{}

string SquareMeshVbo::GetMeshName()
{
	return MESH_NAME;
}



void SquareMeshVbo::Render()
{
	if (this->posAttribId != -1) {
		glBindBuffer(GL_ARRAY_BUFFER, this->posVboId);
		glVertexAttribPointer(this->posAttribId, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), NULL);
	}
	if (this->texAttribId != -1) {
		glBindBuffer(GL_ARRAY_BUFFER, this->texVboId);
		glVertexAttribPointer(this->texAttribId, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), NULL);
	}
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}