#include "wr/scene.h"

#include <raylib.h>

#include "wr/array_list.h"
#include "wr/entity.h"
#include "wr/utils.h"

void wr_play_scene_init(wr_play_scene* self) {
    if (self == nullptr)
        return;

    wr_player_init(&self->player, 100.0f, 100.0f);

    wr_array_list_init(&self->bouncers, sizeof(wr_bouncer), 10);
    for (int i = 0; i < 5; i++) {
        wr_bouncer bouncer;
        wr_bouncer_init(&bouncer, 50.0f + i * 100.0f, 200.0f);
        wr_array_list_add(&self->bouncers, &bouncer);
    }
}

void wr_play_scene_update(wr_play_scene* self, wr_scene* current_scene) {
    if (self == nullptr)
        return;

    wr_player_update(&self->player, GetScreenWidth(), GetScreenHeight());

    for (int i = 0; i < self->bouncers.length; i++) {
        wr_bouncer* bouncer =
            (wr_bouncer*)wr_array_list_get(&self->bouncers, i);

        wr_bouncer_update(bouncer, GetScreenWidth(), GetScreenHeight());

        if (!wr_collision_rect_circle(
                self->player.x,
                self->player.y,
                self->player.width,
                self->player.height,
                bouncer->x,
                bouncer->y,
                bouncer->radius
            ))
            continue;

        wr_player_init(&self->player, 100.0f, 100.0f);
    }

    if (IsKeyPressed(KEY_SPACE)) {
        *current_scene = WR_SCENE_MENU;
    }
}

void wr_play_scene_draw(wr_play_scene* self) {
    if (self == nullptr)
        return;

    wr_player_draw(&self->player);

    for (int i = 0; i < 5; i++) {
        wr_bouncer* bouncer =
            (wr_bouncer*)wr_array_list_get(&self->bouncers, i);
        wr_bouncer_draw(bouncer);
    }
}