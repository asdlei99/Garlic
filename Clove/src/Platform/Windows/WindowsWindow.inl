namespace clv {
	inline void WindowsWindow::setEventCallbackFunction(const EventCallbackFn& callback){
		data.eventCallback = callback;
	}

	inline unsigned int WindowsWindow::getWidth() const {
		return data.width;
	}

	inline unsigned int WindowsWindow::getHeight() const{
		return data.height;
	}
}