#include "Chunk.h"

Chunk::~Chunk()
{
}

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
				float v = sin(x/2);
				float v2 = sin(z/2);
				if (y > 16) {
					if (y < (v + v2) + 26) {
						blocks[x][y][z] = 1;
					}
					else {
						blocks[x][y][z] = 0;
					}
				}
				else 
				{
					blocks[x][y][z] = 2;
				}
			}
		}
	}
}
	

