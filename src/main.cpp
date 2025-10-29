#include "wr/constants.h"
#include "wr/scene/play_scene.h"
#include <raylib.h>

int
main ()
{
  SetConfigFlags (FLAG_WINDOW_RESIZABLE);
  InitWindow (GAME_WIDTH, GAME_HEIGHT, "Wave Rush");
  SetTargetFPS (TARGET_FPS);

  wr_play_scene scene;
  wr_play_scene_init (&scene);

  while (!WindowShouldClose ())
    {
      wr_play_scene_update (&scene);

      BeginDrawing ();
      ClearBackground (RAYWHITE);
      wr_play_scene_draw (&scene);
      EndDrawing ();
    }

  return 0;
}