#include "wr/entity/player.h"

#include <raylib.h>

#include "wr/utils.h"

constexpr float PLAYER_SPEED = 2.0f;

void wr_player_init(wr_player* self, float x, float y) {
    if (self == nullptr)
        return;

    self->x = x;
    self->y = y;
    self->width = 32;
    self->height = 32;
}

void wr_player_move(wr_player* self, float game_width, float game_height) {
    if (self == nullptr)
        return;

    if (IsKeyDown(KEY_W)) {
        self->y -= PLAYER_SPEED;
    }

    if (IsKeyDown(KEY_S)) {
        self->y += PLAYER_SPEED;
    }

    if (IsKeyDown(KEY_A)) {
        self->x -= PLAYER_SPEED;
    }

    if (IsKeyDown(KEY_D)) {
        self->x += PLAYER_SPEED;
    }

    self->x = wr_clampf(self->x, 0, game_width - self->width);
    self->y = wr_clampf(self->y, 0, game_height - self->height);
}

void wr_player_draw(wr_player* self) {
    if (self == nullptr)
        return;

    DrawRectangle(self->x, self->y, self->width, self->height, BLUE);
}