cmake_minimum_required(VERSION 3.23)
project(EventManager)

set(CMAKE_CXX_STANDARD 26)
set(PROJECT_HEADERS ${PROJECT_SOURCE_DIR}/headers)

include(CTest)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_options(-Wall -Wextra -Werror)
endif()

add_subdirectory(src)
add_subdirectory(test)
