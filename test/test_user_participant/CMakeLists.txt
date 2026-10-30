 add_executable(testUserVariousParticipants
    testUserVariousParticipants.cpp
)

target_link_libraries(testUserVariousParticipants
    PRIVATE
    User
    GTest::gtest_main
)

gtest_discover_tests(testUserVariousParticipants)