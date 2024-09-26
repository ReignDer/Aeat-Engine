#include "aepch.h"
#include "LayerStack.h"

namespace Aeat {
	LayerStack::LayerStack()
	{
		m_LayerIpasok = m_Layers.begin();
	}
	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
			delete layer;
	}
	void LayerStack::TulakLayer(Layer* layer)
	{
		m_LayerIpasok = m_Layers.emplace(m_LayerIpasok, layer);
		layer->OnDikit();
	}
	void LayerStack::TulakOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
		overlay->OnDikit();

	}
	void LayerStack::PutokLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.begin(), layer);

		if (it != m_Layers.end()) {
			m_Layers.erase(it);
			m_LayerIpasok--;
		}
	}
	void LayerStack::PutokOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.begin(), overlay);

		if (it != m_Layers.end()) {
			m_Layers.erase(it);
		}
	}
}