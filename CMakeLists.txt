cmake_minimum_required(VERSION 2.8)
set(PROJECT_NAME lab4)
project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "-g -Wall")
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${COMMON_INCLUDES})
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
set(SRC_FILES ${PROJECT_SOURCE_DIR}/src/automata.cpp)
set(CMAKE_CXX_STANDARD 11)
add_library(lab4_lib ${SRC_FILES})
add_executable(lab4 ${PROJECT_SOURCE_DIR}/src/main.cpp )
add_library(task_lib ${SRC_FILES})
target_link_libraries(lab4 lab4_lib)
option(BUILD_TESTS "Build all tests." OFF) # Makes boolean 'test' available.





if (BUILD_TESTS)
  add_subdirectory(ext/gtest-1.8.0)
  enable_testing()
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
  add_executable(runUnitTests ${TEST_SRC_FILES})
  target_link_libraries(runUnitTests gtest gtest_main)
  target_link_libraries(runUnitTests lab4_lib)
  add_test(UnitTests runUnitTests)
  set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/.travis/cmake)
  if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
    include(CodeCoverage)
    setup_target_for_coverage(${PROJECT_NAME}_coverage runUnitTests coverage)
    SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
  endif() #CMAKE_BUILD_TYPE STREQUAL "Coverage"
endif()