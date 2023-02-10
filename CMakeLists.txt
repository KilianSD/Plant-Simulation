cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(PlantSimulation LANGUAGES CXX)
add_library(PlantSimHeaders
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

add_executable(PlantSimulation ./src/main.cpp)

target_link_libraries(PlantSimulation PRIVATE unofficial::sqlite3::sqlite3 dpp::dpp lodepng PlantSimHeaders)
