#include "ros2_cmake/action_server.hpp"

// 생성자: Action Server를 초기화하는 부분
FibonacciActionServer::FibonacciActionServer(const rclcpp::NodeOptions & options )
 : Node("fibonacci_action_server", options) // 노드 이름 설정
 {
    using namespace std::placeholders;

    // Action Server 생성
    action_server_ = rclcpp_action::create_server<Fibonacci>(
        this,                         // 현재 노드
        "fibonacci",                  // action 이름 (클라이언트가 이 이름으로 요청)
        std::bind(&FibonacciActionServer::handle_goal, this, _1, _2),     // goal 요청 처리
        std::bind(&FibonacciActionServer::handle_cancel, this, _1),       // cancel 요청 처리
        std::bind(&FibonacciActionServer::handle_accepted, this, _1));    // goal 수락 후 실행
 }


// 1. Goal 요청 들어왔을 때 실행되는 함수
rclcpp_action::GoalResponse FibonacciActionServer::handle_goal(
   const rclcpp_action::GoalUUID & uuid,
   std::shared_ptr<const Fibonacci::Goal> goal)
 {
   // 클라이언트가 요청한 order 값 출력
   RCLCPP_INFO(this->get_logger(), "Received goal request with order %d", goal->order);

   (void)uuid; // uuid는 사용 안해서 경고 방지

   // goal을 받아서 실행하겠다고 응답
   return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
 }


// 2. cancel 요청이 들어왔을 때 실행
rclcpp_action::CancelResponse FibonacciActionServer::handle_cancel(
const std::shared_ptr<GoalHandleFibonacci> goal_handle)
{
    RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");

    (void)goal_handle; // 사용 안함

    // cancel 요청을 받아들이겠다고 응답
    return rclcpp_action::CancelResponse::ACCEPT;
    }


// 3. goal이 accept되었을 때 실행
void FibonacciActionServer::handle_accepted(const std::shared_ptr<GoalHandleFibonacci> goal_handle)
{
    using namespace std::placeholders;

    // 중요 포인트
    // execute를 바로 실행하면 spin()이 막힘 → 그래서 thread로 실행
    std::thread{
        std::bind(&FibonacciActionServer::execute, this, _1),
        goal_handle
    }.detach(); // detach → 백그라운드 실행
}


// 4. 실제 계산 (핵심 로직)
void FibonacciActionServer::execute(const std::shared_ptr<GoalHandleFibonacci> goal_handle)
{
   RCLCPP_INFO(this->get_logger(), "Executing goal");

   // 1초 간격으로 실행
   rclcpp::Rate loop_rate(1);

   // 클라이언트가 보낸 goal 값
   const auto goal = goal_handle->get_goal();

   // feedback 메시지 (중간 결과)
   auto feedback = std::make_shared<Fibonacci::Feedback>();

   // sequence 참조
   auto & sequence = feedback->partial_sequence;

   // 초기값 (피보나치 시작)
   sequence.push_back(0);
   sequence.push_back(1);

   // 최종 결과
   auto result = std::make_shared<Fibonacci::Result>();


   // 피보나치 계산 루프
   for (int i = 1; (i < goal->order) && rclcpp::ok(); ++i) {

       // cancel 요청 확인
       if (goal_handle->is_canceling()) {
           result->sequence = sequence;
           goal_handle->canceled(result); // cancel 상태 반환
           RCLCPP_INFO(this->get_logger(), "Goal canceled");
           return;
       }

       // 다음 피보나치 값 계산
       sequence.push_back(sequence[i] + sequence[i - 1]);

       // 중간 결과(feedback) 클라이언트에게 전송
       goal_handle->publish_feedback(feedback);
       RCLCPP_INFO(this->get_logger(), "Publish feedback");

       loop_rate.sleep(); // 1초 대기
   }


   // 정상 종료
   if (rclcpp::ok()) {
       result->sequence = sequence;
       goal_handle->succeed(result); // 성공 상태 반환
       RCLCPP_INFO(this->get_logger(), "Goal succeeded");
   }
}


// main 함수
int main(int argc, char * argv[])
{
 rclcpp::init(argc, argv); // ROS 초기화

 auto action_server = std::make_shared<FibonacciActionServer>();

 rclcpp::spin(action_server); // 노드 실행 (이벤트 대기)

 rclcpp::shutdown(); // 종료
 return 0;
}