add_library(Event event.cpp)
target_include_directories(Event
  PUBLIC
  ${PROJECT_SOURCE_DIR}/headers
)

add_library(Waitlist waitlist.cpp)
target_include_directories(Waitlist
  PUBLIC
  ${PROJECT_SOURCE_DIR}/headers
)

add_library(Admin admin.cpp)
target_include_directories(Admin
  PUBLIC
  ${PROJECT_SOURCE_DIR}/headers
)

add_library(User user.cpp)
target_include_directories(User
  PUBLIC
  ${PROJECT_SOURCE_DIR}/headers
)

add_library(UI ui.cpp)
target_link_libraries(UI
  PRIVATE
  Event
)
target_include_directories(UI
  PUBLIC
  Event
  ${PROJECT_SOURCE_DIR}/headers
)

add_library(Input input.cpp)
target_link_libraries(Input
  PRIVATE
  Event
)
target_include_directories(Input
  PUBLIC
  ${PROJECT_SOURCE_DIR}/headers
)

add_executable(runapp main.cpp)
target_link_libraries(runapp
  PRIVATE
  Event
  Waitlist
  Admin
  User
  UI
  Input
)

target_include_directories(runapp
  PUBLIC
  ${PROJECT_SOURCE_DIR}/headers
)
