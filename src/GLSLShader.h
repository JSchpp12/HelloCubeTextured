#pragma once 
#include "Enums.h"
#include "GLSlangHelper.h"

#include <glslang/SPIRV/GlslangToSpv.h>
#include <stdexcept>
#include <string>
#include <list>
#include <memory>
#include <fstream>
#include <string>

//TODO: allow compilation at a later time 
//TODO: dynamically find what type of shader is being used from the file name (i.e. "shader.vert" = vertex (.vert))

//shader class generated from a GLSL shader file
class GLSLShader {
public: 
	bool shaderReady = false; 

	GLSLShader(GLSLShader&&) = default;

	/// <summary>
	/// Constructor which compiles and links the shader provided. 
	/// </summary>
	/// <param name="pathToFile">Path to GLSL shader file</param>
	/// <param name="pipeStage">Stage of the pipeline that the shader should be bound to</param>
	GLSLShader(vk::ShaderStageFlagBits stage, std::string pathToFile);


protected: 

	/// <summary>
	/// Call to compile and link the actual shader file
	/// </summary>
	void Compile(vk::ShaderStageFlagBits stage, const char* shaderCode);

private: 
	std::string pathToFile;

	//language being used
	EShLanguage stage; 

	/// <summary>
	/// Get proper stage for shader.
	/// </summary>
	/// <param name="stage"></param>
	/// <returns></returns>
	EShLanguage GetLanguage(STAR_SHADER_STAGE stage);

	/// <summary>
	/// Read the shader file into memory and place into memory
	/// </summary>
	/// <param name="shaderFile"></param>
	void ReadShaderFile(std::string pathToFile, std::unique_ptr<const char> &shaderFile);
};