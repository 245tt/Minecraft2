#include "Window.h"
Window::Window()
{
	window = nullptr;
	active = false;
}

Window::~Window()
{
	glfwTerminate();
}


void WindowResized(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}





void key_callback(GLFWwindow* window, int Key, int scancode, int action, int mods) 
{
	//std::cout << scancode << ", "<< action << std::endl;
	
	System::KeyAction keyAction = System::Input::GetKey(Key);
	
	
	if (action == 0) {
		keyAction = System::KeyAction::Released;
		
	}
	else if (action == 1) {
		keyAction = System::KeyAction::Pressed;
		
	}
	else if (action == 2) {
		keyAction = System::KeyAction::Holded;
		
	}
	
	//std::cout << glfwGetKeyName(Key,-1) << ", " << keyAction << std::endl;
	
	System::Input::SetKey(Key,keyAction);
}

void Window::Init() 
{
	std::cout << "Creating window!" << std::endl;
	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,6);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1600,900,"Hello Window",NULL,NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window"<< std::endl;
		glfwTerminate();
	}

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);
	glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
	glfwSetFramebufferSizeCallback(window, WindowResized); // window resize event
	glfwSetKeyCallback(window,key_callback);

	glfwMakeContextCurrent(window); //creating opengl context

	glfwSwapInterval(1);
	//initializing glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}

	//getting render data
	const GLubyte* vendor = glGetString(GL_VENDOR); //gpu manufacturer
	const GLubyte* renderer = glGetString(GL_RENDERER); //gpu name
	const GLubyte* OGLversion = glGetString(GL_VERSION); //opengl version
	
	std::cout << vendor << std::endl;
	std::cout << renderer << std::endl;
	std::cout << OGLversion << std::endl;
	glViewport(0, 0, 1600, 900);
	glEnable(GL_DEPTH_TEST);
	active = true;
}


void Window::Update()
{
	active = !glfwWindowShouldClose(window);
	glfwPollEvents();

	//mouse and key input
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	System::Input::UpdateMousePos(xpos, ypos);

	if (System::Input::IsKeyDown(87)) //w
	{
		front = true;
	}
	else front = false;

	if (System::Input::IsKeyDown(83))//s
	{
		back = true;
	}
	else back = false;

	if (System::Input::IsKeyDown(65))//a
	{
		left = true;
	}
	else left = false;

	if (System::Input::IsKeyDown(68))//d
	{
		right = true;
	}
	else right = false;

	yaw += System::Input::mouseDelta.x* 0.05f;
	pitch -= System::Input::mouseDelta.y * 0.05f;

}
	
void Window::SwapBuffer() 
{
	glfwSwapBuffers(window);
	glFinish();
}
