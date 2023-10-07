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


# Project sources
set(SOURCES
    src/asset_id.cpp
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

# Tests
set(TESTS
    test/test_asset_id.cpp
)

add_executable(${PROJECT_NAME}_tests ${TESTS})

target_include_directories(${PROJECT_NAME}_tests
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
  ${PROJECT_NAME}_tests
  GTest::gtest_main
)

enable_testing()
gtest_discover_tests(${PROJECT_NAME}_tests)




