/*
** Example of hot-reloading game functions.
** Raylib code based on the core 3d camera example.
**
** Based on:
** -
*https://medium.com/@TheElkantor/how-to-add-hot-reload-to-your-raylib-proj-in-c-698caa33eb74
** - https://github.com/ddovod/jet-live
**
*/

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

#include "debug.h"
#include "game.h"
#include "raylib.h"
#include "reload.h"

#include <sys/stat.h>

int dbg = 1;

init_gamestate_t init_gamestate = NULL;
free_gamestate_t free_gamestate = NULL;
update_gamestate_t update_gamestate = NULL;
update_frame_t update_frame = NULL;

gamestate_t *state = NULL;

int do_reload() {
  static symtab_t symtab[] = {{"init_gamestate", (void **)&init_gamestate},
                              {"free_gamestate", (void **)&free_gamestate},
                              {"update_gamestate", (void **)&update_gamestate},
                              {"update_frame", (void **)&update_frame},
                              {0}};
  return reload("libgamecode.so", symtab);
}

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 450;
  struct stat prev_stat, current_stat;

  if (do_reload() != 0) {
    return 1;
  };

  state = init_gamestate();

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(screenWidth, screenHeight, "Hot Reloading example.");

  SetTargetFPS(60);

  if (stat("libgamecode.so", &prev_stat) < 0) {
    perror("stat");
    return 1;
  }

  while (!WindowShouldClose()) {
    if (stat("libgamecode.so", &current_stat) < 0) {
      perror("stat");
      return 1;
    }

    if (prev_stat.st_mtime != current_stat.st_mtime) {
      printf("File modified\n");
      prev_stat = current_stat;
      do_reload();
    }

    update_gamestate(state);

    update_frame(state);
  }

  CloseWindow();

  free_gamestate(state);
  state = NULL;

  return 0;
}
