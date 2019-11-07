#pragma once

#include "Core/Graphics/RenderDevice.hpp"
#include "Core/Graphics/RenderFactory.hpp"

namespace clv::gfx{
	//NOTE: This will be used to create a multithreaded renderer. But for now it just wraps the API calls
	class RenderCommand{
		//VARIABLES
	private:
		static std::unique_ptr<RenderDevice> device;
		static std::unique_ptr<RenderFactory> factory;

		//FUNCTIONS
	public:
		static void bindIndexBuffer(IndexBuffer& buffer);
		static void bindVertexBuffer(VertexBuffer& buffer);
		
		static void bindShaderResource(ShaderResource& resource, uint32 bindingPoint); //Temp uint32 - should be the enum

		static void bindTexture(Texture& texture, uint32 bindingPoint); //Temp uint32 - should be the enum

		static void bindShader(Shader& shader);

		static void setRenderTarget(RenderTarget& renderTarget);

		static void setViewport(const Viewport& viewport);

		static void clear();
		static void drawIndexed(const uint32 count);

		static void setClearColour(const math::Vector4f& colour);
		static void setDepthBuffer(bool enabled);
		static void setBlendState(bool enabled);

		//TEMP: Need an 'unbind' function or to refactor the bindable system
		//static void removeCurrentGeometryShader();
		//static void removeTextureAtSlot(uint32 slot);
		//

		static std::shared_ptr<IndexBuffer> createIndexBuffer(const IndexBufferDescriptor& descriptor);
		static std::shared_ptr<VertexBuffer> createVertexBuffer(const VertexBufferDescriptor& descriptor);

		static std::shared_ptr<ShaderResource> createShaderResource(const ShaderResourceDescriptor& descriptor);

		static std::shared_ptr<Texture> createTexture(const TextureDescriptor& descriptor);

		static std::shared_ptr<Surface> createSurface();

		static std::shared_ptr<Viewport> createViewport();

		static void initialiseRenderDevice();
	};
}
