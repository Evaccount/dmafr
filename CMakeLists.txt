cmake_minimum_required(VERSION 3.31)
project(dmafr)

set(INCLUDE_FOL ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_FOL ${CMAKE_CURRENT_SOURCE_DIR}/src)
include(FetchContent)

file(GLOB_RECURSE INCLUDES "${INCLUDE_FOL}/*.hpp")
file(GLOB_RECURSE SOURCES "${SOURCE_FOL}/*.cpp")
find_package(CURL REQUIRED)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git)
FetchContent_MakeAvailable(cpr)




add_executable(${PROJECT_NAME} ${INCLUDES} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE cpr::cpr)
include_directories(${INCLUDE_FOL})
