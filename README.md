# Raylib Hot Reload Starter

## Setup
update project details in CMakeLists.txt then:
```
brew install cmake
cmake -S . -B build
cmake --build build
```

## Run The Executable
```
cd build
make run
```

## Run and Watch
```
cd build
make watch
```
the exe is launched in background and then changes to `game.c` are automatically built and pulled into the program.

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


