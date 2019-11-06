#pragma once

#include "Core/Graphics/Resources/Buffer.hpp"

namespace clv::gfx{
	struct IndexBufferDescriptor{
		//TODO
	};
}

namespace clv::gfx{
	class IndexBuffer : public Buffer{
		//FUNCTIONS
	public:
		virtual uint32 getIndexCount() const = 0;
	};
}