add_executable(TestEvent ut_event.cpp)
target_link_libraries(TestEvent
  ${EVENT_MANAGER_SOURCE_DIR}/src
)
