#pragma once

#include "RendererAPI.h"

namespace Aeat {

	class RenderCommand {
	public:
		inline static void ItakdaClearKulay(const glm::vec4& color) {
			s_RendererAPI->ItakdaClearKulay(color);
		}
		inline static void Clear() {
			s_RendererAPI->Clear();
		}
		inline static void GuhitNaIndex(const std::shared_ptr<VertexArray>& vertexArray) {
			s_RendererAPI->GuhitNaIndex(vertexArray);
		}
	private:
		static RendererAPI* s_RendererAPI;
	};
}
