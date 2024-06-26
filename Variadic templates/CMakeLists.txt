cmake_minimum_required(VERSION 3.27.4)
project(variadic-templates)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})
set(TARGET_PREFIX VariadicTemplates_)

add_custom_target(variadic-templates-examples)
file(GLOB EXAMPLE_FILES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/example*.cpp")

# Create executable targets
foreach(EXAMPLE ${EXAMPLE_FILES})
    get_filename_component(FILE_NAME ${EXAMPLE} NAME_WE)
    set(TARGET_NAME ${TARGET_PREFIX}${FILE_NAME}${exampleIndex})
    add_executable(${TARGET_NAME} ${EXAMPLE})
    set_target_properties(${TARGET_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build
    )
    add_dependencies(variadic-templates-examples ${TARGET_NAME})
endforeach(EXAMPLE)