#pragma once

#include "MidEngine/Layer.h"

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
		float m_Time = 0.0f;
		ImGuiKey ImGui_ImplGlfw_KeyToImGuiKey(int keycode, int scancode);
	};

}
