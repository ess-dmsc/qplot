# C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if (NOT CMAKE_CXX_STANDARD OR CMAKE_CXX_STANDARD LESS 14)
  set(CMAKE_CXX_STANDARD 14)
endif ()

# Warnings
include(CheckCXXCompilerFlag)

check_cxx_compiler_flag("-Wall" Wall_FLAG_SUPPORTED)
if(Wall_FLAG_SUPPORTED)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
endif(Wall_FLAG_SUPPORTED)

check_cxx_compiler_flag("-pedantic" pedantic_FLAG_SUPPORTED)
if(pedantic_FLAG_SUPPORTED)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -pedantic")
endif(pedantic_FLAG_SUPPORTED)

check_cxx_compiler_flag("-Wextra" Wextra_FLAG_SUPPORTED)
if(Wextra_FLAG_SUPPORTED)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wextra")
endif(Wextra_FLAG_SUPPORTED)

if (CMAKE_CXX_COMPILER_ID MATCHES GNU)
  # Optimizations
  if (CMAKE_BUILD_TYPE MATCHES Release)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
  elseif (CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
  endif ()
endif ()

message(STATUS "==============================================================")
