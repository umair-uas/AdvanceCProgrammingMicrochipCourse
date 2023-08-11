cmake_minimum_required(VERSION 3.10)

project(AdvancedCProgrammingMicroChipCourse)

set(CMAKE_C_STANDARD 11)

# List of source files (add more files as needed)
set(SOURCE_FILES
     UnionsandStructs.c
     PointerstoNestedUnionandStruct.c
     ArraysofStructs.c
     ArraysofPointers.c
     ArraysofStructPointers.c
     ArraysofFunctionPointers.c
     StateMachinewithFunctionPointers.c
     TrafficLightStateMachine.c
     CodePortability.c
     DoublePointerDereferencing.c 
    # Add more source files here
)

foreach(SOURCE_FILE ${SOURCE_FILES})
    get_filename_component(FILE_NAME ${SOURCE_FILE} NAME_WE)
    set(EXECUTABLE_NAME "${FILE_NAME}_example")
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES OUTPUT_NAME ${EXECUTABLE_NAME})
    target_compile_options(${EXECUTABLE_NAME} PRIVATE -g)  # Add -g flag
endforeach()
