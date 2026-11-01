cmake_minimum_required(VERSION 3.16)
  project(se3-lib LANGUAGES CXX)

  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)

  find_package(Eigen3 REQUIRED)

  add_executable(demo src/main.cpp)
  target_link_libraries(demo PRIVATE Eigen3::Eigen)
