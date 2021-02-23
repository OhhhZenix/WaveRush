#include "RenderRectShapeSystem.hpp"

#include "component/RectangleShapeComponent.hpp"
#include "component/PositionComponent.hpp"

void RenderRectShapeSystem::ProcessRender(SDL_Renderer* p_Renderer, entt::registry& p_Registry)
{
	auto f_View = p_Registry.view<PositionComponent, RectangleShapeComponent>();
	f_View.each([p_Renderer](PositionComponent& f_Position, RectangleShapeComponent& f_RectShape)
	{
		SDL_Rect f_Rect{ (int)f_Position.X, (int)f_Position.Y, (int)f_Position.X, (int)f_Position.Y };

		if (f_RectShape.OutlineThickness > 0)
		{
			SDL_Rect f_Outline{ static_cast<int>(f_Rect.x - f_RectShape.OutlineThickness),
								static_cast<int>(f_Rect.y - f_RectShape.OutlineThickness),
								static_cast<int>(f_Rect.w + (f_RectShape.OutlineThickness * 2)),
								static_cast<int>(f_Rect.h + (f_RectShape.OutlineThickness * 2)) };
			SDL_SetRenderDrawColor(p_Renderer, f_RectShape.OutlineColor.r, f_RectShape.OutlineColor.g, f_RectShape.OutlineColor.b, f_RectShape.OutlineColor.a);
			SDL_RenderFillRect(p_Renderer, &f_Outline);
		}

		SDL_SetRenderDrawColor(p_Renderer, f_RectShape.Color.r, f_RectShape.Color.g, f_RectShape.Color.b, f_RectShape.Color.a);
		SDL_RenderFillRect(p_Renderer, &f_Rect);
	});
}
