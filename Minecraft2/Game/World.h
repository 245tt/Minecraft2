#pragma once
#include <vector>
#include "Chunk.h"

class World
{
	std::vector<Chunk*> activeChunks;
public: 
	unsigned int GetBlockIdFromWorldCoords(glm::ivec3 pos);
	Chunk* GetChunkFromWorldCoords(glm::ivec3 pos);
};

