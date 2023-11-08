#include "WorldRayCast.h"


void RayCastWorld(RayCastResult* result, glm::vec3 Direction, glm::vec3 startPosition, Chunk* world, float distance)
{
	int numberOfSteps = distance / STEP;
	glm::vec3 checkpoint = startPosition;
	bool hit = false;
	for (int i = 0; i < numberOfSteps; i++)
	{
		//move X axis
		checkpoint.x += (STEP * Direction.x);
		hit = CheckPoint(checkpoint, world);
		if (hit)
		{
			result->distance = i * STEP;
			if (Direction.x > 0)
			{
				result->faceDirection = FaceDirection::East;
			}
			else
			{
				result->faceDirection = FaceDirection::West;
			}
			break;
		}
		//move on Y axis
		checkpoint.y += (STEP * Direction.y);
		hit = CheckPoint(checkpoint, world);
		if (hit)
		{
			result->distance = i * STEP;
			if (Direction.y > 0)
			{
				result->faceDirection = FaceDirection::Bottom;
			}
			else
			{
				result->faceDirection = FaceDirection::Top;
			}
			break;
		}
		//move on Z axis
		checkpoint.z += (STEP * Direction.z);
		hit = CheckPoint(checkpoint, world);
		if (hit)
		{
			result->distance = i * STEP;
			if (Direction.z > 0)
			{
				result->faceDirection = FaceDirection::South;
			}
			else
			{
				result->faceDirection = FaceDirection::North;
			}
			break;
		}
	}
	//std::cout << checkpoint.x << " " << checkpoint.y << " " << checkpoint.z << std::endl;
	if (hit) 
	{
		result->hitPos = checkpoint;
		result->hit = true;
		
		int gridX = (int)round(checkpoint.x);
		int gridY = (int)round(checkpoint.y);
		int gridZ = (int)round(checkpoint.z);

		//std::cout << gridX << " " << gridY << " " << gridZ << std::endl;
		result->blockPos = glm::vec3(gridX,gridY,gridZ);
	}else
	{
		result->hit = false;
	}
	

}

bool CheckPoint(glm::vec3 position, Chunk* world)
{
	int gridX = (int)round(position.x);
	int gridY = (int)round(position.y);
	int gridZ = (int)round(position.z);
	if (gridX >= 0 && gridX < 32 && gridY >= 0 && gridY < 32 && gridZ >= 0 && gridZ < 32) 
	{
		if (world->blocks[gridX][gridY][gridZ] != 0) 
		{
			return true;
		}
	}
	return false;
}
