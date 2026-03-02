cmake_minimum_required(VERSION 3.24)

project(oops_shall_we_try_again)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(oops_test tests/oops_test.cpp src/oops.cpp)
add_executable(main main.cpp src/oops.cpp)

target_link_libraries(oops_test PRIVATE Catch2::Catch2WithMain)
