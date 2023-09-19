#include <string>

//enum FaceDirection 
//{
//	Top,
//	Bottom,
//	Front,
//	Back,
//	Left,
//	Right,
//};

struct BlockData
{
	int id;
	std::string name;
	int hardness;
	bool opaque;

	BlockData(int id, std::string name, int hardness, bool opaque) 
	{
		this->id = id;
		this->name = name;
		this->hardness = hardness;
		this->opaque = opaque;
	}
};

const BlockData BlockList[] = {
	BlockData(0,"Air",0,false),
	BlockData(1,"Dirt",5,true),
	BlockData(2,"Stone",7,true),

};