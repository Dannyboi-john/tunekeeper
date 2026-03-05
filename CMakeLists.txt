cmake_minimum_required(VERSION 3.10)
project(tunekeeper C)

set(CMAKE_C_STANDARD 11)

find_package(SDL2 REQUIRED)

add_subdirectory(lvgl)

file(GLOB UI_IMAGES ui/images/*.c)

# Source
add_executable(tunekeeper 
    main.c 
    ui/ui.c 
    ${UI_IMAGES}
    ui/components/play_button.c
    ui/components/stop_button.c
    ui/components/bpm_dd.c
    ui/components/record_button.c
    ui/components/settings_button.c)

target_link_libraries(tunekeeper
    lvgl
    SDL2::SDL2
)