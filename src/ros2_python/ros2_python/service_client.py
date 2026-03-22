import sys
from ros2_interface.srv import ExCustomSrv
import rclpy
from rclpy.node import Node

# 서비스 클라이언트 노드 정의
class CustomClientAsync(Node):
    def __init__(self):
        # 노드 이름 설정
        super().__init__('minimal_client_async')

        # 서비스 클라이언트 생성
        # 서비스 이름: add_two_ints (서버와 동일해야 함)
        self.cli = self.create_client(ExCustomSrv, 'add_two_ints')

        # 서비스 서버가 준비될 때까지 기다림
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')

        # 요청 객체 생성
        self.req = ExCustomSrv.Request()

    # 서비스 요청 보내는 함수
    def send_request(self, a, b):
        self.req.a = a
        self.req.b = b

        # 비동기 요청 전송 (future 반환)
        return self.cli.call_async(self.req)


def main():
   rclpy.init()

   # 클라이언트 노드 생성
   custom_client = CustomClientAsync()

   # 터미널 입력값 가져오기
   future = custom_client.send_request(int(sys.argv[1]), int(sys.argv[2]))

   # 응답 올 때까지 기다림
   rclpy.spin_until_future_complete(custom_client, future)

   # 결과 받아오기
   response = future.result()

   # 결과 출력
   custom_client.get_logger().info(
       'Result of add_two_ints: for %d + %d = %d' % (
           int(sys.argv[1]), int(sys.argv[2]), response.sum))

   # 노드 종료
   custom_client.destroy_node()

   # ROS2 종료
   rclpy.shutdown()
   

if __name__ == '__main__':
   main()