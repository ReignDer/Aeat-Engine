#pragma once

namespace Aeat {
	enum class RendererAPI {
		None = 0,
		OpenGL = 1,
	};

	class Renderer {
	public:
		inline static RendererAPI KuninAPI() { return s_RendererAPI; }
	private:
		static RendererAPI s_RendererAPI;
	};
}
