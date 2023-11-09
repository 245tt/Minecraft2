#pragma once
#include "glm/glm.hpp"
#include "Chunk.h"
#include "VoxelMesh.h"
#include "VoxelData.h"
#include "BlockData.h"
#include "TextureAtlas.h"
#include "../OpenGL/WorldVertexBuffer.h"
#include "World.h"
#include <vector>

static class ChunkBuilder
{
private:
	static void AddTopFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID);
	static void AddBottomFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID);
	static void AddNorthFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID);
	static void AddSouthFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID);
	static void AddWestFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID);
	static void AddEastFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID);

	static void GenerateMesh(Chunk* chunk, WorldVertexBuffer* worldBuf);
public:
	static void GenerateWorldMesh(World* world,std::vector<WorldVertexBuffer*>& buffers);
	static void UpdateChunkMesh(World* world, std::vector<WorldVertexBuffer*>& buffers);

	static inline int size=0;
};

