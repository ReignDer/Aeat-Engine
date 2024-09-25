#pragma once

#include "../Layer.h"

namespace Aeat {
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnDikit();
		void OnTanggalin();
		void OnHimaton();
		void OnPangyayari(Event& pangyayari);
	private:



	};
}

