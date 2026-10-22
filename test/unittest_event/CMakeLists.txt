include(GoogleTest)

add_executable(TestEventCreation testEventCreation.cpp)
target_link_libraries(TestEventCreation
  PRIVATE
  Event
  GTest::gtest_main
)

gtest_discover_tests(TestEventCreation)
