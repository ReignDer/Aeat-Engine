#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"
namespace Aeat {
	class AEAT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined by Client
	Application* CreateApplication();
}

