#include "aepch.h"
#include "WindowsInput.h"

namespace Aeat {
	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::NagawaPindotKey(int keyKodigo)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().KuninWindow().KuninNativeWindow());

		auto state = glfwGetKey(window, keyKodigo);

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
	bool WindowsInput::NagawaPindotMousePindutan(int pindutan)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().KuninWindow().KuninNativeWindow());

		auto state = glfwGetMouseButton(window, pindutan);

		return state == GLFW_PRESS;
	}
	std::pair<float, float> WindowsInput::NagawaKuninMousePosition()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().KuninWindow().KuninNativeWindow());
		double xpos, ypos;

		glfwGetCursorPos(window, &xpos,&ypos);

		return { (float)xpos, (float)ypos };
	}
	float WindowsInput::NagawaKuninMouseX()
	{
		auto [x, y] = KuninMousePosition();
		return x;

	}
	float WindowsInput::NagawaKuninMouseY()
	{
		auto [x, y] = KuninMousePosition();
		return y;
	}
}
