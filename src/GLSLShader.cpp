#include "GLSLShader.h"

GLSLShader::GLSLShader(vk::ShaderStageFlagBits stage, std::string pathToFile)
{
	std::string shaderCode = this->ReadShaderFile(pathToFile); 
	const char* rawShaderCode = shaderCode.c_str(); 
	this->Compile(stage, rawShaderCode);
}

void GLSLShader::Compile(vk::ShaderStageFlagBits stage, const char* shaderCode)
{
	//std::list<glslang::TShader*> shaders; 

	//might need to look into using these messages 
	EShMessages messages = EShMsgDefault; 

	std::unique_ptr<glslang::TShader> shader(new glslang::TShader(this->stage)); 

	std::vector<unsigned int> shaderCodeSpirV; 
	bool success = GLSlangHelper::GLSLtoSPV(stage, shaderCode, shaderCodeSpirV); 
}

EShLanguage GLSLShader::GetLanguage(STAR_SHADER_STAGE stage)
{
	//for now, using the provided argument to generate proper stage 
	//TODO: fix this
	switch (stage) {
	case(STAR_SHADER_STAGE::VERTEX):
		return EShLanguage::EShLangVertex; 
		break;
	case(STAR_SHADER_STAGE::FRAGMENT):
		return EShLanguage::EShLangFragment; 
		break;
	default:
		throw std::invalid_argument("The provided stage is not supported"); 
	}
	return EShLanguage();
}

std::string GLSLShader::ReadShaderFile(std::string pathToFile)
{
	//read in file 
	std::string line, text;
	std::ifstream fileReader(pathToFile);

	while (std::getline(fileReader, line)) {
		text += line + "\n";
	}

	return(text); 
	//shaderFile = std::unique_ptr<const char>(text.c_str());
}
