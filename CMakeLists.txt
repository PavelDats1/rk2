cmake_minimum_required(VERSION 3.10)
project(RK2_Builder)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ========== ИСХОДНЫЕ ФАЙЛЫ ==========
add_executable(hamburger src/main.cpp src/hamburger.cpp)
add_executable(test_hamburger test/test_hamburger.cpp)

# ========== ТЕСТИРОВАНИЕ ==========
enable_testing()
add_test(NAME HamburgerTest COMMAND test_hamburger)

# ========== КРОСС-ПЛАТФОРМЕННАЯ УСТАНОВКА ==========
set(CPACK_PACKAGE_NAME "rk2-builder")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION "Builder pattern example with hamburgers")

if(WIN32)
    # Windows
    set(INSTALL_DESTINATION "bin")
    set(CPACK_GENERATOR "NSIS")
    set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-Windows")
else()
    # Linux
    set(INSTALL_DESTINATION "/usr/local/bin")
    set(CPACK_GENERATOR "DEB")
    set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}")
endif()

install(TARGETS hamburger
    RUNTIME DESTINATION ${INSTALL_DESTINATION}
)

include(CPack)
