#include "aepch.h"
#include "OpenGLVertexArray.h"


#include <glad/glad.h>
namespace Aeat {

	static GLenum ShaderDataTypePapuntangOpenGLBaseType(ShaderDataType uri) {
		switch (uri)
		{
			case Aeat::ShaderDataType::None:		return GL_FLOAT;
			case Aeat::ShaderDataType::Lutang:		return GL_FLOAT;
			case Aeat::ShaderDataType::Lutang2:		return GL_FLOAT;
			case Aeat::ShaderDataType::Lutang3:		return GL_FLOAT;
			case Aeat::ShaderDataType::Lutang4:		return GL_FLOAT;
			case Aeat::ShaderDataType::Mat3:		return GL_FLOAT;
			case Aeat::ShaderDataType::Mat4:		return GL_FLOAT;
			case Aeat::ShaderDataType::Int:			return GL_INT;
			case Aeat::ShaderDataType::Int2:		return GL_INT;
			case Aeat::ShaderDataType::Int3:		return GL_INT;
			case Aeat::ShaderDataType::Int4:		return GL_INT;
			case Aeat::ShaderDataType::Bool:		return GL_BOOL;
		}
		AE_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray() 
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}


	void OpenGLVertexArray::Bind() const 
	{
		glBindVertexArray(m_RendererID);
	}
	void OpenGLVertexArray::UnBind() const 
	{
		glBindVertexArray(0);
	}


	void OpenGLVertexArray::DagdagVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
	{
		AE_CORE_ASSERT(vertexBuffer->KunintLayout().GetElements().size(), "Vertex Buffer No Layout!");

		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();


		uint32_t index = 0;

		const auto& layout = vertexBuffer->KunintLayout();

		for (const auto& elemento : layout) {
			AE_CORE_TRACE("Element Count: {0}", elemento.KuninElementBilang());
			AE_CORE_TRACE("Type: {0}", ShaderDataTypePapuntangOpenGLBaseType(elemento.Uri));
			AE_CORE_TRACE("Normalized: {0}", elemento.Normalized ? GL_TRUE : GL_FALSE);
			AE_CORE_TRACE("Element Count: {0}", elemento.KuninElementBilang());
			AE_CORE_TRACE("Stride: {0}", layout.KuninStride());
			AE_CORE_TRACE("Offset: {0}", elemento.Offset);
			glEnableVertexAttribArray(index);

			glVertexAttribPointer(index,
				elemento.KuninElementBilang(),
				ShaderDataTypePapuntangOpenGLBaseType(elemento.Uri),
				elemento.Normalized ? GL_TRUE : GL_FALSE,
				layout.KuninStride(),
				(const void*)elemento.Offset);
			index++;
		}

		m_VertexBuffers.push_back(vertexBuffer);
	}
	void OpenGLVertexArray::ItakdaIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;
	}
}
