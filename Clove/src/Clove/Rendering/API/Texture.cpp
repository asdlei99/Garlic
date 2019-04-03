#include "clvpch.h"
#include "Texture.h"

#include "stb_image.h"

#include "Clove/Rendering/Renderer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace clv{
	Texture::Texture(const std::string& filePath)
		: filePath(filePath){
		
		stbi_set_flip_vertically_on_load(1); //Opengl expects our texture to start on the bottom left
		localBuffer = stbi_load(filePath.c_str(), &width, &height, &BPP, 4); //4 = RGBA

		GLCall(glGenTextures(1, &rendererID));
		GLCall(glBindTexture(GL_TEXTURE_2D, rendererID));

		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

		GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer));
		GLCall(glBindTexture(GL_TEXTURE_2D, 0));

		if(localBuffer){
			stbi_image_free(localBuffer);
		}
	}

	Texture::~Texture(){
		//GLCall(glDeleteTextures(1, &rendererID));
	}

	void Texture::bind(unsigned int slot) const{
		GLCall(glActiveTexture(GL_TEXTURE0 + slot));
		GLCall(glBindTexture(GL_TEXTURE_2D, rendererID));
	}

	void Texture::unbind() const{
		GLCall(glBindTexture(GL_TEXTURE_2D, 0));
	}

	void Texture::deleteTexture(){
		GLCall(glDeleteTextures(1, &rendererID));
	}
}