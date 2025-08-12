#include "aepch.h"


#include "Buffer.h"

#include "Renderer.h"
#include "../../Platform/OpenGL/OpenGLBuffer.h"

namespace Aeat {
	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::KuninAPI())
		{
			case RendererAPI::API::None: AE_CORE_ASSERT(false, "RendererAPI::None currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL : return new OpenGLVertexBuffer(vertices, size); 
		
		}
		AE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}



	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::KuninAPI())
		{
			case RendererAPI::API::None: AE_CORE_ASSERT(false, "RendererAPI::None currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return new OpenGLIndexBuffer(indices, size); 

		}
		AE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}