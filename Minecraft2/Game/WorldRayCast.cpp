#include "WorldRayCast.h"

void RayCastWorld(RayCastResult* result, glm::vec3 Direction, glm::vec3 startPosition)
{
	int stepX;
	int stepY;
	int stepZ;

	if (Direction.x < 0) 
	{
		stepX = -1;
	}
	else 
	{
		stepX = 1;
	}
	if (Direction.y < 0)
	{
		stepY = -1;
	}
	else
	{
		stepY = 1;
	}
	if (Direction.z < 0)
	{
		stepZ = -1;
	}
	else
	{
		stepZ = 1;
	}


	//float ScaleX = ;
	//float ScaleY = ;
	//float ScaleZ = ;
	
}
