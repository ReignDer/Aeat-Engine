#pragma once

#ifdef AE_PLATFORM_WINDOWS

extern Aeat::Application* Aeat::CreateApplication();
int main(int argc, char** argv) {
	printf("Aeat Engine");
	auto app = Aeat::CreateApplication();
	app->Run();
	delete app;
}
#endif