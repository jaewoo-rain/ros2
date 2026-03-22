cmake_minimum_required(VERSION 3.8)
project(ros2_cmake) # PROJECT_NAME 정의

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
include_directories(include)

# topic - publisher
add_executable(publisher src/publisher.cpp) # 컴파일해서 실행파일(프로그램)을 만들겠다
ament_target_dependencies(publisher rclcpp std_msgs) # 이 실행파일이 사용할 ROS2 라이브러리들을 연결(link)

# topic - subscriber
add_executable(subscriber src/subscriber.cpp)
ament_target_dependencies(subscriber rclcpp std_msgs)

# 빌드된 실행파일을 install 폴더에 복사해서 ROS2가 실행할 수 있게 해라
install(TARGETS
  # topic 실행 파일 이름
  publisher
  subscriber
  DESTINATION lib/${PROJECT_NAME}
)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
