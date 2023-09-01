cmake_minimum_required(VERSION 3.0.2)
project(pepper_demos)

add_compile_options(-std=c++14)

find_package(catkin REQUIRED COMPONENTS
  pepper_demo_lib
  roscpp
  nao_interaction_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES pepper_demos
   CATKIN_DEPENDS pepper_demo_lib roscpp
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(pepper_demos src/pepper_demos.cpp)
target_link_libraries(pepper_demos ${catkin_LIBRARIES} ${pepper_demo_lib_LIBRARIES})
add_dependencies(pepper_demos ${catkin_EXPORTED_TARGETS})