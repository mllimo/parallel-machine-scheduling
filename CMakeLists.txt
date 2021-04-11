cmake_minimum_required(VERSION 3.16)

project(parallel-machine)

add_subdirectory(vendor/armadillo)
add_subdirectory(src)

target_include_directories(${PROJECT_NAME} 
  PRIVATE include
  PUBLIC vendor/armadillo/include()
)

add_executable(${PROJECT_NAME} /src/main.cc)
target_link_libraries(${PROJECT_NAME} pms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG " -O0 -fsanitize=address -pedantic-errors -Wall -Wextra -DDEBUG -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall")
