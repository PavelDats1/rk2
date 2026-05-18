cmake_minimum_required(VERSION 3.10)
project(RK2_Builder)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основная программа
add_executable(hamburger src/hamburger.cpp)

# Тест
add_executable(test_hamburger test/test_hamburger.cpp)
target_link_libraries(test_hamburger)

# Настройки для создания deb-пакета
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Ваше Имя <email@example.com>")
set(CPACK_PACKAGE_NAME "rk2-builder")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION "Builder pattern example with hamburgers")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}")
include(CPack)

# Установка: куда скопировать бинарник при установке deb-пакета
install(TARGETS hamburger DESTINATION /usr/local/bin)
