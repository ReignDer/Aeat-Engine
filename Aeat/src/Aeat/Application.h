#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"
#include "Window.h"
namespace Aeat {
	class AEAT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Tumatakbo = true;
	};

	//To be defined by Client
	Application* CreateApplication();
}

