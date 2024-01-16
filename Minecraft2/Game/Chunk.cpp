#include "Chunk.h"

Chunk::Chunk() 
{
	for (int x = 0; x < 32; x++)
	{
		for (int y = 0; y < 32; y++)
		{
			for (int z = 0; z < 32; z++)
			{
				blocks[x][y][z] = 0;
			}
		}
	}
}

void Chunk::Populate()
{
	
	for (int x = 0; x < 32; x++) 
	{
		for (int y = 0; y <32; y++)
		{
			for (int z = 0; z < 32; z++)
			{
				
				if (y > 8) {
					
					blocks[x][y][z] = 0;
				}
				else 
				{
					blocks[x][y][z] = 1;
				}
				
			}
		}
	}
}
	

