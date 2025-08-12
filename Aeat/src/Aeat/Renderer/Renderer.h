#pragma once

#include "RenderCommand.h"
namespace Aeat {
	

	class Renderer {
	public:
		static void BeginScene();
		static void EndScene();

		static void Submit(const std::shared_ptr<VertexArray>& vertexArray);

		inline static RendererAPI::API KuninAPI() { return RendererAPI::KuninAPI(); }
	};
}
