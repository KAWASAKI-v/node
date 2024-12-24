cmake_minimum_required(VERSION 3.8)
project(fibonacci_publisher)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(fibonacci_publisher src/fibonacci_publisher.cpp)
ament_target_dependencies(fibonacci_publisher rclcpp std_msgs)

install(TARGETS
  fibonacci_publisher
  DESTINATION lib/${PROJECT_NAME})

ament_package()

