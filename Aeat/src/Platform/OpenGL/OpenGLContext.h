#pragma once

#include "../../Aeat/Renderer/GraphicsContext.h"
#include <../../../vendor/Glad/include/Glad/glad.h>
#include "../../../vendor/GLFW_new/include/GLFW/glfw3.h"


struct GLFWwindow;

namespace Aeat {
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHawakan);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHawakan;
	};
}

