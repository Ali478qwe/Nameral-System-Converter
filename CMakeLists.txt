cmake_minimum_required(VERSION 3.10)

project(hex)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/output")


add_executable(hex
                src/main.c
                include/numeral_system.c
               )

set_target_properties(hex PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output"
)

