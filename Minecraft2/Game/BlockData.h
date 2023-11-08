#pragma once
#include <string>
#include "glm/glm.hpp"
enum FaceDirection
{
	Top,
	Bottom,
	West,
	East,
	South,
	North
};


inline const char* FaceToString(FaceDirection face)
{
	switch (face)
	{
	case Top:   return "Top";
	case Bottom:   return "Bottom";
	case West: return "West";
	case East: return "East";
	case North: return "North";
	case South: return "South";
	default:      return "Null Face";
	}
}
inline glm::ivec3 FaceToDir(FaceDirection face) 
{
	switch (face)
	{
	case Top:   return {0,1,0};
	case Bottom:   return { 0,-1,0 };
	case West: return { 1,0,0 };
	case East: return { -1,0,0 };
	case North: return{ 0,0,1 };
	case South: return { 0,0,-1 };
	default:      return { 0,0,0 };
	}
}

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