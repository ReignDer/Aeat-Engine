#pragma once

#include "../../Aeat/Window.h"
#include "../../Aeat/Events/ApplicationEvent.h"
#include "../../Aeat/Events/MouseEvent.h"
#include "../../Aeat/Events/KeyEvent.h"
#include "../../Aeat/Renderer/GraphicsContext.h"
#include "../OpenGL/OpenGLContext.h"


#include <../../../vendor/GLFW_new/include/GLFW/glfw3.h>




namespace Aeat {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnHimaton() override;

		inline unsigned int KuninWidth() const override { return m_Data.Laki; }
		inline unsigned int KuninHeight() const override { return m_Data.Haba; }

		//Window Attribute
		inline void ItakdaEventCallback(const EventCallbackFn& tawaginMuli) override { m_Data.EventCallback = tawaginMuli; }
		void ItakdaVsync(bool pinagana) override;
		bool VsyncBa() const override;

		inline virtual void* KuninNativeWindow() const { return m_Window; }

		
	private:
		virtual void Init(const WindowProps& props);
		virtual void Pagsasara();
	private:
		GLFWwindow* m_Window;
		GraphicsContext* m_Context;
		//For GLFW to use
		struct WindowData {
			std::string Pamagat;
			unsigned int Laki, Haba;
			bool Vsync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}

