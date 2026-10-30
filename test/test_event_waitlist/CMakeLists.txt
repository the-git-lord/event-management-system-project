add_executable(TestWaitlistHandling testWaitlistHandling.cpp)
target_link_libraries(TestWaitlistHandling
  PRIVATE
  Event
  Waitlist
  EventCreationHelperFunctions
  GTest::gtest_main
)

add_executable(TestWaitlistParticipant testWaitlistParticipant.cpp)
target_link_libraries(TestWaitlistParticipant
  PRIVATE
  Event
  Waitlist
  EventCreationHelperFunctions
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(TestWaitlistHandling)
gtest_discover_tests(TestWaitlistParticipant)
