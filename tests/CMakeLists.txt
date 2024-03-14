find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

add_executable(test-log
  test_log.cpp
)

target_link_libraries(test-log
  PRIVATE
    GTest::gtest_main
    ks-log
)

gtest_discover_tests(test-log
  DISCOVERY_MODE
    PRE_TEST
  XML_OUTPUT_DIR
    reports
)
