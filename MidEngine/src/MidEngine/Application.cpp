#include "mepch.h"
#include "Application.h"
#include "MidEngine/Events/ApplicationEvent.h"
#include "MidEngine/Log.h"

namespace ME {

	Application::Application()
	{

	}


	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		ME_TRACE(e.ToString());

		while (true)
		{

		}
	}
}