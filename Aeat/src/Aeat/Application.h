#pragma once

#include "Core.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"
#include "LayerStack.h"
#include "../../vendor/GLFW_new/include/GLFW/glfw3.h"

namespace Aeat {
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	class AEAT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnHimaton(Event& e);

		void TulakLayer(Layer* layer);

		void TulakOverlay(Layer* overlay);
		
		inline Window& KuninWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowSarado(WindowSaradoEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Tumatakbo = true;
		LayerStack m_LayerPatong;
		static Application* s_Instance;

	};

	//To be defined by Client
	Application* CreateApplication();
}

