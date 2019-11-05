cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
cmake_policy(VERSION 3.2)

project(vox
    VERSION "1.0.1"
    DESCRIPTION "Simplification of OpenGL library"
)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED COMPONENTS OpenGL)

add_subdirectory("libs")

file(GLOB_RECURSE SOURCES_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(${PROJECT_NAME} SHARED ${SOURCES_FILES} ${DEPENDENCIES_SOURCES_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    ${DEPENDENCIES_HEADERS_FILES}
)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glad glfw)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

configure_file("./cmake/${PROJECT_NAME}.pc.in" "${PROJECT_NAME}.pc" @ONLY)
install(FILES "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc" DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig")
