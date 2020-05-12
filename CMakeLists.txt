cmake_minimum_required(VERSION 3.9)
project(lab3)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_EXE_LINKER_FLAGS " -static")

add_subdirectory(test)

#add_executable(lab2 main.cpp lab3.cpp lab3.h test/tests.cpp)
add_executable(lab3 main.cpp lab3.cpp lab3.h)

target_link_libraries(lab3)
#target_link_libraries(lab3 -static-libgcc -static-libstdc++)

#add_definitions(-DTESTS)
