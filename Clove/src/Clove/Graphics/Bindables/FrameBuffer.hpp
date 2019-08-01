#pragma once

#include "Clove/Graphics/Bindable.hpp"

namespace clv::gfx{
	class Texture;

	class FrameBuffer : public Bindable{
		//FUNCTIONS
	public:
		FrameBuffer();
		FrameBuffer(const FrameBuffer& other) = delete;
		FrameBuffer(FrameBuffer&& other) noexcept;
		FrameBuffer& operator=(const FrameBuffer& other) = delete;
		FrameBuffer& operator=(FrameBuffer&& other) noexcept;
		virtual ~FrameBuffer();

		virtual void attachTexture(Texture& texture) = 0;

		virtual bool isComplete() const = 0;
	};
}
