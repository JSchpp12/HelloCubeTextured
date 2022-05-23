#pragma once 
#include "Vertex.h"
#include "Shader.h"
#include "Enums.h"
#include "GLSlangHelper.h"
#include "GLSLShader.h"

#include <vulkan/vulkan.hpp>

#include <glm/glm.hpp>
#include <vector>

class VulkanObject {
public:
	~VulkanObject();
	/// <summary>
	/// Default constructor for a vulkan object
	/// </summary>
	//VulkanObject();
	VulkanObject(std::vector<Vertex> verticies); 
	/// <summary>
	/// Ordered drawing of verticies
	/// </summary>
	/// <param name="verticies">List of verticies</param>
	/// <param name="indicies">Order of indicies that will be used during drawing</param>
	VulkanObject(std::vector<Vertex>* verticies, std::vector<uint16_t>* indicies); 

	//copy assignment 
	//VulkanObject& operator = (VulkanObject&&) = default; 

	void AddShader(vk::ShaderStageFlagBits stage, std::string pathToFile); 

	std::vector<Vertex> GetVerticies(); 

	std::vector<uint16_t> GetIndicies(); 

	std::vector<Shader> GetShaders(); 

	Shader GetVertShader(); 

	Shader GetFragShader(); 
protected:

private:
	std::vector<Vertex> vertexList; 
	std::vector<uint16_t> indicies; 
	GLSLShader vertexShader; 
	GLSLShader fragShader; 
	//TODO: implement positional elements
#pragma region todo
	////current position of the object
	//glm::vec3 position;
	////relative rotation of the object
	//glm::vec3 relativeRotation;

	//glm::vec4 displayMatrix;
#pragma endregion
 

};