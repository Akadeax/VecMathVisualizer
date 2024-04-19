add_executable(VecMathVisualizer main.cpp)

add_custom_command(
    TARGET VecMathVisualizer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory  $<TARGET_FILE_DIR:VecMathVisualizer>/resources
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${VECMATH_COMMON_RESOURCE_DIR}
    $<TARGET_FILE_DIR:VecMathVisualizer>/resources
    )
target_link_libraries(VecMathVisualizer PUBLIC VecMathLib)
if (UNIX)
find_package(Threads REQUIRED)
target_link_libraries(VecMathVisualizer PRIVATE Threads::Threads)
endif()
#set_target_properties(VecMathVisualizer PROPERTIES OUTPUT_NAME "VecMath")
