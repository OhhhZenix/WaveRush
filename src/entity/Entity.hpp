#pragma once

#include "../component/PositionComponent.hpp"
#include "../component/RectangleShapeComponent.hpp"

class Entity
{
    protected:
        RectangleShapeComponent m_Shape;
        PositionComponent m_Position;

    public:
        void Render(SDL_Renderer *p_Renderer)
        {
            /*
            SDL_SetRenderDrawColor(
                p_Renderer,
                m_Shape.OutlineColor.r,
                m_Shape.OutlineColor.g,
                m_Shape.OutlineColor.b,
                m_Shape.OutlineColor.a
                );
            */
            SDL_SetRenderDrawColor(
                p_Renderer,
                m_Shape.Color.r,
                m_Shape.Color.g,
                m_Shape.Color.b,
                m_Shape.Color.a
                );

            SDL_Rect f_Rect = {
                m_Position.X,
                m_Position.Y,
                m_Shape.Size.x,
                m_Shape.Size.y
            };

            SDL_RenderFillRect(p_Renderer, &f_Rect);
        }

        virtual void Update(float p_DeltaTime);

        virtual void ProcessEvents(SDL_Event& event);

};