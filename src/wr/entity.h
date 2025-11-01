#pragma once

struct wr_player {
    float x;
    float y;
    float width;
    float height;
};

void wr_player_init(wr_player* self, float x, float y);

void wr_player_update(wr_player* self, float game_width, float game_height);

void wr_player_draw(wr_player* self);

struct wr_bouncer {
    float x;
    float y;
    float radius;
    float speed_x;
    float speed_y;
};

void wr_bouncer_init(wr_bouncer* self, float x, float y);

void wr_bouncer_update(wr_bouncer* self, float game_width, float game_height);

void wr_bouncer_draw(wr_bouncer* self);

struct wr_seeker {};
