ks_add_unit_test(test-log
  SOURCES
    test_log.cpp
  LIBS
    PRIVATE
      GTest::gtest_main
      ks-log
)
