#pragma once

#include <memory>
#include "Buffer.h"

namespace Aeat {
	class VertexArray {
	public:

		virtual ~VertexArray() {}

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void DagdagVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) = 0;
		virtual void ItakdaIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) = 0;
		virtual const std::vector<std::shared_ptr<VertexBuffer>>& KuninVertexBuffer() const = 0;
		virtual const std::shared_ptr<IndexBuffer>& KuninIndexBuffer() const = 0;

		static VertexArray* Create();
	};
}

