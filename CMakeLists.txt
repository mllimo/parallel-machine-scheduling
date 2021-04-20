cmake_minimum_required(VERSION 3.16)

project(parallel-machine)

file(GLOB SRC
  "src/*.cc"
)

add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME}
  PUBLIC "include"
  PUBLIC "external/csv/include"
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG " -O0 -fsanitize=address -pedantic-errors -Wall -Wextra -DDEBUG -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall")
