#pragma once

namespace clv{
	class Window;
	class LayerStack;
	class Layer;
	class Event;
	class WindowCloseEvent;
	class ImGuiLayer;
	namespace scene{ class Scene; };

	class Application{
		//VARIABLES
	private:
		std::unique_ptr<Window> window;
		std::shared_ptr<scene::Scene> scene;

		bool running = true;

		std::unique_ptr<LayerStack> layerStack;
		std::shared_ptr<ImGuiLayer> imGuiLayer;

		static Application* instance;

		std::chrono::system_clock::time_point prevFrameTime;

		//FUNCTIONS
	public:
		Application();
		virtual ~Application();

		void run();
		void stop();

		void onEvent(Event& e);

		void pushLayer(std::shared_ptr<Layer> layer);
		void pushOverlay(std::shared_ptr<Layer> overlay);

		inline static Application& get();
		inline Window& getWindow();
		inline std::shared_ptr<scene::Scene> getScene();

	private:
		bool onWindowClose(WindowCloseEvent& e);
	};

	//To be defined in CLIENT
	Application* createApplication();
}

#include "Application.inl"