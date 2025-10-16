#include "wr/scene/play_scene.h"
#include "wr/core/array_list.h"
#include "wr/entity/enemy/bouncer.h"
#include "wr/entity/player.h"

void wr_play_scene_init(PlayScene *self) {
  if (self == nullptr) {
    return;
  }

  wr_player_init(&self->player, 100.0f, 100.0f);

  wr_array_list_init(&self->bouncers, sizeof(Bouncer), 10);
  for (int i = 0; i < 5; i++) {
    Bouncer bouncer;
    wr_bouncer_init(&bouncer, 50.0f + i * 100.0f, 200.0f);
    wr_array_list_add(&self->bouncers, &bouncer);
  }
}

void wr_play_scene_update(PlayScene *self) {
  if (self == nullptr) {
    return;
  }

  wr_player_move(&self->player);

  for (int i = 0; i < 5; i++) {
    Bouncer *bouncer = (Bouncer *)wr_array_list_get(&self->bouncers, i);
    wr_bouncer_update(bouncer);
  }
}

void wr_play_scene_draw(PlayScene *self) {
  if (self == nullptr) {
    return;
  }

  wr_player_draw(&self->player);

  for (int i = 0; i < 5; i++) {
    Bouncer *bouncer = (Bouncer *)wr_array_list_get(&self->bouncers, i);
    wr_bouncer_draw(bouncer);
  }
}