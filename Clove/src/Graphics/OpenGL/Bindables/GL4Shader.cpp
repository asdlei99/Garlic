#include "GL4Shader.hpp"

#include "Graphics/OpenGL-4/ShaderStrings.hpp"

#include <fstream>
#include <sstream>

namespace clv::gfx{
	GL4Shader::GL4Shader(GL4Shader&& other) noexcept = default;

	GL4Shader& GL4Shader::operator=(GL4Shader&& other) noexcept = default;

	GL4Shader::~GL4Shader(){
		glDeleteProgram(programID);
	}

	GL4Shader::GL4Shader(ShaderStyle style)
		: programID(glCreateProgram()){
		initialise(style);
	}

	void GL4Shader::bind(){
		glUseProgram(programID);
	}

	ShaderReflectionData GL4Shader::getReflectionData(){
		ShaderReflectionData outData;

		GLint attribCount = 0;
		glGetProgramiv(programID, GL_ACTIVE_ATTRIBUTES, &attribCount);
		for(int32 i = 0; i < attribCount; ++i){
			GLchar name[255];
			GLsizei length = 0;
			GLint size = 0;
			GLenum type = 0;

			glGetActiveAttrib(programID, static_cast<GLuint>(i), sizeof(name), &length, &size, &type, name);

			outData.vertexBufferLayout.add(VertexElement::getTypeFromSemantic(name));
		}

		return outData;
	}

	uint32 GL4Shader::getProgramID() const{
		return programID;
	}

	void GL4Shader::initialise(ShaderStyle style){
		uint32 vertexID = 0;
		uint32 pixelID = 0;
		uint32 geometryID = 0;
		
		switch(style){
			case ShaderStyle::Lit_3D:
				{
					vertexID = compileShader(GL_VERTEX_SHADER, shader_Lit_vs);
					pixelID = compileShader(GL_FRAGMENT_SHADER, shader_Lit_ps);
				}
				break;

			case ShaderStyle::Unlit_3D:
				{
					vertexID = compileShader(GL_VERTEX_SHADER, shader_Unlit_vs);
					pixelID = compileShader(GL_FRAGMENT_SHADER, shader_Unlit_ps);
				}
				break;

			case ShaderStyle::Unlit_2D:
				{
					vertexID = compileShader(GL_VERTEX_SHADER, shader_2D_vs);
					pixelID = compileShader(GL_FRAGMENT_SHADER, shader_2D_ps);
				}
				break;

			case ShaderStyle::RT:
				{
					vertexID = compileShader(GL_VERTEX_SHADER, shader_RT_vs);
					pixelID = compileShader(GL_FRAGMENT_SHADER, shader_RT_ps);
				}
				break;

			case ShaderStyle::Font:
				{
					vertexID = compileShader(GL_VERTEX_SHADER, shader_Font_vs);
					pixelID = compileShader(GL_FRAGMENT_SHADER, shader_Font_ps);
				}
				break;

			case ShaderStyle::CubeShadowMap:
				{
					vertexID = compileShader(GL_VERTEX_SHADER, shader_CubeShadowMap_vs);
					pixelID = compileShader(GL_FRAGMENT_SHADER, shader_CubeShadowMap_ps);
					geometryID = compileShader(GL_GEOMETRY_SHADER, shader_CubeShadowMap_gs);
				}
				break;

			default:
				CLV_ASSERT(false, "Unknown type! {0}", CLV_FUNCTION_NAME);
				break;
		}

		CLV_ASSERT(vertexID != 0 && pixelID != 0, "Pixel or vertex shader not set!");

		attachAndLinkShader(vertexID);
		attachAndLinkShader(pixelID);
		if(geometryID != 0){
			attachAndLinkShader(geometryID);
		}
	}

	uint32 GL4Shader::compileShader(uint32 type, const std::string& source){
		uint32 id = glCreateShader(type);
		const char* src = source.c_str();
		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);

		int32 result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		if(result == GL_FALSE){
			int32 length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* message = new char[length];
			glGetShaderInfoLog(id, length, &length, message);
			CLV_LOG_ERROR("Failed to compile {0} shader! {1}", getStringFromShaderType(type), message);
			glDeleteShader(id);
			delete[] message;
		}

		return id;
	}

	void GL4Shader::attachAndLinkShader(uint32 shaderID){
		glAttachShader(programID, shaderID);
		glLinkProgram(programID);
		glValidateProgram(programID);
		glDeleteShader(shaderID);
	}

	std::string GL4Shader::getStringFromShaderType(GLuint glShaderType){
		switch(glShaderType){
			case GL_VERTEX_SHADER:
				return "vertex";
			case GL_FRAGMENT_SHADER:
				return "pixel";
			case GL_GEOMETRY_SHADER:
				return "geometry";
			default:
				CLV_ASSERT(false, "Uknown type in {0}", CLV_FUNCTION_NAME);
				return "unkown";
		}
	}
}