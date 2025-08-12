#pragma once

#include "VertexArray.h"
#include <glm/glm.hpp>


namespace Aeat {
	class RendererAPI {
	public:
		enum class API {
			None = 0,
			OpenGL = 1,
			Vulkan = 2,
			DirectX = 3
		};

	public:
		virtual void ItakdaClearKulay(const glm::vec4& color) = 0;
		virtual void Clear() = 0;

		virtual void GuhitNaIndex(const std::shared_ptr<VertexArray>& vertexArray) = 0;

		inline static API KuninAPI() { return s_API; }
	private:
		static API s_API;
	};
}
