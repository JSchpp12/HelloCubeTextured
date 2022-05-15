#include "VulkanObject.h"

VulkanObject::VulkanObject()
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

std::vector<Vertex> VulkanObject::GetVerticies()
{
	return this->vertexList;
}

std::vector<uint16_t> VulkanObject::GetIndicies()
{
	return this->indicies; 
}
