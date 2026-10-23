enable_testing()

add_library(testEventCreationHelperFunctions testEventCreationHelperFunctions.cpp)
target_link_libraries(testEventCreationHelperFunctions
  PRIVATE
  Event
)
target_include_directories(testEventCreationHelperFunctions
  PUBLIC
  ${PROJECT_SOURCE_DIR}/headers
)

add_library(testEventCheckHelperFunctions testEventCheckHelperFunctions.cpp)
target_link_libraries(testEventCheckHelperFunctions
  PRIVATE
  Event
)
target_include_directories(testEventCheckHelperFunctions
  PUBLIC
  ${PROJECT_SOURCE_DIR}/headers
)

add_executable(TestEventCreation testEventCreationMain.cpp)
target_link_libraries(TestEventCreation
  PRIVATE
  Event
  testEventCreationHelperFunctions
  testEventCheckHelperFunctions
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(TestEventCreation)
