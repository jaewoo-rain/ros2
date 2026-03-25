import time
import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from ros2_interface.action import Fibonacci


class FibonacciActionServer(Node):

    def __init__(self):
        # 노드 이름을 fibonacci_action_server로 설정
        super().__init__('fibonacci_action_server')

        # Action Server 생성
        # - self: 현재 노드
        # - Fibonacci: 사용할 액션 타입
        # - 'fibonacci': 액션 이름
        # - self.execute_callback: goal이 들어왔을 때 실제로 실행할 함수
        self._action_server = ActionServer(
            self,
            Fibonacci,
            'fibonacci',
            self.execute_callback
        )

    def execute_callback(self, goal_handle):
        # goal을 받아 실제 작업을 수행하는 콜백 함수
        self.get_logger().info('Executing goal...')

        # feedback 메시지 객체 생성
        feedback_msg = Fibonacci.Feedback()

        # 피보나치 수열 초기값 설정
        feedback_msg.partial_sequence = [0, 1]

        # 요청받은 order만큼 피보나치 수열 계산
        for i in range(1, goal_handle.request.order):
            # 다음 피보나치 값 추가
            feedback_msg.partial_sequence.append(
                feedback_msg.partial_sequence[i] + feedback_msg.partial_sequence[i - 1]
            )

            # 현재까지의 진행 상황 로그 출력
            self.get_logger().info(
                'Feedback: {0}'.format(feedback_msg.partial_sequence)
            )

            # 클라이언트에게 중간 결과(feedback) 전송
            goal_handle.publish_feedback(feedback_msg)

            # 1초 대기 (시간이 걸리는 작업처럼 보이게 함)
            time.sleep(1)

        # 작업이 성공적으로 끝났음을 알림
        goal_handle.succeed()

        # 최종 결과 메시지 생성
        result = Fibonacci.Result()

        # 최종 피보나치 수열 저장
        result.sequence = feedback_msg.partial_sequence

        # 결과 반환
        return result


def main(args=None):
    # ROS2 Python 초기화
    rclpy.init(args=args)

    # Action Server 노드 생성
    fibonacci_action_server = FibonacciActionServer()

    # 노드 실행
    rclpy.spin(fibonacci_action_server)


if __name__ == '__main__':
    main()