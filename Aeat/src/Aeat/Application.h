#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"
#include "Window.h"
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
	private:
		bool OnWindowSarado(WindowSaradoEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Tumatakbo = true;
	};

	//To be defined by Client
	Application* CreateApplication();
}

