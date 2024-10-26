#pragma once

#include "../../Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include <../../../vendor/GLFW_new/include/GLFW/glfw3.h>
#include "../Layer.h"
#include "../Application.h"
#include "../Events/KeyEvent.h"
#include "../Events/MouseEvent.h"
#include "../Events/ApplicationEvent.h"

namespace Aeat {
	class AEAT_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnDikit();
		void OnTanggalin();
		void OnHimaton();
		void OnPangyayari(Event& pangyayari);

	private:
		ImGuiKey GlfwToImGuiKey(int keycode);
		bool OnMousePindutanPinindotEvent(MousePindutanPinindotEvent& pangyayari);
		bool OnMousePindutanBinitawEvent(MousePindutanBinitawEvent& pangyayari);
		bool OnMouseGumalawEvent(MouseGumalawEvent& pangyayari);
		bool OnMouseNabalumbonEvent(MouseNabalumbonEvent& pangyayari);
		bool OnKeyPinindotEvent(KeyPinindotEvent& pangyayari);
		bool OnKeyBinitawEvent(KeyBinitawEvent& pangyayari);
		bool OnKeyNagTypeEvent(KeyNagTypeEvent& pangyayari);
		bool OnWindowPalitLakiEvent(WindowPalitLakiEvent& pangyayari);

	private:
		float m_Time = 0.0f;


	};
}

