#include "clvpch.hpp"
#include "Window.hpp"

#include "Clove/Graphics/Renderer.hpp"
#include "Clove/Graphics/Context.hpp"

namespace clv{
	Window::Window() = default;

	Window::~Window() = default;

	void Window::beginFrame(){
		processInput();
	}

	void Window::endFrame(){
		context->present();
	}

	void Window::setEventCallbackFunction(const EventCallbackFn& callback){
		eventCallback = callback;
	}

	unsigned int Window::getWidth() const{
		return windowProperties.width;
	}

	unsigned int Window::getHeight() const{
		return windowProperties.height;
	}

	Keyboard& Window::getKeyboard(){
		return keyboard;
	}

	Mouse& Window::getMouse(){
		return mouse;
	}

	gfx::Context& Window::getContext(){
		return *context.get();
	}
}