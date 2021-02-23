#include "PlayerMovementSystem.hpp"

#include "component/TagComponent.hpp"
#include "component/PositionComponent.hpp"

void PlayerMovementSystem::ProcessUpdate(float p_DeltaTime, entt::registry& p_Registry)
{
	auto f_View = p_Registry.view<const TagComponent, PositionComponent>();
	f_View.each([](const TagComponent& f_Tag, PositionComponent& f_Position)
	{
		if (f_Tag.Value != TagType::Player)
			return;
		printf("Position %f\n", f_Position.X);
		f_Position.X++;
	});
}
