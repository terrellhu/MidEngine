#pragma once

#include "MidEngine/Layer.h"
#include "MidEngine/Events/KeyEvent.h"
#include "MidEngine/Events/MouseEvent.h"
#include "MidEngine/Events/ApplicationEvent.h"

enum ImGuiKey;

namespace ME {
	class ME_API ImGuiLayer: public Layer
	{
	public:
        ImGuiLayer();
        ~ImGuiLayer();

		void OnAttach();
        void OnDetach();
        void OnUpdate();
		void OnEvent(Event& event);
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
        bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);
		ImGuiKey ImGui_ImplGlfw_KeyToImGuiKey(int keycode, int scancode);
	private:
		float m_Time = 0.0f;
		
	};

}
