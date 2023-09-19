#pragma once
#include<String>
#include "stb_image.h"
#include "glad.h"

class CubeMap
{
public:
	CubeMap(std::string texPaths[6]);
	unsigned int id;
};

