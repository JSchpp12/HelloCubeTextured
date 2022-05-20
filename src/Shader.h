#pragma once

#include "Enums.h"

//fundamental shader object which will contain pointer to compiled shader for use in vulkan pipeline
class Shader {
public:
	Shader(); 

	Shader(const Shader&) = delete; 
	Shader& operator = (const Shader&) = delete; 
	~Shader() = default; 
protected: 
	STAR_SHADER_STAGE stage; 

private: 

};