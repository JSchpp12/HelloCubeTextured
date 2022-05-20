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
	if (stage == vk::ShaderStageFlagBits::eFragment) {
		this->vertexShader = new GLSLShader(stage, pathToFile);
	}
	else {
		this->fragShader = new GLSLShader(stage, pathToFile); 
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
