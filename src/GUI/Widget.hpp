#pragma once

#include "Core/PCH.hpp"
#include <functional>

/* 
Widget Needs:
    An Input event.
    Draw function.

*/


class Widget
{
    protected:
    std::function<void()> function;

    public:
    virtual ~Widget() = default;

    virtual void ProcessEvents(SDL_Event& p_Event);

    virtual void ProcessUpdate(float p_DeltaTime);

    virtual void ProcessRender(SDL_Renderer* p_Renderer);
};