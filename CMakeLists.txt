cmake_minimum_required(VERSION 3.23)

project(KsLog LANGUAGES CXX)

find_package(KsCMakeHelpers CONFIG REQUIRED)
find_package(KsFatal CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

ks_setup()

add_subdirectory(src)
add_subdirectory(include)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
