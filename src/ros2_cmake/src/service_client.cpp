#include "rclcpp/rclcpp.hpp"
#include "ros2_interface/srv/ex_custom_srv.hpp"
#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    // 실행 시 인자 체크
    if (argc != 3) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "usage: add_two_ints_client X Y");
        return 1;
    }

    // 노드 생성 (이름: add_two_ints_client)
    std::shared_ptr<rclcpp::Node> node = 
        rclcpp::Node::make_shared("add_two_ints_client");

    // 서비스 클라이언트 생성
    // "add_two_ints" 라는 이름의 서비스에 요청을 보냄
    rclcpp::Client<ros2_interface::srv::ExCustomSrv>::SharedPtr client =
        node->create_client<ros2_interface::srv::ExCustomSrv>("add_two_ints");

    // 요청 객체 생성
    auto request = std::make_shared<ros2_interface::srv::ExCustomSrv::Request>();

    // 입력값을 숫자로 변환해서 request에 넣기
    request->a = atoll(argv[1]);
    request->b = atoll(argv[2]);

    // 서비스 서버가 준비될 때까지 기다림
    while (!client->wait_for_service(1s)) {
        // ROS가 종료 상태라면
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"),
                         "Interrupted while waiting for the service. Exiting.");
            return 0;
        }

        // 아직 서비스가 없으면 계속 기다림
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"),
                    "service not available, waiting again...");
    }

    // 비동기 요청 보내기
    auto result = client->async_send_request(request);

    // 결과 올 때까지 대기
    if (rclcpp::spin_until_future_complete(node, result) == rclcpp::FutureReturnCode::SUCCESS)
    {
        // 결과 출력 (sum 값)
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"),
                    "Sum: %ld", result.get()->sum);
    } 
    else {
        // 실패했을 때
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"),
                     "Failed to call service add_two_ints");
    }

    // ROS2 종료
    rclcpp::shutdown();
    return 0;
}