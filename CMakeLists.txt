cmake_minimum_required(VERSION 3.23)

project(EventManager)

set(CMAKE_CXX_STANDARD 26)
set(SOURCE_FILES
  src/main.cpp
  src/event.cpp
  src/waitlist.cpp
  src/admin.cpp
  src/user.cpp
  src/ui.cpp
  src/input.cpp
)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_options(-Wall -Wextra -Werror)
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(EventManager)
target_sources(EventManager
  PRIVATE ${SOURCE_FILES}
)

target_include_directories(EventManager
  PUBLIC
  headers
)
