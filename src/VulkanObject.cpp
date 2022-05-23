#include "VulkanObject.h"


VulkanObject::~VulkanObject()
{

}

VulkanObject::VulkanObject(std::vector<Vertex> verticies)
{

}

VulkanObject::VulkanObject(std::vector<Vertex>* verticies, std::vector<uint16_t>* indicies)
{
	this->vertexList = *verticies; 
	this->indicies = *indicies; 
}

void VulkanObject::AddShader(vk::ShaderStageFlagBits stage, std::string pathToFile)
{
	if (stage == vk::ShaderStageFlagBits::eVertex) {
		this->vertexShader = GLSLShader(stage, pathToFile);
	}
	else {
		this->fragShader = GLSLShader(stage, pathToFile); 
	}
}

std::vector<Vertex> VulkanObject::GetVerticies()
{
	return this->vertexList;
}

std::vector<uint16_t> VulkanObject::GetIndicies()
{
	return this->indicies; 
}

std::vector<Shader> VulkanObject::GetShaders()
{
	std::vector<Shader> shaderList; 

	shaderList.push_back(this->vertexShader); 
	shaderList.push_back(this->fragShader); 

	return shaderList; 
}

Shader VulkanObject::GetVertShader()
{
	return this->vertexShader; 
}

Shader VulkanObject::GetFragShader()
{
	return this->fragShader; 
}
