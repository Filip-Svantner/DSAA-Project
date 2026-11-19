cmake_minimum_required(VERSION 3.22)
project(SFMLGame LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# FIX 1: Set the policy version minimum BEFORE fetching content.
# This tells CMake to temporarily allow old policies for third-party code.
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

include(FetchContent)
FetchContent_Declare(
    SFML
    URL https://github.com/SFML/SFML/archive/refs/tags/3.0.0.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# FIX 2: Use the standard FetchContent_MakeAvailable.
# The previous manual populate method is deprecated and causing your other warning.
FetchContent_MakeAvailable(SFML)

add_executable(SFMLGame main.cpp Game.cpp Room.cpp Enemy.cpp Player.cpp)
target_link_libraries(SFMLGame PRIVATE SFML::Graphics SFML::Audio)

add_custom_command(TARGET SFMLGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:SFMLGame>/assets
)