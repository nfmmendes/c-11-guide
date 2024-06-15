cmake_minimum_required(VERSION 3.27.4)
project(moving-semantics)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define an option with a description
option(USE_CUSTOM_STRINGS "Enable the use of a custom string class instead of std::string" ON)
option(ENABLE_CUSTOM_STRING_COUT "Enable/disable cout's on string.h file" ON)

if(USE_CUSTOM_STRINGS)
    add_definitions(-DUSE_CUSTOM_STRINGS)
endif()

if(ENABLE_CUSTOM_STRING_COUT)
    add_definitions(-DENABLE_CUSTOM_STRING_COUT)
endif()

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

set(COMMON_HEADERS_AND_SOURCE_FILES ${PROJECT_SOURCE_DIR}/string.cpp ${PROJECT_SOURCE_DIR}/utils.h)
set(TARGET_PREFIX MoveSemantics_)

add_custom_target(move-semantics-examples)
file(GLOB EXAMPLE_FILES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/example*.cpp")

# Create executable targets
foreach(EXAMPLE ${EXAMPLE_FILES})
    get_filename_component(FILE_NAME ${EXAMPLE} NAME_WE)
    set(TARGET_NAME ${TARGET_PREFIX}${FILE_NAME}${exampleIndex})
    add_executable(${TARGET_NAME} ${EXAMPLE} ${COMMON_HEADERS_AND_SOURCE_FILES})
    set_target_properties(${TARGET_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build
    )
    add_dependencies(move-semantics-examples ${TARGET_NAME})
endforeach(EXAMPLE)
