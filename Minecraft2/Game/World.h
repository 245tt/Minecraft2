#pragma once
#include <vector>
#include "Chunk.h"
#include <iostream>

class World
{
public: 
	std::vector<Chunk*> activeChunks;
	unsigned int GetBlockIdFromWorldCoords(glm::ivec3 pos);
	void SetBlockOnWorldCoords(glm::ivec3 pos,int blockID);
	Chunk* GetChunkFromWorldCoords(glm::ivec3 pos);
	Chunk* LoadChunk(glm::ivec3 chunkPos);
	Chunk* GenerateChunk(glm::ivec3 chunkPos);
	void UnloadChunk(glm::ivec3 chunkPos);
};

