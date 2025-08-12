#pragma once
#include "Aeat/Renderer/RendererAPI.h"

namespace Aeat {
	class OpenGLRendererAPI : public RendererAPI {
		
		void ItakdaClearKulay(const glm::vec4& color) override;
		void Clear() override;
		void GuhitNaIndex(const std::shared_ptr<VertexArray>& vertexArray) override;
	};
}