#pragma once

#include "Core.h"
#include "Layer.h"

#include <vector>

namespace Aeat {
	class AEAT_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void TulakLayer(Layer* layer);
		void TulakOverlay(Layer* overlay);
		void PutokLayer(Layer* layer);
		void PutokOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerIpasok;

	};
}

