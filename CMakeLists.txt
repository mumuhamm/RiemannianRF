cmake_minimum_required(VERSION 3.16)
project(BDT_Riemannian)
include_directories(/opt/homebrew/include)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ROOT setup (Finds ROOT, including TMVA)
find_package(ROOT REQUIRED COMPONENTS TMVA RIO Tree Hist MathCore)

# Include directories
include_directories(${ROOT_INCLUDE_DIRS} interface)

# Find Catch2
find_package(Catch2 REQUIRED)

# Include Catch2 headers
include_directories(${CATCH2_INCLUDE_DIRS})
# Enable Metal (for macOS GPU)
if(APPLE)
    find_library(METAL_LIB Metal)
    message(STATUS "Metal GPU support enabled")
endif()

# Source files
file(GLOB_RECURSE SOURCES src/*.cc)

# Build executable
add_executable(BDT_Riemannian ${SOURCES})

# Link ROOT libraries
target_link_libraries(BDT_Riemannian ${ROOT_LIBRARIES})

# Link Metal for GPU (macOS only)
if(APPLE)
    target_link_libraries(BDT_Riemannian ${METAL_LIB})
endif()

# Install target
install(TARGETS BDT_Riemannian DESTINATION bin)

# Enable unit tests with Catch2 (optional)
enable_testing()
add_executable(UnitTests test/test_DataLoader.cc test/test_ManifoldGeometry.cc test/test_BDTTrainer.cc)
target_link_libraries(UnitTests ${ROOT_LIBRARIES})
# Link Catch2
target_link_libraries(UnitTests Catch2::Catch2WithMain)
add_test(NAME BDTTests COMMAND UnitTests)

