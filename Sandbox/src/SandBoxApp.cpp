#include <Aeat.h>

class ExampleLayer : public Aeat::Layer {
public:
	ExampleLayer()
		: Layer("Example") {

	}

	void OnHimaton() override {
		AE_INFO("ExampleLayer::Upadate");
	}

	void OnPangyayari(Aeat::Event& event) override {
		AE_TRACE("{0}", event);
	}
};

class SandBox : public Aeat::Application {
public:
	SandBox()
	{
		TulakLayer(new ExampleLayer());
		TulakOverlay(new Aeat::ImGuiLayer());
	}
	~SandBox() {

	}
};

Aeat::Application* Aeat::CreateApplication() {
	return new SandBox();
}