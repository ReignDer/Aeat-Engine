#include "aepch.h"
#include "OpenGLContext.h"


namespace Aeat {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHawakan) :
		m_WindowHawakan(windowHawakan)
	{
		AE_CORE_ASSERT(m_WindowHawakan, "Window Handle is Null!");
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHawakan);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		AE_CORE_ASSERT(status, "Failed to initialize Glad!");


		AE_CORE_INFO("OpenGL Vendor: {0}", (char*)glGetString(GL_VENDOR));
		AE_CORE_INFO("OpenGL Renderer: {0}", (char*)glGetString(GL_RENDERER));
		AE_CORE_INFO("OpenGL Version: {0}", (char*)glGetString(GL_VERSION));
	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHawakan);
	}
}