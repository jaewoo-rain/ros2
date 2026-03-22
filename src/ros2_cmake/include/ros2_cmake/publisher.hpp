#include <chrono>
#include <memory>
#include <string>
#include <functional>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class StringPublisher : public rclcpp::Node // ROS Node로 Class정의
{
public:
    StringPublisher(std::string node_name, std::string topic_name): 
    Node(node_name)
    {
        publisher_= this->create_publisher<std_msgs::msg::String>(topic_name,10); // Publisher 생성
        timer_= this->create_wall_timer( 1s, std::bind(&StringPublisher::timer_callback, this)); // publish 함수
    }

private:
    void timer_callback()
    {
        auto message = std_msgs::msg::String();
        message.data = "Hello, world! " + std::to_string(count_++);
        RCLCPP_INFO(this->get_logger(), "publishing: '%s' ", message.data.c_str());
        publisher_->publish(message);
    }

        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        size_t count_;
    
};