#include "VoxelMesh.h"

std::vector<float> VoxelMesh::GenVertexData()
{
    int size = vertexPositions.size() / 3;
    
    std::vector<float>vdata;
    vdata.reserve(size * 6);

    for (int i = 0; i < size; i++)
    {

        //vertex positions
        vdata.push_back(vertexPositions[3*i]);
        vdata.push_back(vertexPositions[3*i+1]);
        vdata.push_back(vertexPositions[3*i+2]);

        //texture coordinates
        vdata.push_back(vertexTextureCoords[2*i]);
        vdata.push_back(vertexTextureCoords[2 * i+1]);

        //face brightness
        vdata.push_back(faceBrightness[i]);
    }
    return vdata;
}
