#include "Input.h"

using namespace System;

KeyAction Input::GetKey(int Key)
{
	for (auto& [key, value] : keyState)
		if (key == Key)
			return value;
}

void Input::SetKey(int Key, KeyAction action)
{
	for (auto& [key, value] : keyState)
		if (key == Key)
			value = action;
}

bool System::Input::IsKeyDown(int Key)
{
	for (auto& [key, value] : keyState)
		if (key == Key && (value == KeyAction::Pressed || value == KeyAction::Holded))
			return true;

	return false;
}

bool System::Input::IsKeyPressed(int Key)
{
	for (auto& [key, value] : keyState)
		if (key == Key && value == KeyAction::Pressed)
			return true;
	return false;
}

bool System::Input::IsKeyDown(char key)
{
	return false;
}

bool System::Input::IsKeyPressed(char key)
{
	return false;
}

void Input::UpdateMousePos(float xPos, float yPos)
{
	if (firstMove) 
	{
		lastPos = glm::vec2(xPos,yPos);
		firstMove = false;
	}

	mousePos = glm::vec2( xPos,yPos );

	mouseDelta = mousePos - lastPos;

	lastPos = mousePos;

}


void Input::Init()
{
	//populate keyState dictonary
	for (int i = 0; i < 349; i++) 
	{
		keyState.insert({i,KeyAction::Released});
	}
}
