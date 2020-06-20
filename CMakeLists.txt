cmake_minimum_required(VERSION 3.0)
project(SimpleUtils VERSION 0.0.1)

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(doctest REQUIRED)

include(ExternalProject)
find_package(Git REQUIRED)

ExternalProject_Add(
    doctest
    PREFIX ${CMAKE_BINARY_DIR}/doctest
    GIT_REPOSITORY https://github.com/onqtam/doctest.git
    TIMEOUT 10
    UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
)

# Expose required variable (DOCTEST_INCLUDE_DIR) to parent scope
ExternalProject_Get_Property(doctest source_dir)
set(DOCTEST_INCLUDE_DIR ${source_dir}/doctest CACHE INTERNAL "Path to include folder for doctest")

add_library(SimpleUtils
    ${PROJECT_SOURCE_DIR}/src/SimpleUtils.cc
    ${PROJECT_SOURCE_DIR}/src/StopWatchImpl.cc
    ${PROJECT_SOURCE_DIR}/src/StopWatch.cc
)

target_include_directories(SimpleUtils PRIVATE src)

add_executable(test_stopwatch
    ${PROJECT_SOURCE_DIR}/test/test_stopwatch.cc
    ${PROJECT_SOURCE_DIR}/src/StopWatchImpl.cc
    ${PROJECT_SOURCE_DIR}/src/StopWatch.cc
)
target_compile_features(test_stopwatch PRIVATE cxx_std_11)
target_include_directories(test_stopwatch 
    PRIVATE ${PROJECT_SOURCE_DIR}/src
    PRIVATE ${DOCTEST_INCLUDE_DIR}
    )
# target_link_libraries(test_stopwatch PRIVATE doctest::doctest)