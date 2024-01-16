#pragma once
#include <cmath>
#include "glm/glm.hpp"
class Chunk
{
public:
	Chunk();
	
	void Populate();

	unsigned short blocks[32][32][32];
	glm::ivec3 position = {0,0,0};
	bool needsUpdate= false;
};

