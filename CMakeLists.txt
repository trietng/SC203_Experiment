# CMakeList.txt : CMake project for SC203_Experiment, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("SC203_Experiment")

# Add source to this project's executable.
add_executable (SC203_Experiment "main.cpp" "output.hpp" "file.hpp" "experiment.hpp" "experiment.cpp")

# Name of executable
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "experiment")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SC203_Experiment PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
