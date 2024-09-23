#include "aepch.h"
#include "WindowsWindow.h"

#include <../../../vendor/GLFW_new/include/GLFW/glfw3.h>

namespace Aeat {
	static bool s_GLFWPagsisimula = false;

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

		AE_CORE_INFO("Creating Window {0}, ({1}, {2})", props.Pamagat,props.Laki,props.Haba);

		if (!s_GLFWPagsisimula) {
			int success = glfwInit();
			AE_CORE_ASSERT(success, "Could not initialize GLFW!");
			s_GLFWPagsisimula = true;
		}

		m_Window = glfwCreateWindow((int)props.Laki, (int)props.Haba, m_Data.Pamagat.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		ItakdaVsync(true);

	}

	void WindowsWindow::Pagsasara(){
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnHimaton() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
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
