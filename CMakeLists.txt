cmake_minimum_required(VERSION 3.14)
# Project information
project(Inceptor
  VERSION 3.0.0
  DESCRIPTION "Inceptor interface"
  LANGUAGES CXX
)
# Add the library target
add_library(inceptor INTERFACE)
# Setup include directories 
target_include_directories(inceptor INTERFACE include/)
# Need C++20
target_compile_options(inceptor INTERFACE -std=c++20)

# Example if this project is built separately
if (PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
  # Add example target
  add_executable(example examples/example.cc)
  # Add the includes
  target_include_directories(example PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
  )
  # Link libraries to the example target
  target_link_libraries(example
    PRIVATE 
      inceptor
  )
endif()
