#pragma once
#include "Core.h"
#include "MidEngine/Events/ApplicationEvent.h"
#include "Window.h"
#include "MidEngine/LayerStack.h"

namespace ME {
	class ME_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline static Application& Get() { return *s_Instance; }
        inline Window& GetWindow() { return *m_Window; }
	private:
		static Application* s_Instance;
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	};

	// define in client
	Application* CreateApplication();
}

