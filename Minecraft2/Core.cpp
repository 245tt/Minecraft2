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

    Chunk chunk;
    chunk.Populate();

    VoxelMesh mesh;

    ChunkBuilder builder;
    builder.GenerateMesh(&chunk,&mesh);
	

    VertexBuffer* buffer = new VertexBuffer();
    VertexBuffer* cube = new VertexBuffer();

	std::vector<float> meshData = mesh.GenVertexData();
    buffer->BindData(&meshData[0], &mesh.indices[0], mesh.indices.size(), meshData.size());
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
        
        
        if (m_window.front) camera->MoveCamera(Forward, 0.1);
        if (m_window.back) camera->MoveCamera(Back,     0.1);
        if (m_window.left) camera->MoveCamera(Left,     0.1);
        if (m_window.right) camera->MoveCamera(Right,   0.1);

		//std::cout << camera->position.x << ", " << camera->position.y << ", " << camera->position.z << std::endl;
        
        glm::mat4 model = glm::mat4(1.0f);
        camera->SetRotation(glm::vec3(m_window.pitch, m_window.yaw,0));

        glm::mat4 mvp = camera->GetProjectionMatrix() * camera->GetViewMatrix() * model;
        texture->Use();
		shader->Use();
        shader->SetMat4("mvp", mvp);

		skyboxShader->Use();
		skyboxShader->SetMat4("projection",camera->GetProjectionMatrix());
		skyboxShader->SetMat4("view", glm::mat4(glm::mat3(camera->GetViewMatrix())));
		m_renderer.Prepare();
        m_renderer.Draw(buffer, shader->id);
		m_renderer.DrawCubeMap(cube,skybox, skyboxShader->id);

        m_window.Update();
        m_window.SwapBuffer();
    }

    return;
}
