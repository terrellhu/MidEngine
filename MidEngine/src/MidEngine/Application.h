#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace ME {
	class ME_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// define in client
	Application* CreateApplication();
}

