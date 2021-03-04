#pragma once

#include <functional>
#include "Core/PCH.hpp"
#include "Math/Vec2.hpp"

class Widget
{
    protected:
        Vec2f m_Position;

    public:
        explicit Widget() = default;

        virtual void ProcessEvents(SDL_Event& p_Event) = 0;

	    virtual void ProcessUpdate(float p_DeltaTime) = 0;

	    virtual void ProcessRender(SDL_Renderer* p_Renderer) = 0;
};