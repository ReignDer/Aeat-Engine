#include <Aeat.h>

class ExampleLayer : public Aeat::Layer {
public:
	ExampleLayer()
		: Layer("Example") {

	}

	void OnHimaton() override {
		if(Aeat::Input::NapindotKey(AE_KEY_TAB)) {
			AE_TRACE("TAB Key is Pressed!");
		}
	}

	virtual void OnImGuiRender() override {

		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnPangyayari(Aeat::Event& event) override {
		if (event.KuninEventType() == Aeat::EventType::KeyPinindot) {
			Aeat::KeyPinindotEvent& e = (Aeat::KeyPinindotEvent&)event;
			AE_TRACE("{0}", (char)e.KuninKeyKodigo());
		}
	}
};

class SandBox : public Aeat::Application {
public:
	SandBox()
	{
		TulakLayer(new ExampleLayer());
	}
	~SandBox() {

	}
};

Aeat::Application* Aeat::CreateApplication() {
	return new SandBox();
}