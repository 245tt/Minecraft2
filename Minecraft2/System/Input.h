#pragma once
#include <map>
#include "glm/glm.hpp"
#include "glfw3.h"

namespace System
{
	enum KeyAction
	{
		Released = 0,
		Pressed = 1,
		Holded = 2,
	};


	static class Input
	{
	public:
		static KeyAction GetKey(int Key);
		static void SetKey(int Key, KeyAction action);
		static bool IsKeyDown(int Key);
		static bool IsKeyPressed(int Key);
		static bool IsKeyDown(char key);
		static bool IsKeyPressed(char key);
		static void UpdateMousePos(float xPos, float yPos);
		static void Init();
		inline static glm::vec2 mouseDelta;

	private:
		inline static std::map<int, KeyAction> keyState;
		inline static glm::vec2 mousePos;
		//inline static glm::vec2 mousePosNorm; maybe later
		inline static bool firstMove = true;
		inline static glm::vec2 lastPos;
	};
}

