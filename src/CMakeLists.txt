add_library(ks-log
  log.cpp
)

target_include_directories(
  ks-log
  PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
    "$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

target_sources(
  ks-log
  PUBLIC
    FILE_SET headers
      TYPE
        HEADERS
      BASE_DIRS
        ${PROJECT_SOURCE_DIR}/include/
        ${PROJECT_BINARY_DIR}/include/
      FILES
        ${PROJECT_SOURCE_DIR}/include/ks/log.hpp
        ${PROJECT_BINARY_DIR}/include/ks/log/detail/symbol_visibility.hpp
)

target_compile_features(
  ks-log
  PUBLIC
    cxx_std_17
)

target_link_libraries(
  ks-log
  PUBLIC
    fmt::fmt
  PRIVATE
    KsFatal::ks-fatal
)

ks_install(
  TARGETS
    ks-log
  DEPENDENCIES
    fmt
    KsFatal
)
