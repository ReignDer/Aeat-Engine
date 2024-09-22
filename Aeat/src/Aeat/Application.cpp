#include "aepch.h"
#include "Application.h"

namespace Aeat {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
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
			m_Window->OnHimaton();
		}
	}
}