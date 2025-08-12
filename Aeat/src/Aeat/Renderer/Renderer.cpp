#include "aepch.h"
#include "Renderer.h"

namespace Aeat {
	void Renderer::BeginScene()
	{
	}
	void Renderer::EndScene()
	{
	}
	void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray)
	{
		vertexArray->Bind();
		RenderCommand::GuhitNaIndex(vertexArray);
	}
}