cmake_minimum_required(VERSION 3.11)

project(CodeSnippets LANGUAGES CXX)

find_package(Qt5 COMPONENTS Core REQUIRED)

set(PROJ_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")

set(SOURCE_FILES ${PROJ_SOURCE_DIR}/main.cpp)


add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core)

if(UNIX)
    install(TARGTES ${PROJECT_NAME} DESTINATION /usr/bin)
else()
    install(TARGETS ${PROJECT_NAME} DESTINATION /)
endif()

#packaging
if(UNIX)
    exec_program(dpkg ARGS --print-architecture
                          OUTPUT_VARIABLE CPACK_DEBIAN_PACKAGE_ARCHITECTURE)
    set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
    set(CPACK_PACKAGE_CONTACT "alex tich <atichonov@yandex.ru>")
    set(CPACK_GENERATOR "DEB")
    set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6, libstdc++6, liggcc1, libqt5core5a")
    set(CPACK_STRIP_FILES ON)
    set(CPACK_PACKAGE_VERSION "0.0.1")
    set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}_${CPACK_PACKAGE_VERSION}_${CPACK_DEBIAN_PACKAGE_ARCHITECTURE}")
endif()
