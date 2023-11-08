#pragma once
#include "VertexBuffer.h"
#include "CubeMap.h"
#include "Shader.h"

class MasterRenderer
{
public:
	MasterRenderer();
	~MasterRenderer();

	void Draw(int vao, int size,unsigned int shader);
	void DrawCubeMap(VertexBuffer* buffer, CubeMap* cubeMap,unsigned int shader);
	void Prepare();
private:
};
