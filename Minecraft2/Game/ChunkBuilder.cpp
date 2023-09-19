#include "ChunkBuilder.h"

void ChunkBuilder::AddTopFace(glm::i32vec3 blockPos, VoxelMesh* mesh,unsigned int blockID)
{
	glm::vec4 uvCoords = TextureAtlas::GetUVCoordsFromBlockID(blockID);

	float texCoords[8] = 
	{
		uvCoords[0],uvCoords[1],
		uvCoords[0],uvCoords[3],
		uvCoords[2],uvCoords[1],
		uvCoords[2],uvCoords[3]
	};
	int i = 0;
	//loop adds face to mesh vertex Data
	for (int x = 0; x < 12; x+=3)
	{
		//one vertex added to vector
		mesh->vertexPositions.push_back(topFace[x] + blockPos.x);
		mesh->vertexPositions.push_back(topFace[x+1] + blockPos.y);
		mesh->vertexPositions.push_back(topFace[x+2 ] + blockPos.z);

		//and its uv maps
		
		mesh->vertexTextureCoords.push_back(texCoords[i+0]);
		mesh->vertexTextureCoords.push_back(texCoords[i+1]);
		i += 2;
	}
	//adding indices

	//first triangle
	mesh->indices.push_back(size); 
	mesh->indices.push_back(size+1);
	mesh->indices.push_back(size+2);

	//second
	mesh->indices.push_back(size+1);
	mesh->indices.push_back(size + 2);
	mesh->indices.push_back(size + 3);

	size = size + 4;
}

void ChunkBuilder::AddBottomFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID)
{
	glm::vec4 uvCoords = TextureAtlas::GetUVCoordsFromBlockID(blockID);

	float texCoords[8] =
	{
		uvCoords[0],uvCoords[1],
		uvCoords[0],uvCoords[3],
		uvCoords[2],uvCoords[1],
		uvCoords[2],uvCoords[3]
	};
	int i = 0;
	//loop adds face to mesh vertex Data
	for (int x = 0; x < 12; x += 3)
	{
		//one vertex added to vector
		mesh->vertexPositions.push_back(bottomFace[x] + blockPos.x);
		mesh->vertexPositions.push_back(bottomFace[x + 1] + blockPos.y);
		mesh->vertexPositions.push_back(bottomFace[x + 2] + blockPos.z);

		//and its uv maps
		mesh->vertexTextureCoords.push_back(texCoords[i + 0]);
		mesh->vertexTextureCoords.push_back(texCoords[i + 1]);
		i += 2;
	}
	//adding indices

	//first triangle
	mesh->indices.push_back(size);
	mesh->indices.push_back(size + 1);
	mesh->indices.push_back(size + 2);

	//second
	mesh->indices.push_back(size + 1);
	mesh->indices.push_back(size + 2);
	mesh->indices.push_back(size + 3);

	size = size + 4;
}

void ChunkBuilder::AddFrontFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID)
{
	glm::vec4 uvCoords = TextureAtlas::GetUVCoordsFromBlockID(blockID);

	float texCoords[8] =
	{
		uvCoords[0],uvCoords[1],
		uvCoords[0],uvCoords[3],
		uvCoords[2],uvCoords[1],
		uvCoords[2],uvCoords[3]
	};

	int i = 0;
	//loop adds face to mesh vertex Data
	for (int x = 0; x < 12; x += 3)
	{
		//one vertex added to vector
		mesh->vertexPositions.push_back(frontFace[x] + blockPos.x);
		mesh->vertexPositions.push_back(frontFace[x + 1] + blockPos.y);
		mesh->vertexPositions.push_back(frontFace[x + 2] + blockPos.z);

		//and its uv maps
		mesh->vertexTextureCoords.push_back(texCoords[i + 0]);
		mesh->vertexTextureCoords.push_back(texCoords[i + 1]);
		i += 2;
	}
	//adding indices

	//first triangle
	mesh->indices.push_back(size);
	mesh->indices.push_back(size + 1);
	mesh->indices.push_back(size + 2);

	//second
	mesh->indices.push_back(size + 1);
	mesh->indices.push_back(size + 2);
	mesh->indices.push_back(size + 3);

	size = size + 4;
}

void ChunkBuilder::AddBackFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID)
{
	glm::vec4 uvCoords = TextureAtlas::GetUVCoordsFromBlockID(blockID);

	float texCoords[8] =
	{
		uvCoords[0],uvCoords[1],
		uvCoords[0],uvCoords[3],
		uvCoords[2],uvCoords[1],
		uvCoords[2],uvCoords[3]
	};
	int i = 0;
	//loop adds face to mesh vertex Data
	for (int x = 0; x < 12; x += 3)
	{
		//one vertex added to vector
		mesh->vertexPositions.push_back(backFace[x] + blockPos.x);
		mesh->vertexPositions.push_back(backFace[x + 1] + blockPos.y);
		mesh->vertexPositions.push_back(backFace[x + 2] + blockPos.z);

		//and its uv maps
		mesh->vertexTextureCoords.push_back(texCoords[i + 0]);
		mesh->vertexTextureCoords.push_back(texCoords[i + 1]);
		i += 2;
	}
	//adding indices

	//first triangle
	mesh->indices.push_back(size);
	mesh->indices.push_back(size + 1);
	mesh->indices.push_back(size + 2);

	//second
	mesh->indices.push_back(size + 1);
	mesh->indices.push_back(size + 2);
	mesh->indices.push_back(size + 3);

	size = size + 4;
}

void ChunkBuilder::AddLeftFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID)
{
	glm::vec4 uvCoords = TextureAtlas::GetUVCoordsFromBlockID(blockID);

	float texCoords[8] =
	{
		uvCoords[0],uvCoords[1],
		uvCoords[0],uvCoords[3],
		uvCoords[2],uvCoords[1],
		uvCoords[2],uvCoords[3]
	};
	int i = 0;
	//loop adds face to mesh vertex Data
	for (int x = 0; x < 12; x += 3)
	{
		//one vertex added to vector
		mesh->vertexPositions.push_back(leftFace[x] + blockPos.x);
		mesh->vertexPositions.push_back(leftFace[x + 1] + blockPos.y);
		mesh->vertexPositions.push_back(leftFace[x + 2] + blockPos.z);

		//and its uv maps
		mesh->vertexTextureCoords.push_back(texCoords[i + 0]);
		mesh->vertexTextureCoords.push_back(texCoords[i + 1]);
		i += 2;
	}
	//adding indices

	//first triangle
	mesh->indices.push_back(size);
	mesh->indices.push_back(size + 1);
	mesh->indices.push_back(size + 2);

	//second
	mesh->indices.push_back(size + 1);
	mesh->indices.push_back(size + 2);
	mesh->indices.push_back(size + 3);

	size = size + 4;
}

void ChunkBuilder::AddRightFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID)
{
	glm::vec4 uvCoords = TextureAtlas::GetUVCoordsFromBlockID(blockID);

	float texCoords[8] =
	{
		uvCoords[0],uvCoords[1],
		uvCoords[0],uvCoords[3],
		uvCoords[2],uvCoords[1],
		uvCoords[2],uvCoords[3]
	};
	int i = 0;
	//loop adds face to mesh vertex Data
	for (int x = 0; x < 12; x += 3)
	{
		//one vertex added to vector
		mesh->vertexPositions.push_back(rightFace[x] + blockPos.x);
		mesh->vertexPositions.push_back(rightFace[x + 1] + blockPos.y);
		mesh->vertexPositions.push_back(rightFace[x + 2] + blockPos.z);

		//and its uv maps
		mesh->vertexTextureCoords.push_back(texCoords[i + 0]);
		mesh->vertexTextureCoords.push_back(texCoords[i + 1]);
		i += 2;
	}
	//adding indices

	//first triangle
	mesh->indices.push_back(size);
	mesh->indices.push_back(size + 1);
	mesh->indices.push_back(size + 2);

	//second
	mesh->indices.push_back(size + 1);
	mesh->indices.push_back(size + 2);
	mesh->indices.push_back(size + 3);

	size = size + 4;
}

void ChunkBuilder::GenerateMesh(Chunk* chunk, VoxelMesh* mesh)
{
	for (int x = 0; x < 32; x++)
	{
		for (int y = 0; y < 32; y++)
		{
			for (int z = 0; z < 32; z++)
			{
				if (chunk->blocks[x][y][z] != 0) 
				{
					if (y > 30 ){ //to prevent array out of bounds error
						AddTopFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
						}
					else {
						if (!BlockList[chunk->blocks[x][y + 1][z]].opaque) {
							AddTopFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
						}
					}

					if (y < 1) { //to prevent array out of bounds error
						AddBottomFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
					}
					else {
						if (!BlockList[chunk->blocks[x][y -1][z]].opaque) {
							AddBottomFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
						}
					}
					
					if (z > 30) { //to prevent array out of bounds error
						AddFrontFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
					}
					else {
						if (!BlockList[chunk->blocks[x][y][z+1]].opaque) {
							AddFrontFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
						}
					}
						
					if (z < 1) { //to prevent array out of bounds error
						AddBackFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
					}
					else {
						if (!BlockList[chunk->blocks[x][y][z - 1]].opaque) {
							AddBackFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
						}
					}
					

					if (z > 30) { //to prevent array out of bounds error
						AddFrontFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
					}
					else {
						if (!BlockList[chunk->blocks[x][y][z+1]].opaque) {
							AddFrontFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
						}
					}
						
					if (z < 1) { //to prevent array out of bounds error
						AddBackFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
					}
					else {
						if (!BlockList[chunk->blocks[x][y][z - 1]].opaque) {
							AddBackFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
						}
					}
					
					if (x > 30) { //to prevent array out of bounds error
						AddRightFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
					}
					else {
						if (!BlockList[chunk->blocks[x+1][y][z ]].opaque) {
							AddRightFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
						}
					}

					if (x < 1) { //to prevent array out of bounds error
						AddLeftFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
					}
					else {
						if (!BlockList[chunk->blocks[x-1][y][z]].opaque) {
							AddLeftFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
						}
					}
				}
			}
		}
	}
}
