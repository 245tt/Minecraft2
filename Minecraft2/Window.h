#pragma once
#include "glad.h"
#include "glfw3.h"
#include <iostream>
#include "System/Input.h"


class Window
{
public:
	Window();
	~Window();


	void Init();
	void Update();
	void SwapBuffer();

	bool active = true;
	
	//camera var s
	inline static float pitch = 0;
	inline static float yaw = -90;
	inline static bool firstMouse = false;
	inline static float lastX = 0;
	inline static float lastY = 0;

	float posX = 0;
	float posY = 0;
	float posZ = 0;

	bool front = 0 ;
	bool back  = 0;
	bool right = 0 ;
	bool left  = 0;
private:
	//void WindowResized(GLFWwindow* window, int width, int height);
	//void ProcessInput(GLFWwindow* window);
	
protected:
	//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
public:
	GLFWwindow* window;
};

//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
//void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);
