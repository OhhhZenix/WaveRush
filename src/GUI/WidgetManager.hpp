#pragma once

#include "Core/PCH.hpp"
#include "GUI/Widget.hpp"
#include <vector>

class WidgetManager
{
    private:
        std::vector<Widget*> m_WidgetList;

    public:
        Widget *AddWidget(Widget *p_Widget);

        void RemoveWidget(Widget *p_Widget);

        std::vector<Widget*>& GetWidgets();

        void ProcessEvents(SDL_Event& p_Event);

	    void ProcessUpdate(float p_DeltaTime);

	    void ProcessRender(SDL_Renderer* p_Renderer);
};