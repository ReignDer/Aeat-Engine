#pragma once
#include "Core.h"
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

