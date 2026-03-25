from setuptools import find_packages, setup

package_name = 'ros2_python'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='jaewoo',
    maintainer_email='202017499@jbnu.ac.kr',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [ # 실행 파일
            'ex_pub_node_py = ros2_python.publisher:main',
            'ex_sub_node_py = ros2_python.subscriber:main',
            'service_server = ros2_python.service_server:main',
            'service_client = ros2_python.service_client:main',
            'action_server = ros2_python.action_server:main',
            'action_client = ros2_python.action_client:main'
        ],
    },
)
