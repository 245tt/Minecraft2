#include "MasterRenderer.h"

MasterRenderer::MasterRenderer()
{
	
	
}

MasterRenderer::~MasterRenderer()
{
}


void MasterRenderer::Draw(VertexBuffer* buffer,unsigned int shader)
{


	glUseProgram(shader);
	glBindVertexArray(buffer->vao);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glDrawElements(GL_TRIANGLES,buffer->size,GL_UNSIGNED_INT,0);

	//glDrawArrays(GL_TRIANGLES,0,buffer->size);
}

void MasterRenderer::DrawCubeMap(VertexBuffer* buffer,CubeMap* cubeMap, unsigned int shader)
{
	glDepthFunc(GL_LEQUAL);
	glUseProgram(shader);
	glBindVertexArray(buffer->vao);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP,cubeMap->id);
	
	glDrawElements(GL_TRIANGLES, buffer->size, GL_UNSIGNED_INT, 0);
	
	glDepthFunc(GL_LESS);
}

void MasterRenderer::Prepare()
{
	glClearColor(0.1,0.1,0.1,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
