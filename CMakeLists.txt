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
    ui/menu_bar_components/file.c
    ui/menu_bar_components/edit.c
    ui/menu_bar_components/select.c
    ui/menu_bar_components/view.c
    ui/header_components/play_button.c
    ui/header_components/stop_button.c
    ui/header_components/bpm_dd.c
    ui/header_components/record_button.c
    ui/header_components/settings_button.c
    ui/header_components/prev_button.c
    ui/header_components/next_button.c
    ui/tracklist_components/tl_area.c
    ui/tracklist_components/track.c)

target_link_libraries(tunekeeper
    lvgl
    SDL2::SDL2
)