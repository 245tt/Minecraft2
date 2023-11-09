#include "World.h"

unsigned int World::GetBlockIdFromWorldCoords(glm::ivec3 pos)
{
	glm::ivec3 chunkPos = floor((glm::vec3)pos /= 32);
	Chunk* chunk = GetChunkFromWorldCoords(chunkPos);
	if (chunk == nullptr) 
	{
		return -1;
	}
	//chunk->needsUpdate = true;
	glm::ivec3 blockPos = pos - (chunkPos * 32);
	return chunk->blocks[blockPos.x][blockPos.y][blockPos.z];

}

void World::SetBlockOnWorldCoords(glm::ivec3 pos, int blockID)
{
	glm::ivec3 chunkPos = floor((glm::vec3)pos /= 32);
	Chunk* chunk = GetChunkFromWorldCoords(chunkPos);
	if (chunk != nullptr) {
		chunk->needsUpdate = true;
		glm::ivec3 blockPos = pos - (chunkPos*32);

		chunk->blocks[blockPos.x][blockPos.y][blockPos.z] = blockID;
	}
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
	return nullptr;
}

Chunk* World::LoadChunk(glm::ivec3 chunkPos)
{
	return nullptr;
}

Chunk* World::GenerateChunk(glm::ivec3 chunkPos)
{
	Chunk* chunk = new Chunk();
	chunk->position = chunkPos;
	chunk->position = chunkPos;
	chunk->Populate();
	activeChunks.push_back(chunk);
	return chunk;
}

void World::UnloadChunk(glm::ivec3 chunkPos)
{	
	for (int i = 0; i < activeChunks.size(); i++) 
	{
		if (chunkPos == activeChunks[i]->position) 
		{

			delete activeChunks[i];
			activeChunks.erase(activeChunks.begin()+i);
		}
	}
}
