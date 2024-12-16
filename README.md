# Raylib Hot Reload Starter

This is mainly just a copy of [@seletz's project](https://github.com/seletz/raylib-hot-code-reload-c-example) at this point, but it works on Mac

## Setup
```
brew install cmake
mkdir build
cd build
cmake ..
cmake --build .
```

## Run
in one terminal window:
```
cd build
./my-raylib-starter
```

## Watch for changes
in another:
```
cd build
make watch
```

Then when you make changes in game.c, the library will automatically be rebuilt and you can press `r` in the game window to load in the latest


## TODO
Ideally, you wouldn't have to press `r` to load in the game state, instead, we'd detect when the libgamecode.so had changed and reload it automatically in main.c


## Notes
`dll` is dynamically load library

"Code is stored in memory - to load code dynamically, you store it in memory and jump there" - Tsoding Daily

Basically, there's a separate module that is loaded into the main program as a dynamic library and that's the part of the code that can be hot-reloaded.


## References
- https://github.com/raysan5/raylib-game-template/blob/main/CMakeLists.txt
- https://github.com/krzosa/raylib_hot_reload_template/tree/master
- https://github.com/seletz/raylib-hot-code-reload-c-example
- https://seletz.github.io/posts/hotreload-gamecode-in-c
- https://www.youtube.com/watch?v=Y57ruDOwH1g
- https://www.youtube.com/watch?v=tOQZlD-0Scc

