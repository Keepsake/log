cmake_minimum_required(VERSION 3.23)

project(KsLog LANGUAGES CXX)

find_package(KsCMakeHelpers CONFIG REQUIRED)
find_package(KsFatal CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

ks_setup()

add_subdirectory(src)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
