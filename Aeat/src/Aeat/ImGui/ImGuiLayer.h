#pragma once

#include "../../Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include <../../../vendor/GLFW_new/include/GLFW/glfw3.h>
#include "../Layer.h"
#include "../Application.h"

namespace Aeat {
	class AEAT_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnDikit();
		void OnTanggalin();
		void OnHimaton();
		void OnPangyayari(Event& pangyayari);
	private:
		float m_Time = 0.0f;


	};
}

