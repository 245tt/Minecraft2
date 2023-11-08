#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "glfw3.h"
enum Camera_Movement 
{
	Forward,
	Back,
	Left,
	Right
};

class Camera
{
private:
	glm::vec3 rotation = glm::vec3(0.0f);
	float fov = 0;
	float aspectRatio = 0;
	float near = 0;
	float far = 0;
	glm::vec3 right;
	glm::vec3 up;
	void UpdateLookDir();
public:
	glm::vec3 front;
	Camera(float fov,float aspectRatio,float nearPlane,float farPlane);
	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix();
	void SetRotation(glm::vec3 rotation);
	void MoveCamera(Camera_Movement dir,float distance);
	glm::vec3 position = glm::vec3(0.0f);
};

