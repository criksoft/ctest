cmake_minimum_required(VERSION 4.1)
project(ctest C)

set(CMAKE_C_STANDARD 17)

#add_executable(ctest main.c)

file(GLOB C_FILES "src/*.c")

foreach(file ${C_FILES})
    get_filename_component(name ${file} NAME_WE)
    add_executable(${name} ${file})
    target_include_directories(${name} PRIVATE ./include)
    target_include_directories(${name} PRIVATE ./external)
endforeach()


target_include_directories(raylib_test PRIVATE /opt/homebrew/include)
target_link_directories(raylib_test PRIVATE /opt/homebrew/lib)
target_link_libraries(raylib_test PRIVATE raylib)



