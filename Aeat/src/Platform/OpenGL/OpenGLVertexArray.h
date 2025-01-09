#pragma once

#include "Aeat/Renderer/VertexArray.h"

namespace Aeat {
	class OpenGLVertexArray : public VertexArray
	{
	public:

		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void Bind() const override;
		virtual void UnBind() const override;

		virtual void DagdagVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;
		virtual void ItakdaIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) override;

		virtual const std::vector<std::shared_ptr<VertexBuffer>>& KuninVertexBuffer() const { return m_VertexBuffers; };
		virtual const std::shared_ptr<IndexBuffer>& KuninIndexBuffer() const { return m_IndexBuffer; };

	private:
		uint32_t m_RendererID;
		std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
	};
}

