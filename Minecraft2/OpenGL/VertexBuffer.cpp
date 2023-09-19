#include "VertexBuffer.h"

VertexBuffer::VertexBuffer()
{
	this->vao = 0;
	this->size = 0;
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1,&vao);
}
/*
float v_vertices[] =
{
	//X    Y      Z		R  G  B		   U  V
	//front face
	-1.0,1.0, 1.0,  0.0,0.0,
	1.0,1.0,  1.0,  1.0,0.0,
	-1.0,-1.0,1.0,	0.0,1.0,
	1.0,-1.0, 1.0,  1.0,1.0,

	//back
	-1.0,1.0, -1.0,  0.0,0.0,
	1.0,1.0,  -1.0,  1.0,0.0,
	-1.0,-1.0,-1.0,	0.0,1.0,
	1.0,-1.0, -1.0,  1.0,1.0,

	//bottom
	-1.0,-1.0, 1.0,  0.0,0.0,
	1.0,-1.0,  1.0,  1.0,0.0,
	-1.0,-1.0,-1.0,	0.0,1.0,
	1.0,-1.0, -1.0,  1.0,1.0,

	//top
	-1.0, 1.0, 1.0,  0.0,0.0,
	1.0,  1.0,  1.0, 1.0,0.0,
	-1.0, 1.0,-1.0,	 0.0,1.0,
	1.0,  1.0, -1.0, 1.0,1.0,

	//left
	-1.0,-1.0,1.0,  0.0,0.0,
	-1.0,1.0,1.0,	 1.0,0.0,
	-1.0,-1.0,-1.0, 0.0,1.0,
	-1.0,1.0,-1.0, 1.0,1.0,

	//right
	1.0,-1.0,1.0,  0.0,0.0,
	1.0,1.0,1.0, 1.0,0.0,
	1.0,-1.0,-1.0, 0.0,1.0,
	1.0,1.0,-1.0, 1.0,1.0,

};
unsigned int v_indices[] =
{
	//front
	0,1,2,
	1,2,3,


	//back
	4,5,6,
	5,6,7,

	//bottom
	8,9,10,
	9,10,11,

	//top
	12,13,14,
	13,14,15,

	//left
	16,17,18,
	17,18,19,

	//right
	20,21,22,
	21,22,23,

};
*/
void VertexBuffer::BindData(float* vertices, unsigned int* indices,unsigned int indicesSize,unsigned int vertDataCount)
{
	unsigned int vbo,ebo;	

	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);

	glGenBuffers(1,&vbo);
	glGenBuffers(1,&ebo);

	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);

	glBufferData(GL_ARRAY_BUFFER, vertDataCount*sizeof(float), &vertices[0], GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize *sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
	//vertex pos
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*)(0 * sizeof(float)));
	glEnableVertexAttribArray(0);

	//vertex texture coords
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER,0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	
	glDeleteBuffers(1,&vbo);
	glDeleteBuffers(1,&ebo);
	this->size = indicesSize;
	std::cout << "created buffer size of: " << size << std::endl;
}