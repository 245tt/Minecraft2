#include "glm/glm.hpp"
#include "World.h"
#include "BlockData.h"

struct RayCastResult
{
	glm::ivec3 blockPos;
	glm::ivec3 hitPos;
	//FaceDirection faceDirection;
	float distance;

};

void RayCastWorld(RayCastResult* result,glm::vec3 Direction,glm::vec3 startPosition);