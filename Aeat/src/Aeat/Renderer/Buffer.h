#pragma once


namespace Aeat {

	enum class ShaderDataType {
		None = 0,
		Lutang,
		Lutang2,
		Lutang3,
		Lutang4,
		Mat3,
		Mat4,
		Int,
		Int2,
		Int3,
		Int4,
		Bool
	};

	static uint32_t ShaderDataTypeSize(ShaderDataType uri) {
		switch (uri) {
			case ShaderDataType::Lutang: return 4;
			case ShaderDataType::Lutang2: return 4 * 2;
			case ShaderDataType::Lutang3: return 4 * 3;
			case ShaderDataType::Lutang4: return 4 * 4;
			case ShaderDataType::Mat3: return 4 * 3 * 3;
			case ShaderDataType::Mat4: return 4 * 4 * 4;
			case ShaderDataType::Int: return 4;
			case ShaderDataType::Int2: return 4 * 2;
			case ShaderDataType::Int3: return 4 * 3;
			case ShaderDataType::Int4: return 4 * 4;
			case ShaderDataType::Bool: return 1;

		}
		AE_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}


	struct BufferElement {
		std::string Pangalan;
		ShaderDataType Uri;
		uint32_t Offset;
		uint32_t Laki;
		bool Normalized;

		BufferElement() {}
		BufferElement(ShaderDataType uri, const std::string& pangalan, bool normalized = 0)
			: Pangalan(pangalan), Uri(uri), Laki(ShaderDataTypeSize(uri)), Offset(0), Normalized(normalized) {

		}

		uint32_t KuninElementBilang() const {
			switch (Uri) {
				case ShaderDataType::Lutang:  return 1;
				case ShaderDataType::Lutang2: return 2;
				case ShaderDataType::Lutang3: return 3;
				case ShaderDataType::Lutang4: return 4;
				case ShaderDataType::Mat3:	  return 3 * 3;
				case ShaderDataType::Mat4:	  return 4 * 4;
				case ShaderDataType::Int:	  return 1;
				case ShaderDataType::Int2:	  return 2;
				case ShaderDataType::Int3:	  return 3;
				case ShaderDataType::Int4:	  return 4;
				case ShaderDataType::Bool:	  return 1;
			}
			AE_CORE_ASSERT(false, "Unknown ShaderDataType!");
			return 0;
		}
	};

	class BufferLayout {
	public:
		BufferLayout() {}
		BufferLayout(const std::initializer_list<BufferElement>& elemento)
			: m_Elements(elemento) {
			KalkulaOffsetAtStride();
		}

		inline uint32_t KuninStride() const { return m_Stride; }
		inline const std::vector<BufferElement>& GetElements() const { return m_Elements; }

		std::vector<BufferElement>::iterator begin() { return m_Elements.begin(); }
		std::vector<BufferElement>::iterator end() { return m_Elements.end(); }
		std::vector<BufferElement>::const_iterator begin() const { return m_Elements.begin(); }
		std::vector<BufferElement>::const_iterator end() const { return m_Elements.end(); }

	private:
		void KalkulaOffsetAtStride() {
			uint32_t offset = 0;
			m_Stride = 0;
			for (auto& elemento : m_Elements) {
				elemento.Offset = offset;
				offset += elemento.Laki;
				m_Stride += elemento.Laki;
			}
		}
	private:
		std::vector<BufferElement> m_Elements;
		uint32_t m_Stride = 0;
	};

	class VertexBuffer {
	public:

		virtual ~VertexBuffer() {}

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual const BufferLayout& KunintLayout() const = 0;
		virtual void ItakdaLayout(const BufferLayout& layout) = 0;

		static VertexBuffer* Create(float* vertices, uint32_t size);
	};

	class IndexBuffer {
	public:
		virtual ~IndexBuffer() {}

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual uint32_t GetCount() const = 0;

		static IndexBuffer* Create(uint32_t* indices, uint32_t size);
	};
}
