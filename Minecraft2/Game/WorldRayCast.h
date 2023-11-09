#pragma once
#include "glm/glm.hpp"
#include "World.h"
#include "BlockData.h"
//#include <iostream>

#define STEP 0.1f


struct RayCastResult
{
	bool hit;
	glm::ivec3 blockPos;
	glm::vec3 hitPos;
	FaceDirection faceDirection;
	float distance;

};

void RayCastWorld(RayCastResult* result,glm::vec3 Direction,glm::vec3 startPosition,World* world,float distance);
bool CheckPoint(glm::vec3 position, World* world);