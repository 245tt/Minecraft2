#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include "glad.h"
#include <glm/gtc/type_ptr.hpp>
#include "glm/glm.hpp"

class Shader
{
public:
	~Shader();
	Shader(const char* vertPath, const char* fragPath);
	
	void Use();
	void SetInt(const std::string &name,int x);
	void SetFloat(const std::string &name, float x);
	void SetVec3(const std::string &name, float x,float y, float z);
	void SetVec3(const std::string &name, const glm::vec3 &vec);
	void SetVec2(const std::string &name, float x, float y);
	void SetVec2(const std::string &name, const glm::vec2 &vec);
	void SetMat4(const std::string &name, const glm::mat4 &mat);
	void SetMat3(const std::string &name, const glm::mat4& mat);
	void SetMat2(const std::string &name, const glm::mat4& mat);
	unsigned int id;
};

