#pragma once
#include "Window.h"
#include "OpenGL\MasterRenderer.h"
#include "System/Input.h"
#include <chrono>

class Core
{
public:
	static Core GetInstance();
	
	//modules
	Window m_window;
	MasterRenderer m_renderer;
	void InitModules();
	void Run();

	//camera var
	float pitch;
	float yaw;
	bool firstMouse = false;
	float lastX;
	float lastY;

protected:
	static Core* singleton;
	double lastTime;
	double currentTime;


};
