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
	static void AddFrontFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID);
	static void AddBackFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID);
	static void AddLeftFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID);
	static void AddRightFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID);

public:
	static void GenerateMesh(Chunk* chunk,VoxelMesh* mesh);

	static inline int size=0;
};

