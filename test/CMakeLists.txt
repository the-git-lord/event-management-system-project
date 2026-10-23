include(GoogleTest)

add_library(EventCreationHelperFunctions testEventCreationHelperFunctions.cpp)
target_link_libraries(EventCreationHelperFunctions
  PRIVATE
  Event
)
target_include_directories(EventCreationHelperFunctions
  PUBLIC
  ${PROJECT_SOURCE_DIR}/headers
)

add_library(EventCheckHelperFunctions testEventCheckHelperFunctions.cpp)
target_link_libraries(EventCheckHelperFunctions
  PRIVATE
  Event
)
target_include_directories(EventCheckHelperFunctions
  PUBLIC
  ${PROJECT_SOURCE_DIR}/headers
)

add_library(UserRegistrationHelperFunctions testEventUserRegistrationHelperFunctions.cpp)
target_link_libraries(UserRegistrationHelperFunctions
  PRIVATE
  Event
)
target_include_directories(UserRegistrationHelperFunctions
  PUBLIC
  ${PROJECT_SOURCE_DIR}/headers
)

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
  UserRegistrationHelperFunctions
  GTest::gtest_main
)

gtest_discover_tests(TestEventCreation)
gtest_discover_tests(TestEventUserRegistration)
