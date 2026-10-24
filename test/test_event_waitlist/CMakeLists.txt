add_executable(TestWaitlist test_waitlist.cpp)
target_link_libraries(TestWaitlist
  PRIVATE
  Event
  Waitlist
  EventCreationHelperFunctions
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(TestWaitlist)
