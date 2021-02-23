#include "PlayScene.hpp"

#include "component/TagComponent.hpp"
#include "component/RectangleShapeComponent.hpp"
#include "component/PositionComponent.hpp"
#include "system/RenderRectShapeSystem.hpp"

PlayScene::PlayScene()
{
	// Add entities
	auto player = GetEntityManager().CreateEntity();
	GetEntityManager().GetRegistry().emplace_or_replace<TagComponent>(player, TagType::Player);
	GetEntityManager().GetRegistry()
		.emplace<RectangleShapeComponent>(player, SDL_Color{ 0, 255, 0, 255 }, glm::vec2(50, 50), SDL_Color{ 0, 0, 0,255 }, (int )5);
	GetEntityManager().GetRegistry().emplace<PositionComponent>(player, 100.0f, 100.0f);


	// Register systems
	GetSystemManager().RegisterSystem(new RenderRectShapeSystem());
}
