#include "GUI/WidgetManager.hpp"

WidgetManager::~WidgetManager() {
	if (!m_WidgetList.empty()) {
		for (Widget* f_Widget : m_WidgetList) {
			delete f_Widget;
		}
		m_WidgetList.clear();
	}
}

Widget* WidgetManager::AddWidget(Widget* p_Widget) {
	m_WidgetList.emplace_back(p_Widget);
	return p_Widget;
}

void WidgetManager::RemoveWidget(Widget* p_Widget) {
	auto f_Iterator = std::find(m_WidgetList.begin(), m_WidgetList.end(), p_Widget);
	if (f_Iterator != m_WidgetList.end()) {
		delete p_Widget;
		m_WidgetList.erase(f_Iterator);
	}
}

std::vector<Widget*>& WidgetManager::GetWidgets() {
	return m_WidgetList;
}

void WidgetManager::ProcessEvents(SDL_Event& p_Event) {
	if (m_WidgetList.empty()) {
		return;
	}

	for (Widget* f_Widget : m_WidgetList) {
		f_Widget->ProcessEvents(p_Event);
	}
}

void WidgetManager::ProcessUpdate(float p_DeltaTime) {
	if (m_WidgetList.empty()) {
		return;
	}

	for (Widget* f_Widget : m_WidgetList) {
		f_Widget->ProcessUpdate(p_DeltaTime);
	}
}

void WidgetManager::ProcessRender(SDL_Renderer* p_Renderer) {
	if (m_WidgetList.empty()) {
		return;
	}

	for (Widget* f_Widget : m_WidgetList) {
		f_Widget->ProcessRender(p_Renderer);
	}
}