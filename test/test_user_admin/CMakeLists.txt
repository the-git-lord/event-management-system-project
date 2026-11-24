add_executable(TestAdminUserReports testAdminUserReports.cpp)
target_link_libraries(TestAdminUserReports
  PRIVATE
  Admin
  Event
  User
  Report
  GTest::gtest_main
)

add_executable(TestUserReporting testUserReporting.cpp)
target_link_libraries(TestUserReporting
  PRIVATE
  Admin
  User
  Report
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(TestAdminUserReports)
gtest_discover_tests(TestUserReporting)