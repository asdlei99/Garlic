#pragma once

#include "Clove/Graphics/Core/GraphicsTypes.hpp"

namespace clv::gfx{
	class Buffer;
	class Texture;
	class PipelineObject;
	class RenderTarget;
	class Shader;
	class Surface;
	struct Viewport;
}

namespace clv::gfx{
	class CommandBuffer{
		//FUNCTIONS
	public:
		virtual ~CommandBuffer() = default;

		virtual void beginEncoding() = 0;

		virtual void bindIndexBuffer(const Buffer& buffer) = 0;
		virtual void bindVertexBuffer(const Buffer& buffer, const uint32 stride) = 0;
		virtual void bindShaderResourceBuffer(const Buffer& buffer, const ShaderType shaderType, const uint32 bindingPoint) = 0;
		virtual void bindPipelineObject(const PipelineObject& pipelineObject) = 0;
		virtual void bindTexture(const Texture* texture, const uint32 bindingPoint) = 0;

		virtual void setViewport(const Viewport& viewport) = 0;
		virtual void setDepthEnabled(bool enabled) = 0;

		virtual void drawIndexed(const uint32 count) = 0;

		virtual void endEncoding() = 0;
	};
}