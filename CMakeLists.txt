cmake_minimum_required(VERSION 3.21)
project(Game_NewSample VERSION 0.0.1 LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)


add_executable(Game_NewSample main.cpp AssetManager.cpp AssetManager.h 
GameEngine.h GameEngine.cpp)

add_custom_command(
  TARGET Game_NewSample POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy 
    ${PROJECT_SOURCE_DIR}/game.ico
    $<TARGET_FILE_DIR:Game_NewSample>/game.ico)
add_custom_command(
  TARGET Game_NewSample POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy 
    ${PROJECT_SOURCE_DIR}/game.png
    $<TARGET_FILE_DIR:Game_NewSample>/game.png)

target_link_libraries(Game_NewSample PRIVATE sfml-graphics sfml-system sfml-window)

target_compile_features(Game_NewSample PRIVATE cxx_std_14)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET Game_NewSample POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Game_NewSample> $<TARGET_FILE_DIR:Game_NewSample> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS Game_NewSample)

# Директория с СMakeLists.txt
# cmake -S . -B build
# cmake --build build --config Release
# cmake --build build --config Debug
# Для запуска проекта выбрать активный проект