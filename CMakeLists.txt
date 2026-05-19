cmake_minimum_required(VERSION 3.10)
project(RK2_Builder)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основная программа
add_executable(hamburger src/hamburger.cpp)

# Тест (отдельный исполняемый файл)
add_executable(test_hamburger test/test_hamburger.cpp)

# CPack для deb-пакета
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Pavel Datskovskikh <pavel@example.com>")
set(CPACK_PACKAGE_NAME "rk2-builder")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION "Builder pattern example with hamburgers")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}")
install(TARGETS hamburger DESTINATION /usr/local/bin)
include(CPack)
