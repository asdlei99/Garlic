#include "clvpch.h"
#include "Renderer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Clove/Rendering/API/VertexArray.h"
#include "Clove/Rendering/API/IndexBuffer.h"
#include "Clove/Rendering/API/Shader.h"

namespace clv{
	void GLClearError(){
		while(glGetError() != GL_NO_ERROR);
	}

	bool GLLogCall(){
		while(GLenum error = glGetError()){
			CLV_ERROR("OpenGL Error! ({0})", error);
			return false;
		}
		return true;
	}

	void Renderer::clear() const{
		GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
	}

	void Renderer::draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const{
		shader.bind();
		va.bind();
		ib.bind();

		GLCall(glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr));
	}
}