#pragma once

#include "MeshVbo.h"

class SquareMeshVbo : public MeshVbo {
protected:

public:
	static string const MESH_NAME; 
	bool isUVchange = false;
	SquareMeshVbo(); //constructor
	virtual string GetMeshName();
	virtual void Render();
	virtual void LoadData();
	virtual void Animation();
	void ChangeUV(float* newUV);
	void ResetUV();
};