add_library(EventCreationHelperFunctions testEventCreationHelperFunctions.cpp)
target_link_libraries(EventCreationHelperFunctions
  PRIVATE
  Event
)
target_include_directories(EventCreationHelperFunctions
  PUBLIC
  ${PROJECT_HEADERS}
  ${SHARED_TEST_HEADERS}
)

add_library(EventCheckHelperFunctions testEventCheckHelperFunctions.cpp)
target_link_libraries(EventCheckHelperFunctions
  PRIVATE
  Event
)
target_include_directories(EventCheckHelperFunctions
  PUBLIC
  ${PROJECT_HEADERS}
  ${SHARED_TEST_HEADERS}
)

add_library(UserRegistrationHelperFunctions testEventUserRegistrationHelperFunctions.cpp)
target_link_libraries(UserRegistrationHelperFunctions
  PRIVATE
  Event
  EventCreationHelperFunctions
)
target_include_directories(UserRegistrationHelperFunctions
  PUBLIC
  ${PROJECT_HEADERS}
  ${SHARED_TEST_HEADERS}
)
