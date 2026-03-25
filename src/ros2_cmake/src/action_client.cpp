#include "ros2_cmake/action_client.hpp"

// 생성자: Action Client 초기화
FibonacciActionClient::FibonacciActionClient(const rclcpp::NodeOptions & options)
: Node("fibonacci_action_client", options) // 노드 이름 설정
{
 // Action Server와 연결할 client 생성
 this->client_ptr_ = rclcpp_action::create_client<Fibonacci>(
   this,
   "fibonacci"); // 서버 이름과 동일해야 함

 // 0.5초 후 send_goal 실행하는 타이머
 this->timer_ = this->create_wall_timer(
   std::chrono::milliseconds(500),
   std::bind(&FibonacciActionClient::send_goal, this));
}


// goal을 서버로 보내는 함수
void FibonacciActionClient::send_goal()
{
 using namespace std::placeholders;

 // 타이머는 한 번만 실행되도록 취소
 this->timer_->cancel();

 // Action Server가 준비될 때까지 대기
 if (!this->client_ptr_->wait_for_action_server()) {
   RCLCPP_ERROR(this->get_logger(), "Action server not available after waiting");
   rclcpp::shutdown(); // 서버 없으면 종료
 }

 // goal 메시지 생성
 auto goal_msg = Fibonacci::Goal();
 goal_msg.order = 20; // 피보나치 몇 개 계산할지 설정

 RCLCPP_INFO(this->get_logger(), "Sending goal");

 // goal 전송 옵션 설정 (콜백 등록)
 auto send_goal_options = rclcpp_action::Client<Fibonacci>::SendGoalOptions();

 // 서버가 goal을 받았을 때 호출
 send_goal_options.goal_response_callback =
   std::bind(&FibonacciActionClient::goal_response_callback, this, _1);

 // 서버가 중간 결과(feedback) 보낼 때 호출
 send_goal_options.feedback_callback =
   std::bind(&FibonacciActionClient::feedback_callback, this, _1, _2);

 // 서버가 최종 결과(result) 보낼 때 호출
 send_goal_options.result_callback =
   std::bind(&FibonacciActionClient::result_callback, this, _1);

 // 비동기로 goal 전송
 this->client_ptr_->async_send_goal(goal_msg, send_goal_options);
}


// 서버가 goal 요청에 응답했을 때 실행
void FibonacciActionClient::goal_response_callback(const GoalHandleFibonacci::SharedPtr & goal_handle)
{
 // goal이 거절된 경우
 if (!goal_handle) {
   RCLCPP_ERROR(this->get_logger(), "Goal was rejected by server");
 } else {
   // goal이 정상적으로 수락됨
   RCLCPP_INFO(this->get_logger(), "Goal accepted by server, waiting for result");
 }
}


// 서버에서 feedback(중간 결과) 받을 때 실행
void FibonacciActionClient::feedback_callback(
 GoalHandleFibonacci::SharedPtr,
 const std::shared_ptr<const Fibonacci::Feedback> feedback)
{
 std::stringstream ss;
 ss << "Next number in sequence received: ";

 // 현재까지 계산된 피보나치 수열 출력
 for (auto number : feedback->partial_sequence) {
   ss << number << " ";
 }

 RCLCPP_INFO(this->get_logger(), ss.str().c_str());
}


// 서버에서 최종 결과(result) 받을 때 실행
void FibonacciActionClient::result_callback(const GoalHandleFibonacci::WrappedResult & result)
{
 // 결과 상태 확인
 switch (result.code) {

   case rclcpp_action::ResultCode::SUCCEEDED:
     break;

   case rclcpp_action::ResultCode::ABORTED:
     RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
     return;

   case rclcpp_action::ResultCode::CANCELED:
     RCLCPP_ERROR(this->get_logger(), "Goal was canceled");
     return;

   default:
     RCLCPP_ERROR(this->get_logger(), "Unknown result code");
     return;
 }

 // 결과 출력
 std::stringstream ss;
 ss << "Result received: ";

 // 최종 피보나치 수열 출력
 for (auto number : result.result->sequence) {
   ss << number << " ";
 }

 RCLCPP_INFO(this->get_logger(), ss.str().c_str());

 // 작업 끝났으니 ROS 종료
 rclcpp::shutdown();
}


// main 함수
int main(int argc, char * argv[]) {
 rclcpp::init(argc, argv); // ROS 초기화

 auto action_client = std::make_shared<FibonacciActionClient>();

 rclcpp::spin(action_client); // 노드 실행

 rclcpp::shutdown(); // 종료
 return 0;
}