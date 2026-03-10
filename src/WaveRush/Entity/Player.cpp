#include "WaveRush/Entity/Player.hpp"

#include "WaveRush/Game.hpp"

namespace WaveRush {

auto CreatePlayer(Game& game) -> void {
    auto player = game.GetEntityManager().CreateEntity();
    auto& tag = game.GetEntityManager().GetTag(player);
    tag.value = EntityTag::Player;
    auto& pos = game.GetEntityManager().GetPosition(player);
    pos.x = 100;
    pos.y = 100;
}

} // namespace WaveRush