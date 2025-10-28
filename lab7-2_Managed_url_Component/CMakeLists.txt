cmake_minimum_required(VERSION 3.16)

# Add external components directory to use the local Display component
set(EXTRA_COMPONENT_DIRS "../components")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(lab7-2)
