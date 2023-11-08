#pragma once
#include "glm/glm.hpp"
#include "Chunk.h"
#include "VoxelMesh.h"
#include "VoxelData.h"
#include "BlockData.h"
#include "TextureAtlas.h"

static class ChunkBuilder
{
private:
	static void AddTopFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID);
	static void AddBottomFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID);
	static void AddNorthFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID);
	static void AddSouthFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID);
	static void AddWestFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID);
	static void AddEastFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID);

public:
	static void GenerateMesh(Chunk* chunk,VoxelMesh* mesh);

	static inline int size=0;
};

