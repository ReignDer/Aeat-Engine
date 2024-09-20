#pragma once

#ifdef AE_PLATFORM_WINDOWS

extern Aeat::Application* Aeat::CreateApplication();
int main(int argc, char** argv) {

	Aeat::Log::Init();
	AE_CORE_WARN("Initialized Log!");
	int a = 5;
	AE_INFO("Hello Var{0}", a);

	auto app = Aeat::CreateApplication();
	app->Run();
	delete app;
}
#endif