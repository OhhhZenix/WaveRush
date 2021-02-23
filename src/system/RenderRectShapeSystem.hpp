#pragma once

#include "system/System.hpp"

class RenderRectShapeSystem : public System {
 public:
	void ProcessRender(SDL_Renderer *p_Renderer, entt::registry &p_Registry) override;
};