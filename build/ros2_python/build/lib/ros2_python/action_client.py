import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from ros2_interface.action import Fibonacci


class FibonacciActionClient(Node):

    def __init__(self):
        # 노드 이름 설정
        super().__init__('fibonacci_action_client')

        # Action Client 생성 (서버와 연결)
        self._action_client = ActionClient(self, Fibonacci, 'fibonacci')


    def send_goal(self, order):
        # goal 메시지 생성
        goal_msg = Fibonacci.Goal()
        goal_msg.order = order  # 몇 개까지 피보나치 계산할지

        # 서버가 준비될 때까지 대기
        self._action_client.wait_for_server()

        # 비동기로 goal 전송
        self._send_goal_future = self._action_client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback  # 중간 결과 받을 콜백
        )

        # goal 응답 받았을 때 실행될 콜백 등록
        self._send_goal_future.add_done_callback(self.goal_response_callback)


    def goal_response_callback(self, future):
        # 서버의 응답 결과 가져오기
        goal_handle = future.result()

        # goal이 거절된 경우
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected :(')
            return

        # goal이 정상적으로 수락된 경우
        self.get_logger().info('Goal accepted :)')

        # 결과를 비동기로 요청
        self._get_result_future = goal_handle.get_result_async()

        # 결과가 도착했을 때 실행될 콜백 등록
        self._get_result_future.add_done_callback(self.get_result_callback)


    def get_result_callback(self, future):
        # 최종 결과 가져오기
        result = future.result().result

        # 결과 출력
        self.get_logger().info('Result: {0}'.format(result.sequence))

        # 작업 완료 후 ROS 종료
        rclpy.shutdown()


    def feedback_callback(self, feedback_msg):
        # 서버에서 보내온 중간 결과(feedback)
        feedback = feedback_msg.feedback

        # 현재까지 계산된 피보나치 수열 출력
        self.get_logger().info(
            'Received feedback: {0}'.format(feedback.partial_sequence)
        )


def main(args=None):
    # ROS2 초기화
    rclpy.init(args=args)

    # Action Client 생성
    action_client = FibonacciActionClient()

    # goal 전송 (10개 피보나치)
    action_client.send_goal(10)

    # 노드 실행
    rclpy.spin(action_client)


if __name__ == '__main__':
    main()