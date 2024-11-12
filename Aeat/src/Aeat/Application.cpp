#include "aepch.h"

#include <glad/glad.h>

#include "Application.h"



namespace Aeat {
	Application* Application::s_Instance = nullptr;

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

	Application::Application()
	{

		//AE_CORE_ASSERT(s_Instance, "Application already exists!");
		s_Instance = this;


		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->ItakdaEventCallback(BIND_EVENT_FN(Application::OnHimaton));

		m_ImGuiLayer = new ImGuiLayer;

		TulakOverlay(m_ImGuiLayer);

		glGenVertexArrays(1,&m_VertexArray);
		glBindVertexArray(m_VertexArray);

		

		float vertices[3 * 7] = {
			-0.5f,-0.5f,0.0f, 1.0f,0.0f,1.0f,1.0f,
			0.5f, -0.5f,0.0f, 1.0f,0.0f,1.0f,1.0f,
			0.0f,0.5f,0.0f, 1.0f,0.0f,1.0f,1.0f
		};

		m_VertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

		{
			BufferLayout layout = {
				{ShaderDataType::Lutang3, "a_Position"},
				{ShaderDataType::Lutang4, "a_Color"}
			};

			m_VertexBuffer->ItakdaLayout(layout);
		}

		uint32_t index = 0;

		const auto& layout = m_VertexBuffer->KunintLayout();

		for(const auto& elemento : layout){
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
				(const void*) elemento.Offset);
			index++;
		}

		

		uint32_t indices[3] = { 0,1,2 };
		m_IndexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));

		std::string vertexSrc = R"(
			#version 460 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;
		
			
			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = vec4(a_Position,1.0);

			}

		)";

		std::string fragmentSrc = R"(
			#version 460 core
			
			layout(location = 0) out vec4 color;
			
			in vec3 v_Position;
			in vec4 v_Color;

			void main(){
				color = vec4(v_Position * 0.5 + 0.5,1.0);
				color = v_Color;

			}

		)";

		m_Shader.reset(new Shader(vertexSrc,fragmentSrc));
	}

	Application::~Application()
	{
	}

	void Application::TulakLayer(Layer* layer)
	{
		m_LayerPatong.TulakLayer(layer);
	}

	void Application::TulakOverlay(Layer* overlay)
	{
		m_LayerPatong.TulakLayer(overlay);
	}

	void Application::OnHimaton(Event& e)
	{
		EventDispatcher  dispatcher(e);
		dispatcher.Pagpapadala<WindowSaradoEvent>(BIND_EVENT_FN(Application::OnWindowSarado));

		/*AE_CORE_INFO("{0}", e);*/

		for (auto it = m_LayerPatong.end(); it != m_LayerPatong.begin();) {
			(*--it)->OnPangyayari(e);
			if (e.NaHandle())
				break;
		}

	}

	void Application::Run()
	{
		/*WindowPalitLakiEvent e(1280, 720);

		if (e.NasaCategory(EventCategoryApplikasyon)) {
			AE_TRACE(e);
		}
		if (e.NasaCategory(EventCategoryPampasok)) {
			AE_TRACE(e);
		}*/

		while (m_Tumatakbo) {
			glClearColor(0.15f,0.15f,0.15f,1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Shader->Bind();
			glBindVertexArray(m_VertexArray);
			glDrawElements(GL_TRIANGLES, m_IndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

			for (Layer* layer : m_LayerPatong)
				layer->OnHimaton();

			m_ImGuiLayer->Simula();

			for (Layer* layer : m_LayerPatong)
				layer->OnImGuiRender();

			m_ImGuiLayer->Wakas();
			
			/*auto [x, y] = Input::KuninMousePosition();
			AE_CORE_TRACE("{0}, {1}", x, y);*/

			m_Window->OnHimaton();
		}
	}

	bool Application::OnWindowSarado(WindowSaradoEvent& e) {
		m_Tumatakbo = false;
		return true;
	}
	
}