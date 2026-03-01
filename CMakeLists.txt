cmake_minimum_required(VERSION 3.10)
project(tunekeeper C)

set(CMAKE_C_STANDARD 11)

find_package(SDL2 REQUIRED)

add_subdirectory(lvgl)

# Source
add_executable(tunekeeper main.c ui/ui.c)

target_link_libraries(tunekeeper
    lvgl
    SDL2::SDL2
)