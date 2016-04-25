cmake_minimum_required(VERSION 3.4)
project(CurveAssignment)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#########################################################
# FIND GLUT
#########################################################
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)

#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

set(SOURCE_FILES src/main.cpp src/Scene.cpp src/Scene.h src/float2.h src/float2.cpp src/Object.cpp src/Object.h src/Curve.cpp src/Curve.h src/Freeform.cpp src/Freeform.h src/BezierCurve.cpp src/BezierCurve.h src/LagrangeCurve.cpp src/LagrangeCurve.h src/PolyLine.cpp src/PolyLine.h src/Scene.cpp src/Scene.h)
add_executable(CurveAssignment ${SOURCE_FILES})

target_link_libraries(CurveAssignment ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )