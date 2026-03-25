from ament_index_python.packages import get_package_share_path
from ament_index_python.packages import get_package_prefix

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition, UnlessCondition
from launch.substitutions import Command, LaunchConfiguration

from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue

import os


def generate_launch_description():
    # 현재 패키지 이름
    package_name = "ros2_urdf"

    # urdf_tutorial 패키지의 share 경로 가져오기
    urdf_tutorial_path = get_package_share_path('urdf_tutorial')

    # 현재 패키지 install 경로 가져오기
    default_model_path = get_package_prefix(package_name)

    # install → src 경로로 변경 (소스 코드 경로로 접근하기 위함)
    default_model_path = default_model_path.replace("install", "src")

    # URDF 파일 경로 설정
    default_model_path = os.path.join(default_model_path, "robot/dof3_manipulator.urdf")

    # RViz 기본 설정 파일 경로
    default_rviz_config_path = urdf_tutorial_path / 'rviz/urdf.rviz'

    # GUI 사용 여부 (joint_state_publisher_gui 실행 여부)
    gui_arg = DeclareLaunchArgument(
        name='gui',
        default_value='true',
        choices=['true', 'false'],
        description='Flag to enable joint_state_publisher_gui'
    )

    # URDF 모델 경로 인자
    model_arg = DeclareLaunchArgument(
        name='model',
        default_value=str(default_model_path),
        description='Absolute path to robot urdf file'
    )

    # RViz 설정 파일 경로 인자
    rviz_arg = DeclareLaunchArgument(
        name='rvizconfig',
        default_value=str(default_rviz_config_path),
        description='Absolute path to rviz config file'
    )

    # xacro 명령을 통해 URDF를 robot_description 파라미터로 변환
    robot_description = ParameterValue(
        Command(['xacro ', LaunchConfiguration('model')]),
        value_type=str
    )

    # robot_state_publisher 노드 (TF를 퍼블리시)
    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': robot_description}]
    )

    # gui 값이 false일 때 실행 (CLI 기반 joint state publisher)
    joint_state_publisher_node = Node(
        package='joint_state_publisher',
        executable='joint_state_publisher',
        condition=UnlessCondition(LaunchConfiguration('gui'))
    )

    # gui 값이 true일 때 실행 (슬라이더 GUI 제공)
    joint_state_publisher_gui_node = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui',
        condition=IfCondition(LaunchConfiguration('gui'))
    )

    # RViz 실행 노드
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', LaunchConfiguration('rvizconfig')],
    )

    # launch 실행 목록 반환
    return LaunchDescription([
        gui_arg,
        model_arg,
        rviz_arg,
        joint_state_publisher_node,
        joint_state_publisher_gui_node,
        robot_state_publisher_node,
        rviz_node
    ])