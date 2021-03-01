#pragma once

#include <functional>
#include "Core/PCH.hpp"

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
        virtual void ProcessEvents(SDL_Event& p_Event) = 0;

	    virtual void ProcessUpdate(float p_DeltaTime) = 0;

	    virtual void ProcessRender(SDL_Renderer* p_Renderer) = 0;
};