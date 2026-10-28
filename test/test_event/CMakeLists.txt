add_executable(TestEventCreation testEventCreationMain.cpp)
target_link_libraries(TestEventCreation
  PRIVATE
  Event
  EventCreationHelperFunctions
  EventCheckHelperFunctions
  GTest::gtest_main
)

add_executable(TestEventUserRegistration testEventUserRegistrationMain.cpp)
target_link_libraries(TestEventUserRegistration
  PRIVATE
  Event
  EventCreationHelperFunctions
  UserRegistrationHelperFunctions
  GTest::gtest_main
)

add_executable(TestEventRegistrationDeadline testEventRegistrationDeadline.cpp)
target_link_libraries(TestEventRegistrationDeadline
  PRIVATE
  Event
  EventCreationHelperFunctions
  UserRegistrationHelperFunctions
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(TestEventCreation)
gtest_discover_tests(TestEventUserRegistration)
gtest_discover_tests(TestEventRegistrationDeadline)
