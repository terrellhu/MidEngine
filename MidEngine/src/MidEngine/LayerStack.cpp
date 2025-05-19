#include "mepch.h"
#include "LayerStack.h"

namespace ME {
	ME::LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}

	ME::LayerStack::~LayerStack()
	{
		for (auto layer : m_Layers)
		{
			delete layer;
		}
	}

	void ME::LayerStack::PushLayer(Layer* layer)
	{
        m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
	}

	void ME::LayerStack::PushOverlay(Layer* overlay)
	{
        m_Layers.emplace_back(overlay);
	}

	void ME::LayerStack::PopLayer(Layer* layer)
	{
        auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
        if (it != m_Layers.end())
        {
            m_Layers.erase(it);
            m_LayerInsert--;
        }
	}

	void ME::LayerStack::PopOverlay(Layer* overlay)
	{
        auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
        if (it != m_Layers.end())
            m_Layers.erase(it);
	}

}