set (CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.5)

set(RAYLACER
  Raylacer/Core/Pixel.cpp
  Raylacer/Core/Color.cpp
  Raylacer/Core/Vector.cpp
  Raylacer/Export/Export.cpp
  Raylacer/Shapes/Sphere.cpp
  Raylacer/Core/Ray.cpp
  Raylacer/Core/Screen.cpp
  Raylacer/Core/Light.cpp
  Raylacer/Core/Material.cpp
)


include_directories(
	${CMAKE_SOURCE_DIR}/.
)

set (DEMO
  Demo/main.cpp
)


add_executable(demo ${RAYLACER} ${DEMO} )
