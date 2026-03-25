#ifndef ROS2_CMAKE__ACTION_CLIENT_HPP_
#define ROS2_CMAKE__ACTION_CLIENT_HPP_

#include <functional>
#include <future>
#include <memory>
#include <string>
#include <sstream>
#include "ros2_interface/action/fibonacci.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

// 타입 alias (간단하게 쓰려고)
using Fibonacci = ros2_interface::action::Fibonacci;
using GoalHandleFibonacci = rclcpp_action::ClientGoalHandle<Fibonacci>;

// Action Client 클래스
class FibonacciActionClient : public rclcpp::Node
{
public:

   // 생성자 (노드 옵션 포함)
   explicit FibonacciActionClient(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

   // 소멸자 (기본)
   virtual ~FibonacciActionClient() =default;

   // goal을 서버로 보내는 함수
   void send_goal();

private:

   // Action Client 객체 (서버와 통신)
   rclcpp_action::Client<Fibonacci>::SharedPtr client_ptr_;

   // 타이머 (일정 시간 후 goal 보내는 용도)
   rclcpp::TimerBase::SharedPtr timer_;

   // goal 요청 후, 서버가 응답했을 때 호출되는 콜백
   void goal_response_callback(const GoalHandleFibonacci::SharedPtr & goal_handle);

   // 서버에서 중간 결과(feedback)를 보낼 때 호출되는 콜백
   void feedback_callback(
       GoalHandleFibonacci::SharedPtr,
       const std::shared_ptr<const Fibonacci::Feedback> feedback);

   // 최종 결과(result)를 받을 때 호출되는 콜백
   void result_callback(const GoalHandleFibonacci::WrappedResult & result);

};  // class FibonacciActionClient

// 헤더 가드 끝
#endif // ROS2_CMAKE__ACTION_SERVER_HPP_