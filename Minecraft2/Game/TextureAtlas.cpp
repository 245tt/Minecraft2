#include "TextureAtlas.h"

glm::vec4 TextureAtlas::GetUVCoordsFromBlockID(unsigned int id)
{

    return UVCoords[id];
}
