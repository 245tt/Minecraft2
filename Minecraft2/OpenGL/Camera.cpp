#include "Camera.h"

Camera::Camera(float fov, float aspectRatio, float nearPlane, float farPlane)
{
	this->fov = fov;
	this->aspectRatio = aspectRatio;
	this->near = nearPlane;
	this->far = farPlane;
	front = glm::vec3(0);
	up = glm::vec3(0);;
	right = glm::vec3(0);
}

glm::mat4 Camera::GetViewMatrix()
{


	UpdateLookDir();
	return glm::lookAt(this->position,this->position + front, glm::vec3(0, 1.0, 0));
}

glm::mat4 Camera::GetProjectionMatrix()
{

	return glm::perspective(glm::radians(this->fov),this->aspectRatio,this->near,this->far);
}

void Camera::SetRotation(glm::vec3 rotation)
{
	this->rotation = rotation;
}

void Camera::MoveCamera(Camera_Movement dir,float distance)
{
	switch (dir)
	{
	case Forward:
		position += front * distance;
		break;
	case Back:
		position -= front * distance;
		break;
	case Left:
		position -= right * distance;
		break;
	case Right:
		position += right * distance;
		break;
	}
}

void Camera::UpdateLookDir()
{
	front.x = cos(glm::radians(rotation.y)) * cos(glm::radians(rotation.x));
	front.y = sin(glm::radians(rotation.x));
	front.z = sin(glm::radians(rotation.y)) * cos(glm::radians(rotation.x));
	front = glm::normalize(front);

	right = glm::normalize(glm::cross(front,glm::vec3(0,1,0)));
	up = glm::normalize(glm::cross(front,right));
}
