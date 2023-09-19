#pragma once
#include <vector>

class VoxelMesh{
public:
	std::vector<float> vertexPositions;
	std::vector<float> vertexTextureCoords;
	std::vector<float> faceBrightness;
	std::vector<unsigned int> indices;

	std::vector<float> GenVertexData();
};


