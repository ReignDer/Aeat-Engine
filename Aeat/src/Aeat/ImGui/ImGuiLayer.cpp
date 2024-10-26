#include "aepch.h"
#include "ImGuiLayer.h"

namespace Aeat {



	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::OnDikit()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		ImGui_ImplOpenGL3_Init("#version 460");

	}

	void ImGuiLayer::OnTanggalin()
	{
	}

	void ImGuiLayer::OnHimaton()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();

		io.DisplaySize = ImVec2(app.KuninWindow().KuninWidth(), app.KuninWindow().KuninHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnPangyayari(Event& pangyayari)
	{
		EventDispatcher dispatcher(pangyayari);
		dispatcher.Pagpapadala<MousePindutanPinindotEvent>(AE_BIND_EVENT_FN(ImGuiLayer::OnMousePindutanPinindotEvent));
		dispatcher.Pagpapadala<MousePindutanBinitawEvent>(AE_BIND_EVENT_FN(ImGuiLayer::OnMousePindutanBinitawEvent));
		dispatcher.Pagpapadala<MouseGumalawEvent>(AE_BIND_EVENT_FN(ImGuiLayer::OnMouseGumalawEvent));
		dispatcher.Pagpapadala<MouseNabalumbonEvent>(AE_BIND_EVENT_FN(ImGuiLayer::OnMouseNabalumbonEvent));
		dispatcher.Pagpapadala<KeyPinindotEvent>(AE_BIND_EVENT_FN(ImGuiLayer::OnKeyPinindotEvent));
		dispatcher.Pagpapadala<KeyBinitawEvent>(AE_BIND_EVENT_FN(ImGuiLayer::OnKeyBinitawEvent));
		dispatcher.Pagpapadala<KeyNagTypeEvent>(AE_BIND_EVENT_FN(ImGuiLayer::OnKeyNagTypeEvent));
		dispatcher.Pagpapadala<WindowPalitLakiEvent>(AE_BIND_EVENT_FN(ImGuiLayer::OnWindowPalitLakiEvent));
	}

	bool ImGuiLayer::OnMousePindutanPinindotEvent(MousePindutanPinindotEvent& pangyayari)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[pangyayari.KuninMousePindutan()] = true;
		return false;
	}

	bool ImGuiLayer::OnMousePindutanBinitawEvent(MousePindutanBinitawEvent& pangyayari)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[pangyayari.KuninMousePindutan()] = false;
		return false;
	}

	bool ImGuiLayer::OnMouseGumalawEvent(MouseGumalawEvent& pangyayari)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(pangyayari.KuninX(), pangyayari.KuninY());
		return false;
	}

	bool ImGuiLayer::OnMouseNabalumbonEvent(MouseNabalumbonEvent& pangyayari)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += pangyayari.KuninXOffset();
		io.MouseWheel += pangyayari.KuninYOffset();
		return false;
	}

	bool ImGuiLayer::OnKeyPinindotEvent(KeyPinindotEvent& pangyayari)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[pangyayari.KuninKeyKodigo()] = true;

		io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
		io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
		io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
		io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
		return false;
	}

	bool ImGuiLayer::OnKeyBinitawEvent(KeyBinitawEvent& pangyayari)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[pangyayari.KuninKeyKodigo()] = false;
		return false;
	}

	bool ImGuiLayer::OnKeyNagTypeEvent(KeyNagTypeEvent& pangyayari)
	{
		ImGuiIO& io = ImGui::GetIO();
		int keyKodigo = pangyayari.KuninKeyKodigo();

		if(keyKodigo >0 && keyKodigo < 0x10000)
			io.AddInputCharacter((unsigned int)keyKodigo);
		return false;
	}

	bool ImGuiLayer::OnWindowPalitLakiEvent(WindowPalitLakiEvent& pangyayari)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(pangyayari.KuninWidth(), pangyayari.KuninHaba());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		return false;

	}

}