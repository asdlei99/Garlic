#include "RenderCommand.hpp"

#include "Graphics/OpenGL/GL.hpp"
#if CLV_PLATFORM_WINDOWS
#include "Graphics/Direct3D/D3D.hpp"
#endif

namespace clv::gfx{
	std::unique_ptr<RenderDevice> RenderCommand::device;
	std::unique_ptr<RenderFactory> RenderCommand::factory;

	void RenderCommand::bindIndexBuffer(const Buffer& buffer){
		device->bindIndexBuffer(buffer);
	}

	void RenderCommand::bindVertexBuffer(const Buffer& buffer){
		device->bindVertexBuffer(buffer);
	}

	void RenderCommand::bindShaderResourceBuffer(const Buffer& buffer, const ShaderType shaderType, const uint32 bindingPoint){
		device->bindShaderResourceBuffer(buffer, shaderType, bindingPoint);
	}

	void RenderCommand::bindTexture(const Texture& texture, const uint32 bindingPoint){
		device->bindTexture(texture, bindingPoint);
	}

	void RenderCommand::bindShader(const Shader& shader){
		device->bindShader(shader);
	}

	void RenderCommand::updateBufferData(Buffer& buffer, void* data){
		device->updateBufferData(buffer, data);
	}

	void RenderCommand::makeSurfaceCurrent(Surface& surface){
		device->makeSurfaceCurrent(surface);
	}

	void RenderCommand::setRenderTarget(RenderTarget& renderTarget){
		device->setRenderTarget(renderTarget);
	}

	void RenderCommand::resetRenderTargetToDefault(){
		device->resetRenderTargetToDefault();
	}

	void RenderCommand::setViewport(const Viewport& viewport){
		device->setViewport(viewport);
	}

	void RenderCommand::clear(){
		device->clear();
	}

	void RenderCommand::drawIndexed(const uint32 count){
		device->drawIndexed(count);
	}

	void RenderCommand::setClearColour(const math::Vector4f& colour){
		device->setClearColour(colour);
	}

	void RenderCommand::setDepthBuffer(bool enabled){
		device->setDepthBuffer(enabled);
	}

	void RenderCommand::setBlendState(bool enabled){
		device->setBlendState(enabled);
	}

	void RenderCommand::removeCurrentGeometryShader(){
		device->removeCurrentGeometryShader();
	}

	void RenderCommand::removeTextureAtSlot(uint32 slot){
		device->removeTextureAtSlot(slot);
	}

	std::shared_ptr<Buffer> RenderCommand::createBuffer(const BufferDescriptor& descriptor, void* data){
		return factory->createBuffer(descriptor, data);
	}

	std::shared_ptr<Texture> RenderCommand::createTexture(const TextureDescriptor& descriptor, const std::string& pathToTexture){
		return factory->createTexture(descriptor, pathToTexture);
	}

	std::shared_ptr<Texture> RenderCommand::createTexture(const TextureDescriptor& descriptor, void* data, int32 BPP){
		return factory->createTexture(descriptor, data, BPP);
	}

	std::shared_ptr<RenderTarget> RenderCommand::createRenderTarget(Texture* colourTexture, Texture* depthStencilTexture){
		return factory->createRenderTarget(colourTexture, depthStencilTexture);
	}

	std::shared_ptr<Shader> RenderCommand::createShader(const ShaderDescriptor& descriptor){
		return factory->createShader(descriptor);
	}

	std::shared_ptr<Surface> RenderCommand::createSurface(){
		return factory->createSurface();
	}

	void RenderCommand::initialise(gfx::API api){
		switch(api){
			case API::OpenGL4:
				{
					CLV_LOG_TRACE("Creating OpenGL renderer");
					auto pair = ogl::initialiseOGL();
					device = std::move(pair.first);
					factory = std::move(pair.second);
					break;
				}

			#if CLV_PLATFORM_WINDOWS
			case API::DirectX11:
				{
					CLV_LOG_TRACE("Creating Direct3D API");
					auto pair = d3d::_11::initialiseD3D();
					device = std::move(pair.first);
					factory = std::move(pair.second);
					break;
				}
			#endif

			default:
				CLV_LOG_ERROR("Default statement hit. Could not initialise RenderAPI: {0}", CLV_FUNCTION_NAME);
				break;
		}
	}
}