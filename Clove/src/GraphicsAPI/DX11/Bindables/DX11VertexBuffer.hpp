#pragma once

#include "Clove/Graphics/Bindable.hpp"

#include "GraphicsAPI/DX11/DX11Exception.hpp"

#include <wrl.h>

struct ID3D11Buffer;

namespace clv{
	namespace gfx{
		class DX11VertexBuffer : public Bindable{
			//VARIABLES
		private:
			Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer;

			//FUNCTIONS
		public:
			DX11VertexBuffer() = delete;
			DX11VertexBuffer(const DX11VertexBuffer& other) = delete;
			DX11VertexBuffer(DX11VertexBuffer&& other) noexcept;
			DX11VertexBuffer& operator=(const DX11VertexBuffer& other) = delete;
			DX11VertexBuffer& operator=(DX11VertexBuffer&& other) noexcept;
			~DX11VertexBuffer();

			DX11VertexBuffer(const std::vector<float>& vertices, Renderer* renderer);

			virtual void bind(Renderer* renderer) override;
			virtual void unbind() override;
		};
	}
}