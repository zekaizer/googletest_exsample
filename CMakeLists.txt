cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)


add_subdirectory(extern/googletest)





enable_testing()

INCLUDE_DIRECTORIES(src)
INCLUDE_DIRECTORIES(mock)

add_executable(
  test_cmodule
  src/cmodule.c
  mock/BCM2835Lib_MOCK.cpp
  test/test_cmodule.cpp
  test/test_BCM2835Lib.cpp
)
target_link_libraries(
  test_cmodule
  gtest_main
  gmock
)

include(GoogleTest)
gtest_discover_tests(test_cmodule)


if(CMAKE_COMPILER_IS_GNUCXX)
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")
    include(CodeCoverage)
    append_coverage_compiler_flags()
    setup_target_for_coverage_gcovr_html(
            NAME coverage
            EXECUTABLE test_cmodule
            BASE_DIRECTORY "${PROJECT_SOURCE_DIR}/src"
    )
endif()
