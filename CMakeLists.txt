cmake_minimum_required(VERSION 3.28)
project(SS_Logger VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Boost REQUIRED COMPONENTS system thread log log_setup)

include(FetchContent)

# Add google tests
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG v1.15.0)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()


add_subdirectory(include/Utils)
add_subdirectory(include/Parser)
add_subdirectory(include/Logger)

add_executable(SS_Logger src/main.cpp)

target_link_libraries(SS_Logger PRIVATE
    Logger
    Parser
    Utils
    Boost::system
    Boost::thread
    Boost::log
    Boost::log_setup
)

target_include_directories(SS_Logger PRIVATE
    ${CMAKE_SOURCE_DIR}/include/Logger/include
    ${CMAKE_SOURCE_DIR}/include/Parser/include
    ${CMAKE_SOURCE_DIR}/include/Utils/include
    ${Boost_INCLUDE_DIRS}
)
