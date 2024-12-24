cmake_minimum_required(VERSION 3.5)
project(fibonacci_subscriber)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(fibonacci_subscriber src/fibonacci_subscriber.cpp)
ament_target_dependencies(fibonacci_subscriber rclcpp std_msgs)

install(TARGETS
  fibonacci_subscriber
  DESTINATION lib/${PROJECT_NAME})

ament_package()

