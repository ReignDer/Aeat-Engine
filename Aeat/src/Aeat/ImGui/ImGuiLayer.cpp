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
        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
        //io.ConfigViewportsNoAutoMerge = true;
        //io.ConfigViewportsNoTaskBarIcon = true;

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        //ImGui::StyleColorsLight();

        // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
        ImGuiStyle& style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        Application& app = Application::Get();
        GLFWwindow* window = static_cast<GLFWwindow*>(app.KuninWindow().KuninNativeWindow());

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 460");

	}

	void ImGuiLayer::OnTanggalin()
	{
        // Cleanup
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
	}

	void ImGuiLayer::OnImGuiRender()
	{
		static bool show = true;
		ImGui::ShowDemoWindow(&show);

	}

    void ImGuiLayer::Simula()
    {
		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
    }

    void ImGuiLayer::Wakas()
    {
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		GLFWwindow* window = static_cast<GLFWwindow*>(app.KuninWindow().KuninNativeWindow());
		io.DisplaySize = ImVec2(app.KuninWindow().KuninWidth(), app.KuninWindow().KuninHeight());

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}
    }

	//void ImGuiLayer::OnPangyayari(Event& pangyayari)
	//{
	//	EventDispatcher dispatcher(pangyayari);
	//	dispatcher.Pagpapadala<MousePindutanPinindotEvent>(AE_BIND_EVENT_FN(ImGuiLayer::OnMousePindutanPinindotEvent));
	//	dispatcher.Pagpapadala<MousePindutanBinitawEvent>(AE_BIND_EVENT_FN(ImGuiLayer::OnMousePindutanBinitawEvent));
	//	dispatcher.Pagpapadala<MouseGumalawEvent>(AE_BIND_EVENT_FN(ImGuiLayer::OnMouseGumalawEvent));
	//	dispatcher.Pagpapadala<MouseNabalumbonEvent>(AE_BIND_EVENT_FN(ImGuiLayer::OnMouseNabalumbonEvent));
	//	dispatcher.Pagpapadala<KeyPinindotEvent>(AE_BIND_EVENT_FN(ImGuiLayer::OnKeyPinindotEvent));
	//	dispatcher.Pagpapadala<KeyBinitawEvent>(AE_BIND_EVENT_FN(ImGuiLayer::OnKeyBinitawEvent));
	//	dispatcher.Pagpapadala<KeyNagTypeEvent>(AE_BIND_EVENT_FN(ImGuiLayer::OnKeyNagTypeEvent));
	//	dispatcher.Pagpapadala<WindowPalitLakiEvent>(AE_BIND_EVENT_FN(ImGuiLayer::OnWindowPalitLakiEvent));
	//}

	//ImGuiKey ImGuiLayer::GlfwToImGuiKey(int keycode)
	//{ 
 //       switch (keycode)
 //       {
 //       case GLFW_KEY_TAB: return ImGuiKey_Tab;
 //           case GLFW_KEY_LEFT: return ImGuiKey_LeftArrow;
 //           case GLFW_KEY_RIGHT: return ImGuiKey_RightArrow;
 //           case GLFW_KEY_UP: return ImGuiKey_UpArrow;
 //           case GLFW_KEY_DOWN: return ImGuiKey_DownArrow;
 //           case GLFW_KEY_PAGE_UP: return ImGuiKey_PageUp;
 //           case GLFW_KEY_PAGE_DOWN: return ImGuiKey_PageDown;
 //           case GLFW_KEY_HOME: return ImGuiKey_Home;
 //           case GLFW_KEY_END: return ImGuiKey_End;
 //           case GLFW_KEY_INSERT: return ImGuiKey_Insert;
 //           case GLFW_KEY_DELETE: return ImGuiKey_Delete;
 //           case GLFW_KEY_BACKSPACE: return ImGuiKey_Backspace;
 //           case GLFW_KEY_SPACE: return ImGuiKey_Space;
 //           case GLFW_KEY_ENTER: return ImGuiKey_Enter;
 //           case GLFW_KEY_ESCAPE: return ImGuiKey_Escape;
 //           case GLFW_KEY_APOSTROPHE: return ImGuiKey_Apostrophe;
 //           case GLFW_KEY_COMMA: return ImGuiKey_Comma;
 //           case GLFW_KEY_MINUS: return ImGuiKey_Minus;
 //           case GLFW_KEY_PERIOD: return ImGuiKey_Period;
 //           case GLFW_KEY_SLASH: return ImGuiKey_Slash;
 //           case GLFW_KEY_SEMICOLON: return ImGuiKey_Semicolon;
 //           case GLFW_KEY_EQUAL: return ImGuiKey_Equal;
 //           case GLFW_KEY_LEFT_BRACKET: return ImGuiKey_LeftBracket;
 //           case GLFW_KEY_BACKSLASH: return ImGuiKey_Backslash;
 //           case GLFW_KEY_RIGHT_BRACKET: return ImGuiKey_RightBracket;
 //           case GLFW_KEY_GRAVE_ACCENT: return ImGuiKey_GraveAccent;
 //           case GLFW_KEY_CAPS_LOCK: return ImGuiKey_CapsLock;
 //           case GLFW_KEY_SCROLL_LOCK: return ImGuiKey_ScrollLock;
 //           case GLFW_KEY_NUM_LOCK: return ImGuiKey_NumLock;
 //           case GLFW_KEY_PRINT_SCREEN: return ImGuiKey_PrintScreen;
 //           case GLFW_KEY_PAUSE: return ImGuiKey_Pause;
 //           case GLFW_KEY_KP_0: return ImGuiKey_Keypad0;
 //           case GLFW_KEY_KP_1: return ImGuiKey_Keypad1;
 //           case GLFW_KEY_KP_2: return ImGuiKey_Keypad2;
 //           case GLFW_KEY_KP_3: return ImGuiKey_Keypad3;
 //           case GLFW_KEY_KP_4: return ImGuiKey_Keypad4;
 //           case GLFW_KEY_KP_5: return ImGuiKey_Keypad5;
 //           case GLFW_KEY_KP_6: return ImGuiKey_Keypad6;
 //           case GLFW_KEY_KP_7: return ImGuiKey_Keypad7;
 //           case GLFW_KEY_KP_8: return ImGuiKey_Keypad8;
 //           case GLFW_KEY_KP_9: return ImGuiKey_Keypad9;
 //           case GLFW_KEY_KP_DECIMAL: return ImGuiKey_KeypadDecimal;
 //           case GLFW_KEY_KP_DIVIDE: return ImGuiKey_KeypadDivide;
 //           case GLFW_KEY_KP_MULTIPLY: return ImGuiKey_KeypadMultiply;
 //           case GLFW_KEY_KP_SUBTRACT: return ImGuiKey_KeypadSubtract;
 //           case GLFW_KEY_KP_ADD: return ImGuiKey_KeypadAdd;
 //           case GLFW_KEY_KP_ENTER: return ImGuiKey_KeypadEnter;
 //           case GLFW_KEY_KP_EQUAL: return ImGuiKey_KeypadEqual;
 //           case GLFW_KEY_LEFT_SHIFT: return ImGuiKey_LeftShift;
 //           case GLFW_KEY_LEFT_CONTROL: return ImGuiKey_LeftCtrl;
 //           case GLFW_KEY_LEFT_ALT: return ImGuiKey_LeftAlt;
 //           case GLFW_KEY_LEFT_SUPER: return ImGuiKey_LeftSuper;
 //           case GLFW_KEY_RIGHT_SHIFT: return ImGuiKey_RightShift;
 //           case GLFW_KEY_RIGHT_CONTROL: return ImGuiKey_RightCtrl;
 //           case GLFW_KEY_RIGHT_ALT: return ImGuiKey_RightAlt;
 //           case GLFW_KEY_RIGHT_SUPER: return ImGuiKey_RightSuper;
 //           case GLFW_KEY_MENU: return ImGuiKey_Menu;
 //           case GLFW_KEY_0: return ImGuiKey_0;
 //           case GLFW_KEY_1: return ImGuiKey_1;
 //           case GLFW_KEY_2: return ImGuiKey_2;
 //           case GLFW_KEY_3: return ImGuiKey_3;
 //           case GLFW_KEY_4: return ImGuiKey_4;
 //           case GLFW_KEY_5: return ImGuiKey_5;
 //           case GLFW_KEY_6: return ImGuiKey_6;
 //           case GLFW_KEY_7: return ImGuiKey_7;
 //           case GLFW_KEY_8: return ImGuiKey_8;
 //           case GLFW_KEY_9: return ImGuiKey_9;
 //           case GLFW_KEY_A: return ImGuiKey_A;
 //           case GLFW_KEY_B: return ImGuiKey_B;
 //           case GLFW_KEY_C: return ImGuiKey_C;
 //           case GLFW_KEY_D: return ImGuiKey_D;
 //           case GLFW_KEY_E: return ImGuiKey_E;
 //           case GLFW_KEY_F: return ImGuiKey_F;
 //           case GLFW_KEY_G: return ImGuiKey_G;
 //           case GLFW_KEY_H: return ImGuiKey_H;
 //           case GLFW_KEY_I: return ImGuiKey_I;
 //           case GLFW_KEY_J: return ImGuiKey_J;
 //           case GLFW_KEY_K: return ImGuiKey_K;
 //           case GLFW_KEY_L: return ImGuiKey_L;
 //           case GLFW_KEY_M: return ImGuiKey_M;
 //           case GLFW_KEY_N: return ImGuiKey_N;
 //           case GLFW_KEY_O: return ImGuiKey_O;
 //           case GLFW_KEY_P: return ImGuiKey_P;
 //           case GLFW_KEY_Q: return ImGuiKey_Q;
 //           case GLFW_KEY_R: return ImGuiKey_R;
 //           case GLFW_KEY_S: return ImGuiKey_S;
 //           case GLFW_KEY_T: return ImGuiKey_T;
 //           case GLFW_KEY_U: return ImGuiKey_U;
 //           case GLFW_KEY_V: return ImGuiKey_V;
 //           case GLFW_KEY_W: return ImGuiKey_W;
 //           case GLFW_KEY_X: return ImGuiKey_X;
 //           case GLFW_KEY_Y: return ImGuiKey_Y;
 //           case GLFW_KEY_Z: return ImGuiKey_Z;
 //           case GLFW_KEY_F1: return ImGuiKey_F1;
 //           case GLFW_KEY_F2: return ImGuiKey_F2;
 //           case GLFW_KEY_F3: return ImGuiKey_F3;
 //           case GLFW_KEY_F4: return ImGuiKey_F4;
 //           case GLFW_KEY_F5: return ImGuiKey_F5;
 //           case GLFW_KEY_F6: return ImGuiKey_F6;
 //           case GLFW_KEY_F7: return ImGuiKey_F7;
 //           case GLFW_KEY_F8: return ImGuiKey_F8;
 //           case GLFW_KEY_F9: return ImGuiKey_F9;
 //           case GLFW_KEY_F10: return ImGuiKey_F10;
 //           case GLFW_KEY_F11: return ImGuiKey_F11;
 //           case GLFW_KEY_F12: return ImGuiKey_F12;
 //           case GLFW_KEY_F13: return ImGuiKey_F13;
 //           case GLFW_KEY_F14: return ImGuiKey_F14;
 //           case GLFW_KEY_F15: return ImGuiKey_F15;
 //           case GLFW_KEY_F16: return ImGuiKey_F16;
 //           case GLFW_KEY_F17: return ImGuiKey_F17;
 //           case GLFW_KEY_F18: return ImGuiKey_F18;
 //           case GLFW_KEY_F19: return ImGuiKey_F19;
 //           case GLFW_KEY_F20: return ImGuiKey_F20;
 //           case GLFW_KEY_F21: return ImGuiKey_F21;
 //           case GLFW_KEY_F22: return ImGuiKey_F22;
 //           case GLFW_KEY_F23: return ImGuiKey_F23;
 //           case GLFW_KEY_F24: return ImGuiKey_F24;
 //           default: return ImGuiKey_None;
 //       }
	//}

	//bool ImGuiLayer::OnMousePindutanPinindotEvent(MousePindutanPinindotEvent& pangyayari)
	//{
	//	ImGuiIO& io = ImGui::GetIO();
	//	io.MouseDown[pangyayari.KuninMousePindutan()] = true;
	//	return false;
	//}

	//bool ImGuiLayer::OnMousePindutanBinitawEvent(MousePindutanBinitawEvent& pangyayari)
	//{
	//	ImGuiIO& io = ImGui::GetIO();
	//	io.AddMouseButtonEvent(pangyayari.KuninMousePindutan(), false);
	//	return false;
	//}

	//bool ImGuiLayer::OnMouseGumalawEvent(MouseGumalawEvent& pangyayari)
	//{
	//	ImGuiIO& io = ImGui::GetIO();
	//	io.AddMousePosEvent(pangyayari.KuninX(), pangyayari.KuninY());
	//	return false;
	//}

	//bool ImGuiLayer::OnMouseNabalumbonEvent(MouseNabalumbonEvent& pangyayari)
	//{
	//	ImGuiIO& io = ImGui::GetIO();
	//	io.AddMouseWheelEvent(pangyayari.KuninXOffset(), pangyayari.KuninYOffset());
	//	//io.MouseWheelH += pangyayari.KuninXOffset();
	//	//io.MouseWheel += pangyayari.KuninYOffset();
	//	return false;
	//}

	//bool ImGuiLayer::OnKeyPinindotEvent(KeyPinindotEvent& pangyayari)
	//{
	//	ImGuiIO& io = ImGui::GetIO();
	//	
	//	//ImGuiKey imgui_key = ImGui_ImplGlfw_KeyToImGuiKey(pangyayari.KuninKeyKodigo(), -1);
	//	io.AddKeyEvent(GlfwToImGuiKey(pangyayari.KuninKeyKodigo()), true);
 //       io.AddKeyEvent(ImGuiMod_Ctrl, (pangyayari.KuninKeyKodigo() == GLFW_KEY_LEFT_CONTROL) || pangyayari.KuninKeyKodigo() == GLFW_KEY_RIGHT_CONTROL);
 //       io.AddKeyEvent(ImGuiMod_Shift, (pangyayari.KuninKeyKodigo() == GLFW_KEY_LEFT_SHIFT) || pangyayari.KuninKeyKodigo() == GLFW_KEY_RIGHT_SHIFT);
 //       io.AddKeyEvent(ImGuiMod_Alt, (pangyayari.KuninKeyKodigo() == GLFW_KEY_LEFT_ALT) || pangyayari.KuninKeyKodigo() == GLFW_KEY_RIGHT_ALT);
 //       io.AddKeyEvent(ImGuiMod_Super, (pangyayari.KuninKeyKodigo() == GLFW_KEY_LEFT_SUPER) || pangyayari.KuninKeyKodigo() == GLFW_KEY_RIGHT_SUPER);
	//	/*io.KeysDown[pangyayari.KuninKeyKodigo()] = true;
	//	io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
	//	io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
	//	io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
	//	io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER]*/;

	//	return false;
	//}

	//bool ImGuiLayer::OnKeyBinitawEvent(KeyBinitawEvent& pangyayari)
	//{
	//	ImGuiIO& io = ImGui::GetIO();
	//	io.AddKeyEvent(GlfwToImGuiKey(pangyayari.KuninKeyKodigo()), false);
	//	//io.KeysDown[pangyayari.KuninKeyKodigo()] = false;
	//	return false;
	//}

	//bool ImGuiLayer::OnKeyNagTypeEvent(KeyNagTypeEvent& pangyayari)
	//{
	//	ImGuiIO& io = ImGui::GetIO();
	//	int keyKodigo = pangyayari.KuninKeyKodigo();

	//	if(keyKodigo >0 && keyKodigo < 0x10000)
	//		io.AddInputCharacter((unsigned int)keyKodigo);
	//	return false;
	//}

	//bool ImGuiLayer::OnWindowPalitLakiEvent(WindowPalitLakiEvent& pangyayari)
	//{
	//	ImGuiIO& io = ImGui::GetIO();
	//	io.DisplaySize = ImVec2(pangyayari.KuninWidth(), pangyayari.KuninHaba());
	//	io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
	//	return false;

	//}

}