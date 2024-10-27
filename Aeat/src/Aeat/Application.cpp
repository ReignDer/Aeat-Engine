#include "aepch.h"
#include "Application.h"

namespace Aeat {
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{

		//AE_CORE_ASSERT(s_Instance, "Application already exists!");
		s_Instance = this;


		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->ItakdaEventCallback(BIND_EVENT_FN(Application::OnHimaton));
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

		AE_CORE_INFO("{0}", e);

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
			glClearColor(1,0,1,1);
			glClear(GL_COLOR_BUFFER_BIT);
			for (Layer* layer : m_LayerPatong)
				layer->OnHimaton();

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