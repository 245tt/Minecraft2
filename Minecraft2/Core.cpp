#include "Core.h"
#include "OpenGL/Shader.h"
#include "OpenGL/Camera.h"
#include "OpenGL/Texture.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Game/Chunk.h"
#include "Game/ChunkBuilder.h"
#include "Game/VoxelMesh.h"
#include "Game/World.h"
#include "Game/WorldRayCast.h"
#include "OpenGL/WorldVertexBuffer.h"
#include <thread>

float v_vertices[] =
{
	//X    Y    Z    U  V
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

Core Core::GetInstance() 
{
	if (singleton == nullptr) 
	{
		singleton = new Core();
	}
	return *singleton;
}

Core* Core::singleton = nullptr;

void Core::InitModules() 
{
	m_window.Init();
	System::Input::Init();
}



void Core::Run() 
{


	World world;
	//world.GenerateChunk({0,0,0});
	//world.GenerateChunk({ 0,0,1 });
	for (size_t x = 0; x < 10; x++)
	{
		for (size_t z = 0; z < 10; z++)
		{
			world.GenerateChunk({ x,0,z });
			//world.GenerateChunk({ x,1,z });
		}
	}
    //Chunk chunk;
    //chunk.Populate();

    ChunkBuilder builder;
	

    //WorldVertexBuffer* buffer = new WorldVertexBuffer();
    VertexBuffer* cube = new VertexBuffer();
	std::vector<WorldVertexBuffer*> worldBuffers;

    builder.GenerateWorldMesh(&world, worldBuffers);

	//std::vector<float> meshData = mesh.GenVertexData();
    //buffer->BindData(&meshData[0], &mesh.indices[0], mesh.indices.size(), meshData.size());
    cube->BindData(v_vertices, v_indices,sizeof(v_indices)/sizeof(v_indices[0]), sizeof(v_vertices) / sizeof(v_vertices[0]));

    Camera* camera = new Camera(90, 16.0f/9 ,0.1f,10000.0f);
    camera->position = glm::vec3(0.0,0.0,2.0);
    Shader* shader = new Shader("Resources/Shaders/final.vert","Resources/Shaders/final.frag");
    shader->Use();
    Texture* texture = new Texture("Resources/Textures/TextureAtlas.png");
	
	//setup skybox
	Shader* skyboxShader = new Shader("Resources/Shaders/cubeMap.vert","Resources/Shaders/cubeMap.frag");
	CubeMap* skybox = new CubeMap(new std::string[6] {
		"Resources/Textures/Skybox/posx.jpg",
		"Resources/Textures/Skybox/negx.jpg",
		"Resources/Textures/Skybox/posy.jpg",
		"Resources/Textures/Skybox/negy.jpg",
		"Resources/Textures/Skybox/posz.jpg",
		"Resources/Textures/Skybox/negz.jpg" });


    while (m_window.active) {
        
		currentTime = glfwGetTime();
		double delta = currentTime - lastTime;
		lastTime = currentTime;

		

        if (m_window.front) camera->MoveCamera(Forward, 10* delta);
        if (m_window.back) camera->MoveCamera(Back,     10* delta);
        if (m_window.left) camera->MoveCamera(Left,     10* delta);
        if (m_window.right) camera->MoveCamera(Right,   10* delta);

		RayCastResult result;
		RayCastWorld(&result,camera->front,camera->position,&world,5.0f);
		if (System::Input::IsKeyPressed(72)) 
		{
			//std::cout << result.hitPos.x << " " << result.hitPos.x << " " << result.hitPos.x << std::endl;
		}
		if (glfwGetKey(m_window.window, 72) == GLFW_PRESS && result.hit)
		{
			std::cout << "breaking block" << std::endl;
			glm::ivec3 pos = result.blockPos;
			world.SetBlockOnWorldCoords(pos, 0);
			auto t0 = std::chrono::high_resolution_clock::now();
			builder.UpdateChunkMesh(&world,worldBuffers);
			auto t1 = std::chrono::high_resolution_clock::now();

			std::chrono::duration< double > fs = t1 - t0;
			std::chrono::milliseconds d = std::chrono::duration_cast<std::chrono::milliseconds>(fs);

			std::cout << fs.count() << "s\n";
			std::cout << d.count() << "ms\n";
			//std::vector<float> meshData = mesh.GenVertexData();
			//buffer->BindData(&meshData[0], &mesh.indices[0], mesh.indices.size(), meshData.size());
		}

		if (glfwGetKey(m_window.window, 67) == GLFW_PRESS && result.hit)
		{
			//std::cout << FaceToString(result.faceDirection) << std::endl;
			glm::ivec3 target = result.blockPos + FaceToDir(result.faceDirection);
			world.SetBlockOnWorldCoords(target, 2);
			builder.UpdateChunkMesh(&world, worldBuffers);
		}
        glm::mat4 model = glm::mat4(1.0f);
        camera->SetRotation(glm::vec3(m_window.pitch, m_window.yaw,0));

        glm::mat4 mvp = camera->GetProjectionMatrix() * camera->GetViewMatrix() * model;
        texture->Use();
		shader->Use();
        shader->SetMat4("mvp", mvp);

		skyboxShader->Use();
		skyboxShader->SetMat4("projection",camera->GetProjectionMatrix());
		skyboxShader->SetMat4("view", camera->GetViewMatrix());
		m_renderer.Prepare();
		m_renderer.DrawCubeMap(cube,skybox, skyboxShader->id);
        //m_renderer.Draw(buffer->vao,buffer->size, shader->id);
		for (int i = 0; i < worldBuffers.size(); i++) 
		{
			model = glm::mat4(1.0f);
			model = glm::translate(model,(glm::vec3)(world.activeChunks[i]->position*32));
			glm::mat4 mvp = camera->GetProjectionMatrix() * camera->GetViewMatrix() * model;
			shader->SetMat4("mvp", mvp);
			m_renderer.Draw(worldBuffers[i]->vao, worldBuffers[i]->size, shader->id);
		}

        m_window.Update();
        m_window.SwapBuffer();
    }

    return;
}
