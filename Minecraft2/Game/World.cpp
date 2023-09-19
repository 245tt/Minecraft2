#include "World.h"

unsigned int World::GetBlockIdFromWorldCoords(glm::ivec3 pos)
{
	glm::ivec3 chunkPos = floor((glm::vec3)pos /= 32);
	Chunk* chunk = GetChunkFromWorldCoords(chunkPos);
	glm::ivec3 blockPos = pos - chunkPos;

	return chunk->blocks[blockPos.x][blockPos.y][blockPos.z];
}

Chunk* World::GetChunkFromWorldCoords(glm::ivec3 pos)
{
	for (int i = 0; i < activeChunks.size(); i++) 
	{
		if (activeChunks[i]->position == pos) 
		{
			return activeChunks[i];
		}
	}
}
