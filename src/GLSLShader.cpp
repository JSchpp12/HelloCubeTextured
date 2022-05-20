#include "GLSLShader.h"

GLSLShader::GLSLShader(vk::ShaderStageFlagBits stage, std::string pathToFile)
{
	std::unique_ptr<const char> shaderCode; 

	this->ReadShaderFile(pathToFile, shaderCode); 
	this->Compile(stage, shaderCode.get()); 
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

void GLSLShader::ReadShaderFile(std::string pathToFile, std::unique_ptr<const char>& shaderFile)
{
	//read in file 
	//std::string line, text;
	//std::ifstream fileReader(pathToFile);
	//std::unique_ptr<const char> shaderCode;

	//while (std::getline(fileReader, line)) {
	//	text += line + "\n";
	//}

	//shaderFile = std::make_unique<const char>(text.c_str()); 
}
