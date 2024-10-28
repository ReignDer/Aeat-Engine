#include "aepch.h"
#include "WindowsWindow.h"

namespace Aeat {
	static bool s_GLFWPagsisimula = false;
	static void GLFWErrorCallback(int error, const char* description) {
		AE_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		Init(props);
	}

	WindowsWindow::~WindowsWindow(){
		Pagsasara();
	}

	void WindowsWindow::Init(const WindowProps& props) {
		m_Data.Pamagat = props.Pamagat;
		m_Data.Laki = props.Laki;
		m_Data.Haba = props.Haba;

		AE_CORE_INFO("Creating Window {0}, ({1}, {2})", props.Pamagat, props.Laki, props.Haba);

		if (!s_GLFWPagsisimula) {
			int success = glfwInit();
			AE_CORE_ASSERT(success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWPagsisimula = true;
		}

		m_Window = glfwCreateWindow((int)props.Laki, (int)props.Haba, m_Data.Pamagat.c_str(), nullptr, nullptr);

		m_Context = new OpenGLContext(m_Window);
		m_Context->Init();

		
		glfwSetWindowUserPointer(m_Window, &m_Data);
		ItakdaVsync(true);

		//Set GLFW Callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int laki, int haba)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Laki = laki;
				data.Haba = haba;

				WindowPalitLakiEvent event(laki, haba);
				data.EventCallback(event);

			});
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				WindowSaradoEvent event;
				data.EventCallback(event);
			});
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action) {
				case GLFW_PRESS: {
					KeyPinindotEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyBinitawEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPinindotEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
				}
			});
		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keyKodigo)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				KeyNagTypeEvent pangyayari(keyKodigo);
				data.EventCallback(pangyayari);
				
			});
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action) {
				case GLFW_PRESS: {
					MousePindutanPinindotEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MousePindutanBinitawEvent event(button);
					data.EventCallback(event);
					break;
				}
				}
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseNabalumbonEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseGumalawEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);
			});
	}

	void WindowsWindow::Pagsasara(){
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnHimaton() {
		glfwPollEvents();
		m_Context->SwapBuffers();
		
	}

	void WindowsWindow::ItakdaVsync(bool pinagana) {
		if (pinagana)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.Vsync = pinagana;

	}

	bool WindowsWindow::VsyncBa() const {
		return m_Data.Vsync;
	}



}
