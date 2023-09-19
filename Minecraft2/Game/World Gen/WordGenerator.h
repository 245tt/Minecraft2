#pragma once
#include "../Chunk.h"
#include "glm/glm.hpp"
class WordGenerator
{
	WordGenerator(int seed);
public:
	Chunk GenerateChunk(glm::ivec3 chunkPos);

private:
	int seed;
};

