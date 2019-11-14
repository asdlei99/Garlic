#pragma once

/*
has the swap chain / context (the thing you render to for a window)
*/

namespace clv::gfx{
	class RenderDevice;
	class RenderTarget;
}

namespace clv::gfx{
	class Surface{
		//FUNCTIONS
	public:
		virtual ~Surface() = default;

		virtual void setVSync(bool vsync) = 0;
		virtual bool isVsync() const = 0;

		virtual void present() = 0;
	};
}