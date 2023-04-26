cmake_minimum_required(VERSION 3.24)
project(matrix)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}  main.cpp)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        include
        "${CMAKE_BINARY_DIR}"
        )

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
