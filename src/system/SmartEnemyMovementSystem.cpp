#include "SmartEnemyMovementSystem.hpp"

#include "component/TagComponent.hpp"
#include "component/RectangleShapeComponent.hpp"

void SmartEnemyMovementSystem::ProcessUpdate(float p_DeltaTime, entt::registry& p_Registry)
{
	auto f_View = p_Registry.view<const TagComponent, RectangleShapeComponent>();
}
