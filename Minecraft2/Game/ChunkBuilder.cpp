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

		mesh->faceBrightness.push_back(1.0f);

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

		mesh->faceBrightness.push_back(.2f);
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

void ChunkBuilder::AddNorthFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID)
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

		mesh->faceBrightness.push_back(0.6f);
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

void ChunkBuilder::AddSouthFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID)
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

		mesh->faceBrightness.push_back(0.6f);
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

void ChunkBuilder::AddWestFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID)
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

		mesh->faceBrightness.push_back(0.4f);
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

void ChunkBuilder::AddEastFace(glm::i32vec3 blockPos, VoxelMesh* mesh, unsigned int blockID)
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

		mesh->faceBrightness.push_back(0.4f);
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

void ChunkBuilder::UpdateChunkMesh(World* world, std::vector<WorldVertexBuffer*>& buffers) 
{
	for (int i = 0; i < world->activeChunks.size(); i++)
	{
		if (world->activeChunks[i]->needsUpdate) {
			
			GenerateMesh(world->activeChunks[i], buffers[i]);
			world->activeChunks[i]->needsUpdate = false;
		}
	}
}


void ChunkBuilder::GenerateMesh(Chunk* chunk,WorldVertexBuffer* worldBuf)
{
	VoxelMesh* mesh = new VoxelMesh();

	mesh->faceBrightness.clear();
	mesh->indices.clear();
	mesh->vertexPositions.clear();
	mesh->vertexTextureCoords.clear();
	size = 0;
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
						AddNorthFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
					}
					else {
						if (!BlockList[chunk->blocks[x][y][z+1]].opaque) {
							AddNorthFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
						}
					}
						
					if (z < 1) { //to prevent array out of bounds error
						AddSouthFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
					}
					else {
						if (!BlockList[chunk->blocks[x][y][z - 1]].opaque) {
							AddSouthFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
						}
					}
					

					//if (z > 30) { //to prevent array out of bounds error
					//	AddNorthFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
					//}
					//else {
					//	if (!BlockList[chunk->blocks[x][y][z+1]].opaque) {
					//		AddNorthFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
					//	}
					//}
					//	
					//if (z < 1) { //to prevent array out of bounds error
					//	AddSouthFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
					//}
					//else {
					//	if (!BlockList[chunk->blocks[x][y][z - 1]].opaque) {
					//		AddSouthFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
					//	}
					//}
					
					if (x > 30) { //to prevent array out of bounds error
						AddEastFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
					}
					else {
						if (!BlockList[chunk->blocks[x+1][y][z ]].opaque) {
							AddEastFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
						}
					}

					if (x < 1) { //to prevent array out of bounds error
						AddWestFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
					}
					else {
						if (!BlockList[chunk->blocks[x-1][y][z]].opaque) {
							AddWestFace(glm::i32vec3(x, y, z), mesh, chunk->blocks[x][y][z]);
						}
					}
				}
			}
		}
	}
	std::vector<float> meshData = mesh->GenVertexData();
	worldBuf->BindData(&meshData[0], &mesh->indices[0], mesh->indices.size(), meshData.size());
	delete mesh;
}

void ChunkBuilder::GenerateWorldMesh(World* world, std::vector<WorldVertexBuffer*>& buffers)
{
	for (int i = 0; i < buffers.size(); i++) 
	{
		delete buffers[i];
	}
	buffers.clear();
	buffers.reserve(world->activeChunks.size());
	for (int i = 0; i < world->activeChunks.size();i++) 
	{
		WorldVertexBuffer* buf = new WorldVertexBuffer();
		GenerateMesh(world->activeChunks[i], buf);
		buffers.push_back(buf);
	}

}
