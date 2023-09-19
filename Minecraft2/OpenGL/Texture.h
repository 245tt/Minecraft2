#pragma once
#include <fstream>
#include <iostream>
#include "glad.h"
#include "stb_image.h"

class Texture
{
public:
	~Texture();
	Texture(const char* texturePath);
	void Use(GLenum textureUnit = GL_TEXTURE0);

	unsigned int id;
};

