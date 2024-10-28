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

		glGenVertexArrays(1,&m_VertexArray);
		glBindVertexArray(m_VertexArray);

		glGenBuffers(1, &m_VertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);

		float vertices[3 * 3] = {
			-0.5f,-0.5f,0.0f,
			0.5f, -0.5f,0.0f,
			0.0f,0.5f,0.0f
		};

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 *sizeof(float), nullptr);

		glGenBuffers(1, &m_IndexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);

		unsigned int indices[3] = { 0,1,2 };
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		std::string vertexSrc = R"(
			#version 460 core
			
			layout(location = 0) in vec3 a_Position;
			
			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = vec4(a_Position,1.0);

			}

		)";

		std::string fragmentSrc = R"(
			#version 460 core
			
			layout(location = 0) out vec4 color;
			
			in vec3 v_Position;

			void main(){
				color = vec4(v_Position * 0.5 + 0.5,1.0);

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
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

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