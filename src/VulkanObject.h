#pragma once 
#include "Vertex.h"

#include <glm/glm.hpp>
#include <vector>

class VulkanObject {
public:
	/// <summary>
	/// Default constructor for a vulkan object
	/// </summary>
	VulkanObject();
	VulkanObject(std::vector<Vertex> verticies); 
	/// <summary>
	/// Ordered drawing of verticies
	/// </summary>
	/// <param name="verticies">List of verticies</param>
	/// <param name="indicies">Order of indicies that will be used during drawing</param>
	VulkanObject(std::vector<Vertex>* verticies, std::vector<uint16_t>* indicies); 

	std::vector<Vertex> GetVerticies(); 

	std::vector<uint16_t> GetIndicies(); 
protected:

private:
	std::vector<Vertex> vertexList; 
	std::vector<uint16_t> indicies; 

	//TODO: implement positional elements
#pragma region todo
	////current position of the object
	//glm::vec3 position;
	////relative rotation of the object
	//glm::vec3 relativeRotation;

	//glm::vec4 displayMatrix;
#pragma endregion
 

};