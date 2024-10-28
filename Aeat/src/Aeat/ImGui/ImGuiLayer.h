#pragma once

#include <../../../vendor/imgui/backends/imgui_impl_opengl3.h>
#include <../../../vendor/imgui/backends/imgui_impl_glfw.h>

#include "../Layer.h"
#include "../Application.h"
#include "../Events/KeyEvent.h"
#include "../Events/MouseEvent.h"
#include "../Events/ApplicationEvent.h"

#include <../../../vendor/GLFW_new/include/GLFW/glfw3.h>
namespace Aeat {
	class AEAT_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnDikit() override;
		virtual void OnTanggalin() override;
		virtual void OnImGuiRender() override;

		void Simula();
		void Wakas();


	private:
		float m_Time = 0.0f;


	};
}

