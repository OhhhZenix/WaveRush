#include "WaveRush/Scene/PlayScene.hpp"

#include <raylib.h>

#include "WaveRush/Constants.hpp"
#include "WaveRush/Entity/Bouncer.hpp"
#include "WaveRush/Entity/Player.hpp"
#include "WaveRush/Game.hpp"
#include "WaveRush/Widget.hpp"
#include "WaveRush/Widget/Button.hpp"
#include "WaveRush/Widget/Label.hpp"

namespace WaveRush {

PlayScene::PlayScene() {
    auto& player = entity_manager.AddEntity<Player>();
    player.SetX((GAME_WIDTH - player.GetWidth()) / 2);
    player.SetY((GAME_HEIGHT - player.GetHeight()) / 2);

    auto& bouncer = entity_manager.AddEntity<Bouncer>();
    bouncer.SetX(20);
    bouncer.SetY(20);
    bouncer.SetVelocityX(5);
    bouncer.SetVelocityY(5);

    auto& pause_label = widget_manager.AddWidget<Label>();
    pause_label.SetText("Paused");
    pause_label.SetFontSize(48);
    pause_label.SetX((GAME_WIDTH - (4 * 40)) / 2);
    pause_label.SetY(60);
    pause_label.SetColor(WHITE);

    auto& back_button = widget_manager.AddWidget<Button>();
    back_button.SetX((GAME_WIDTH - 180) / 2);
    back_button.SetY((GAME_HEIGHT - 60) / 2);
    back_button.SetWidth(180);
    back_button.SetHeight(60);
    back_button.SetFontSize(24);
    back_button.SetText("Back");
    back_button.SetOnClick([](Button& self, Game& game) {
        if (self.IsLeftClicked())
            game.GetSceneManager().GotoPreviousScene();
    });
}

auto PlayScene::Update(Game& game) -> void {
    if (IsKeyPressed(KEY_ESCAPE))
        this->paused = !paused;

    if (paused)
        widget_manager.Update(game);
    else
        entity_manager.Update(game);
}

auto PlayScene::Render() -> void {
    entity_manager.Render();

    if (paused)
        widget_manager.Render();
}

} // namespace WaveRush
