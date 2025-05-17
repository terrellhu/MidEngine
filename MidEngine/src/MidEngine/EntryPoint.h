#pragma once

#ifdef ME_PLATFORM_WINDOWS

extern ME::Application* ME::CreateApplication();

int main(int arg, char** argv) {
	ME::Log::Init();

	ME_CORE_WARN("Initialized Log!");
	int a = 5;
	ME_INFO("Hello World! Var={0}", a);

	auto app = ME::CreateApplication();
	app->Run();
	delete app;
}

#endif