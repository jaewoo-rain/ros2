#include "rclcpp/rclcpp.hpp"
#include "ros2_interface/srv/ex_custom_srv.hpp"
#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
    // ROS2 초기화
    rclcpp::init(argc, argv);

    // 노드 생성
    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("param_client");

    // 서비스 클라이언트 생성
    // "add_two_ints"라는 이름의 서비스를 요청할 수 있는 client
    rclcpp::Client<ros2_interface::srv::ExCustomSrv>::SharedPtr client =
        node->create_client<ros2_interface::srv::ExCustomSrv>("add_two_ints");

    // 유효하지 않은 기본값 설정
    // 파라미터가 제대로 안 들어왔는지 검사하기 위한 용도
    const int invalid_value = std::numeric_limits<int>::min();

    int num1 = invalid_value;
    int num2 = invalid_value;

    // 사용할 파라미터 이름
    std::string param_name1 = "number1";
    std::string param_name2 = "number2";

    // 파라미터 선언
    // number1, number2를 정수형 파라미터로 선언
    node->declare_parameter(param_name1, rclcpp::PARAMETER_INTEGER);
    node->declare_parameter(param_name2, rclcpp::PARAMETER_INTEGER);

    // 파라미터 값 얻기 (number1)
    if (!node->get_parameter(param_name1, num1)) {
        RCLCPP_WARN(
            node->get_logger(),
            "Parameter '%s' not found, using default invalid value",
            param_name1.c_str()
        );
    }

    // 파라미터 값 얻기 (number2)
    if (!node->get_parameter(param_name2, num2)) {
        RCLCPP_WARN(
            node->get_logger(),
            "Parameter '%s' not found, using default invalid value",
            param_name2.c_str()
        );
    }

    // 유효성 검사
    // 두 숫자 파라미터를 모두 제대로 얻었는지 확인
    if (num1 == invalid_value || num2 == invalid_value) {
        RCLCPP_ERROR(
            node->get_logger(),
            "Invalid parameters detected. num1 = %d, num2 = %d. Check your parameter settings.",
            num1,
            num2
        );
        rclcpp::shutdown();
        return 1;
    }

    // 서비스 요청 메시지 생성
    auto request = std::make_shared<ros2_interface::srv::ExCustomSrv::Request>();

    // 요청 값 설정
    request->a = num1;
    request->b = num2;

    // 서비스 서버가 준비될 때까지 1초 간격으로 대기
    while (!client->wait_for_service(1s)) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(
                rclcpp::get_logger("rclcpp"),
                "Interrupted while waiting for the service. Exiting."
            );
            return 0;
        }

        RCLCPP_INFO(
            rclcpp::get_logger("rclcpp"),
            "service not available, waiting again..."
        );
    }

    // 비동기로 서비스 요청 보내기
    auto result = client->async_send_request(request);

    // 응답 올 때까지 대기
    if (rclcpp::spin_until_future_complete(node, result) ==
        rclcpp::FutureReturnCode::SUCCESS)
    {
        // 성공 시 결과 출력
        RCLCPP_INFO(
            rclcpp::get_logger("rclcpp"),
            "Sum: %ld",
            result.get()->sum
        );
    } else {
        // 실패 시 에러 출력
        RCLCPP_ERROR(
            rclcpp::get_logger("rclcpp"),
            "Failed to call service add_two_ints"
        );
    }

    // 노드 실행
    rclcpp::spin(node);

    // ROS2 종료
    rclcpp::shutdown();
    return 0;
}