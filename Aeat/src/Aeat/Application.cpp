#include "aepch.h"

#include <glad/glad.h>

#include "Application.h"



namespace Aeat {
	Application* Application::s_Instance = nullptr;

	

	Application::Application()
	{

		//AE_CORE_ASSERT(s_Instance, "Application already exists!");
		s_Instance = this;


		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->ItakdaEventCallback(BIND_EVENT_FN(Application::OnHimaton));

		m_ImGuiLayer = new ImGuiLayer;

		TulakOverlay(m_ImGuiLayer);	

		m_VertexArray.reset(VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f,-0.5f,0.0f, 1.0f,0.0f,1.0f,1.0f,
			0.5f, -0.5f,0.0f, 0.0f,1.0f,1.0f,1.0f,
			0.0f,0.5f,0.0f, 1.0f,1.0f,0.0f,1.0f
		};

		std::shared_ptr<VertexBuffer> vertexBuffer;
		vertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

		BufferLayout layout = {
			{ShaderDataType::Lutang3, "a_Position"},
			{ShaderDataType::Lutang4, "a_Color"}
		};

		vertexBuffer->ItakdaLayout(layout);

		m_VertexArray->DagdagVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0,1,2 };

		std::shared_ptr<IndexBuffer> indexBuffer;
		indexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->ItakdaIndexBuffer(indexBuffer);


		m_ParisukatVA.reset(VertexArray::Create());

		float parisukatVertices[3 * 4] = {
			-0.75f,-0.75f,0.0f,
			0.75f, -0.75f,0.0f,
			0.75f, 0.75f, 0.0f,
			-0.75f, 0.75f, 0.0f
		};

		std::shared_ptr<VertexBuffer> parisukatVB;
		parisukatVB.reset(VertexBuffer::Create(parisukatVertices, sizeof(parisukatVertices)));
		parisukatVB->ItakdaLayout({
			{ ShaderDataType::Lutang3, "a_Position" }
			});

		m_ParisukatVA->DagdagVertexBuffer(parisukatVB);


		uint32_t parisukatIndices[6] = { 0,1,2,2,3,0 };
		std::shared_ptr<IndexBuffer> parisukatIB;
		parisukatIB.reset(IndexBuffer::Create(parisukatIndices, sizeof(parisukatIndices)/sizeof(uint32_t)));
		m_ParisukatVA->ItakdaIndexBuffer(parisukatIB);


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

		std::string parisukatVertexSrc = R"(
			#version 460 core
			
			layout(location = 0) in vec3 a_Position;
		
			
			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = vec4(a_Position,1.0);

			}

		)";

		std::string parisukatFragmentSrc = R"(
			#version 460 core
			
			layout(location = 0) out vec4 color;
			
			in vec3 v_Position;

			void main(){
				color = vec4(0.2, 0.3, 0.8, 1.0);

			}

		)";

		m_BughawShader.reset(new Shader(parisukatVertexSrc, parisukatFragmentSrc));



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

			m_BughawShader->Bind();
			m_ParisukatVA->Bind();
			glDrawElements(GL_TRIANGLES, m_ParisukatVA->KuninIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);

			m_Shader->Bind();
			m_VertexArray->Bind();
			glDrawElements(GL_TRIANGLES, m_VertexArray->KuninIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);

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