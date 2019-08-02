#include "clvpch.hpp"
#include "GL4Shader.hpp"

#include "Clove/Application.hpp"

#include <glad/glad.h>
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

	void GL4Shader::initialise(ShaderStyle style){
		unsigned int vertexID = 0;
		unsigned int pixelID = 0;
		
		switch(style){
			case ShaderStyle::Lit:
				{
					std::string vertexSource = parseShader("../Clove/src/Graphics/OpenGL-4/Shaders/Lit-vs.glsl");
					vertexID = compileShader(GL_VERTEX_SHADER, vertexSource);

					std::string pixelSource = parseShader("../Clove/src/Graphics/OpenGL-4/Shaders/Lit-ps.glsl");
					pixelID = compileShader(GL_FRAGMENT_SHADER, pixelSource);
				}
				break;
			case ShaderStyle::Unlit:
				{
					std::string vertexSource = parseShader("../Clove/src/Graphics/OpenGL-4/Shaders/Unlit-vs.glsl");
					vertexID = compileShader(GL_VERTEX_SHADER, vertexSource);

					std::string pixelSource = parseShader("../Clove/src/Graphics/OpenGL-4/Shaders/Unlit-ps.glsl");
					pixelID = compileShader(GL_FRAGMENT_SHADER, pixelSource);
				}
				break;

			case ShaderStyle::_2D:
				{
					std::string vertexSource = parseShader("../Clove/src/Graphics/OpenGL-4/Shaders/2D-vs.glsl");
					vertexID = compileShader(GL_VERTEX_SHADER, vertexSource);

					std::string pixelSource = parseShader("../Clove/src/Graphics/OpenGL-4/Shaders/2D-ps.glsl");
					pixelID = compileShader(GL_FRAGMENT_SHADER, pixelSource);
				}
				break;

			default:
				CLV_ASSERT(false, "Unknown type! {0}", __func__);
				break;
		}

		CLV_ASSERT(vertexID != 0 && pixelID != 0, "Pixel or vertex shader not set!");

		glAttachShader(programID, vertexID);
		glLinkProgram(programID);
		glValidateProgram(programID);
		glDeleteShader(vertexID);

		glAttachShader(programID, pixelID);
		glLinkProgram(programID);
		glValidateProgram(programID);
		glDeleteShader(pixelID);
	}

	std::string GL4Shader::parseShader(const std::string& filepath){
		std::ifstream stream(filepath);

		std::string line;
		std::stringstream ss;
		while(getline(stream, line)){
			ss << line << '\n';
		}

		return ss.str();
	}

	unsigned int GL4Shader::compileShader(unsigned int type, const std::string& source){
		unsigned int id = glCreateShader(type);
		const char* src = source.c_str();
		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);

		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		if(result == GL_FALSE){
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* message = new char[length];
			glGetShaderInfoLog(id, length, &length, message);
			CLV_LOG_ERROR("Failed to compile {0} shader! {1}", type == GL_VERTEX_SHADER ? "vertex" : "fragment", message);
			glDeleteShader(id);
			delete[] message;
		}

		return id;
	}
}