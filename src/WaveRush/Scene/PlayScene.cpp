#include "WaveRush/Scene/PlayScene.hpp"

#include <raylib.h>

#include "WaveRush/Entity/Player.hpp"
#include "WaveRush/Game.hpp"
#include "WaveRush/Widget.hpp"
#include "WaveRush/Widget/Button.hpp"

namespace WaveRush {

PlayScene::PlayScene() {
    entity_manager.AddEntity(new Player());

    auto back_button = new Button();
    back_button->SetText("Back");
    back_button->SetOnClick([](Button& self, Game& game) {
        if (self.IsLeftClicked())
            game.GetSceneManager().GotoPreviousScene();
    });
    widget_manager.AddWidget(back_button);
}

void PlayScene::Update(Game& game) {
    if (IsKeyPressed(KEY_ESCAPE))
        this->paused = !paused;

    if (!paused)
        entity_manager.Update(game);

    if (paused)
        widget_manager.Update(game);
}

void PlayScene::Render() {
    entity_manager.Render();

    if (paused)
        widget_manager.Render();
}

} // namespace WaveRush
