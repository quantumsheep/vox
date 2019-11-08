add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(glm)

set(ASSIMP_BUILD_NO_EXPORT ON CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory(assimp)

set(DEPENDENCIES_HEADERS_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/imgui"
    "${CMAKE_CURRENT_SOURCE_DIR}/imgui-impl"

    "${CMAKE_CURRENT_SOURCE_DIR}/glm"

    "${CMAKE_CURRENT_SOURCE_DIR}/stb"

    PARENT_SCOPE
)

set(DEPENDENCIES_SOURCES_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_demo.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_widgets.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_draw.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/imgui-impl/imgui_impl_opengl3.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/imgui-impl/imgui_impl_glfw.cpp"

    PARENT_SCOPE
)
