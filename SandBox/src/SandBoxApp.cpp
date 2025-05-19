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
	}

	void OnEvent(ME::Event& event) override
	{
		ME_INFO("{0}", event);
	}
};

class SandBox : public ME::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
	}

	~SandBox()
	{

	}
};

ME::Application* ME::CreateApplication()
{
	return new SandBox();
}