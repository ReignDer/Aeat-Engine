#include "aepch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Aeat {

	VertexArray* VertexArray::Create()
	{
		switch (Renderer::KuninAPI())
		{
		case RendererAPI::None: AE_CORE_ASSERT(false, "RendererAPI::None currently not supported!"); return nullptr;
		case RendererAPI::OpenGL: return new OpenGLVertexArray();

		}
		AE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
