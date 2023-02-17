cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
# Set C++20 Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Check for C++17 support
if(CMAKE_CXX_STANDARD LESS 17)
    message(FATAL_ERROR "ERROR: Plant Simulation, requires atleast a <= C++17 compatible compiler to build. Please make sure you have enabled C++ 17 support in your compiler flags. If C++ 17 support is already enabled and you are still encountering this error, please check that your CMakeLists.txt file is configured correctly. If you are unsure how to enable C++17 support in your compiler flags, please refer to your compiler's documentation.")
endif()

project(PlantSimulation LANGUAGES CXX)
add_library(PlantSimulationHeaders
STATIC
"./src/color.cpp"
"./src/date.cpp"
"./src/flower.cpp"
"./src/fruit.cpp"
"./src/plant.cpp"
"./src/vegetable.cpp"
)

find_package(lodepng CONFIG REQUIRED)
find_package(unofficial-sqlite3 CONFIG REQUIRED)
find_package(dpp CONFIG REQUIRED)

if (NOT lodepng_FOUND)
    message(FATAL_ERROR "LodePNG library not found")
endif()

if(NOT unofficial-sqlite3_FOUND)
    message(FATAL_ERROR "SQLite3 library not found")
endif()

if(NOT dpp_FOUND)
    message(FATAL_ERROR "D++ library not found")
endif()

include_directories(
    C:/vcpkg/installed/${VCPKG_TARGET_TRIPLET}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
add_executable(PlantSimulation ./src/main.cpp)

target_link_libraries(PlantSimulation PRIVATE unofficial::sqlite3::sqlite3 dpp::dpp lodepng PlantSimulationHeaders)
