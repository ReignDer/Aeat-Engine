#pragma once

#include "Core.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"
#include "LayerStack.h"



#include "Input.h"
#include "ImGui/ImGuiLayer.h"




namespace Aeat {
	class AEAT_API ImGuiLayer;
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
		ImGuiLayer* m_ImGuiLayer;
		bool m_Tumatakbo = true;
		LayerStack m_LayerPatong;
		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;

	private:
		static Application* s_Instance;

	};

	//To be defined by Client
	Application* CreateApplication();
}

