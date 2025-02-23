## CPP

```
TextAdventureGame/
├── include/
│   ├── Location.h
│   ├── Player.h
│   ├── Item.h
│   ├── Enemy.h
│   ├── NPC.h
│   └── Game.h
├── src/
│   ├── Location.cpp
│   ├── Player.cpp
│   ├── Item.cpp
│   ├── Enemy.cpp
│   ├── NPC.cpp
│   └── Game.cpp
├── main.cpp
└── CMakeLists.txt (или Makefile)
```

cmake_minimum_required(VERSION 3.10)
project(TextAdventureGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(TextAdventureGame
    src/Location.cpp
    src/Player.cpp
    src/Item.cpp
    src/Enemy.cpp
    src/NPC.cpp
    src/Game.cpp
    main.cpp
)

target_include_directories(TextAdventureGame PRIVATE include)

## Сборка и запуск
### Создайте директорию build и перейдите в неё:

bash:
    mkdir build
    cd build

### Запустите CMake для генерации Makefile:

bash:
    cmake ..

### Соберите проект:

bash:
    make

### Запустите игру:

bash:
    ./TextAdventureGame