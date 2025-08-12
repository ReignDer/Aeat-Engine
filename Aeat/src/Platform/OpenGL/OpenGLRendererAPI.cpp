#include "aepch.h"
#include "OpenGLRendererAPI.h"
#include <glad/glad.h>


namespace Aeat {
	void OpenGLRendererAPI::ItakdaClearKulay(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGLRendererAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRendererAPI::GuhitNaIndex(const std::shared_ptr<VertexArray>& vertexArray)
	{
		glDrawElements(GL_TRIANGLES, vertexArray->KuninIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
	}
}
