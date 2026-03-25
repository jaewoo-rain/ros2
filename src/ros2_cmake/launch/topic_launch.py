from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
   return LaunchDescription([
       Node(
           package='ros2_cmake', # 패키지 이름
           namespace='ros2_cmake',
           executable='publisher', # 실행 파일
           name='ex_pub' # Node 이름
       ),
       Node(
           package='ros2_cmake',
           namespace='ros2_cmake',
           executable='subscriber',
           name='ex_sub'
       ),
   ])