# Copyright (c) 2025 Seid Eshetu.

cmake_minimum_required(VERSION 3.10)

project(DaveLogs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ----------------------------------------------------
# Compiler, Target System OS, Target Architecture, 
# ----------------------------------------------------
if (NOT DEFINED CMAKE_SYSTEM_NAME)
    set(CMAKE_SYSTEM_NAME ${CMAKE_HOST_SYSTEM_NAME})
endif()

if (NOT DEFINED CMAKE_SYSTEM_PROCESSOR)
    set(CMAKE_SYSTEM_PROCESSOR ${CMAKE_HOST_SYSTEM_PROCESSOR})
endif()

message(STATUS "=====================================")
message(STATUS "Set Target System Name: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Set Target Architecture: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "Host System Name: ${CMAKE_HOST_SYSTEM_NAME}")
message(STATUS "Host Architecture: ${CMAKE_HOST_SYSTEM_PROCESSOR}")
message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "C++ Compiler Path: ${CMAKE_CXX_COMPILER}")
message(STATUS "=====================================")

# message("Conducting compiler compatibility check.")
# include(${CMAKE_SOURCE_DIR}/cmake/cmake_compiler_v_target_system_architecture_check.cmake)
# include(${CMAKE_SOURCE_DIR}/cmake/cmake_compiler_v_target_system_platform_check.cmake)


# ----------------------------------------------------
# Build Profiles setup
# ----------------------------------------------------
# include(${CMAKE_SOURCE_DIR}/cmake/cmake_C++_build_profiles.cmake)



# Current Build Profile Enquiry
# ---------------------------- 
# include(${CMAKE_SOURCE_DIR}/cmake/config_info.cmake)


# ----------------------------------------------------
# Dependencies
# ----------------------------------------------------
# Dependencies - via vcpkg
# ------------------------
# [NONE]


# Dependencies - Manual
# ----------------------
# [NONE]

# Include Project and Manually Added External Library Headers
set(PRJ_INCLUDE_DIRS
        "${CMAKE_SOURCE_DIR}/src"
)

# ----------------------------------------------------
# Project Source Code
# ----------------------------------------------------
file(GLOB_RECURSE PROJECT_SRCS
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

# ----------------------------------------------------
# Demo Executables
# ----------------------------------------------------
foreach(DEMO_TARGET
           quick_demo
           basic_demo
        )

      add_executable(${DEMO_TARGET}
          ${PROJECT_SRCS}
          demos/${DEMO_TARGET}.cpp
      )

      target_include_directories(${DEMO_TARGET} PUBLIC
           ${PRJ_INCLUDE_DIRS}
      )

      target_link_libraries(${DEMO_TARGET}
          ${PRJ_LIBS}
      )
endforeach()