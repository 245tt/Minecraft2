#pragma once
#include "glm/glm.hpp"


//
const glm::vec4 UVCoords[] = {
	glm::vec4(0),
	glm::vec4(0,0,0.0625,0.0625),
	glm::vec4(0.0625,0,0.125,0.0625),
};
static class TextureAtlas
{
private:

public:
	static glm::vec4 GetUVCoordsFromBlockID(unsigned int id);
};

