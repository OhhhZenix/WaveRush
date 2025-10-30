#include "wr/entity/enemy/bouncer.h"

#include <raylib.h>

void wr_bouncer_init(wr_bouncer* self, float x, float y) {
    if (self == nullptr) {
        return;
    }

    self->x = x;
    self->y = y;
    self->radius = 16.0f;
    self->speed_x = 1.0f;
    self->speed_y = 1.0f;
}

void wr_bouncer_update(wr_bouncer* self, float game_width, float game_height) {
    if (self == nullptr) {
        return;
    }

    self->x += self->speed_x;
    self->y += self->speed_y;

    if (self->x <= self->radius || self->x >= game_width - self->radius) {
        self->speed_x = -self->speed_x;
    }

    if (self->y <= self->radius || self->y >= game_height - self->radius) {
        self->speed_y = -self->speed_y;
    }
}

void wr_bouncer_draw(wr_bouncer* self) {
    if (self == nullptr) {
        return;
    }

    DrawCircle(self->x, self->y, self->radius, GREEN);
}
