#pragma once 
#include <vector>
#include <iostream>
#include "glad.h"

class VertexBuffer
{
public:
	VertexBuffer();
	~VertexBuffer();

	void BindData(float* vertices, unsigned int* indices, unsigned int indicesSize, unsigned int vertDataCount);
	unsigned int vao;
	unsigned int size;
	
	
private:

};

