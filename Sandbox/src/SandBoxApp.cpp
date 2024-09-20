#include <Aeat.h>

class SandBox : public Aeat::Application {
public:
	SandBox()
	{

	}
	~SandBox() {

	}
};

Aeat::Application* Aeat::CreateApplication() {
	return new SandBox();
}