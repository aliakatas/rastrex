cmake_minimum_required(VERSION 3.25)
project(rastrex VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Export compile commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ── Dependencies ─────────────────────────────────────────────────────────────
find_package(GDAL REQUIRED)

# Add more find_package() calls here as your deps grow, e.g.:
# find_package(Eigen3 REQUIRED)
# find_package(Boost REQUIRED COMPONENTS filesystem)

# ── Library target ────────────────────────────────────────────────────────────
add_library(rastrex
    src/rastrex_api.cxx
)

# Public headers live in include/ and are installed alongside the library
target_include_directories(rastrex
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(rastrex
    PUBLIC
        GDAL::GDAL
    # Add more targets here, e.g. Eigen3::Eigen
)

target_compile_options(rastrex PRIVATE
    -Wall -Wextra -Wpedantic
)

# ── Tests ─────────────────────────────────────────────────────────────────────
# enable_testing()
# add_subdirectory(tests)

# ── Install rules ─────────────────────────────────────────────────────────────
include(GNUInstallDirs)
install(TARGETS rastrex
    EXPORT rastrexTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT rastrexTargets
    FILE rastrexTargets.cmake
    NAMESPACE mylib::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/rastrex
)

# -- Test target ────────────────────────────────────────────────────────────
add_executable(test_rastrex 
    src/rastrex_api.cxx
    src/test_rastrex.cxx
)

# Public headers live in include/ and are installed alongside the library
target_include_directories(test_rastrex
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(test_rastrex
    PUBLIC
        GDAL::GDAL
    # Add more targets here, e.g. Eigen3::Eigen
)

target_compile_options(test_rastrex PRIVATE
    -Wall -Wextra -Wpedantic
)