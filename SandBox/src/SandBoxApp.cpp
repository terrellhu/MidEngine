#include <MidEngine.h>

class ExampleLayer : public ME::Layer
{
public:
    ExampleLayer()
		: Layer("Example")
	{

	}
	void OnUpdate() override
	{
		//ME_INFO("ExampleLayer::Update");
		if (ME::Input::IsKeyPressed(ME_KEY_TAB))
			ME_INFO("Tab key is pressed");
	}

	void OnEvent(ME::Event& event) override
	{
		if (event.GetEventType() == ME::EventType::KeyPressed)
		{
			ME::KeyPressedEvent& e = (ME::KeyPressedEvent&)event;
            ME_INFO("{0}", (char)e.GetKeyCode());
		}
	}
};

class SandBox : public ME::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new ME::ImGuiLayer());
	}

	~SandBox()
	{

	}
};

ME::Application* ME::CreateApplication()
{
	return new SandBox();
}