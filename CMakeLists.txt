cmake_minimum_required(VERSION 3.22)
project(SFMLGame CXX)

# Fixes the third-party old policy error for dependencies like vorbis
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    SFML
    URL https://github.com/SFML/SFML/archive/refs/tags/3.0.0.tar.gz
)
FetchContent_MakeAvailable(SFML)

add_executable(SFMLGame main.cpp Game.cpp Room.cpp Enemy.cpp)
target_link_libraries(SFMLGame PRIVATE SFML::Graphics SFML::Audio)

add_custom_command(TARGET SFMLGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:SFMLGame>/assets
)