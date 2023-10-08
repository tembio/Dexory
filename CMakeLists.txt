cmake_minimum_required(VERSION 3.5)

project (dexory)

set(CMAKE_CXX_STANDARD 17)

# Setup Google Test
include(FetchContent)
include(GoogleTest)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#Setup opencv
find_package(OpenCV REQUIRED)

# Project
set(SOURCES
    src/asset_id.cpp
    src/digit.cpp
    src/text_exporter.cpp
    src/png_exporter.cpp
)

add_executable(${PROJECT_NAME} src/main.cpp ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(
  ${PROJECT_NAME}
  ${OpenCV_LIBS}
)

# Tests
set(TESTS
    test/test_asset_id.cpp
    test/test_digit.cpp
    test/test_text_exporter.cpp
    test/test_png_exporter.cpp
)

add_executable(${PROJECT_NAME}_tests ${TESTS} ${SOURCES})

target_include_directories(${PROJECT_NAME}_tests
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(
  ${PROJECT_NAME}_tests
  GTest::gtest_main
  GTest::gmock_main
  ${OpenCV_LIBS}
)

enable_testing()
gtest_discover_tests(${PROJECT_NAME}_tests PROPERTIES TIMEOUT 600)
