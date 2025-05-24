#include <MidEngine.h>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi

glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
{
	glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	return Projection * View * Model;
}

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