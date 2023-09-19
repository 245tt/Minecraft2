#include "VoxelMesh.h"

std::vector<float> VoxelMesh::GenVertexData()
{

    std::vector<float>vdata;

    for (int i = 0; i < vertexPositions.size()/3; i++) 
    {

        //vertex positions
        vdata.push_back(vertexPositions[3*i]);
        vdata.push_back(vertexPositions[3*i+1]);
        vdata.push_back(vertexPositions[3*i+2]);

        //texture coordinates
        vdata.push_back(vertexTextureCoords[2*i]);
        vdata.push_back(vertexTextureCoords[2 * i+1]);

        //face brightness
        //vdata.push_back(faceBrightness[i]);
    }
    std::vector<float>data(vdata);
    return vdata;
}
