// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_interface:srv/ExCustomSrv.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACE__SRV__DETAIL__EX_CUSTOM_SRV__BUILDER_HPP_
#define ROS2_INTERFACE__SRV__DETAIL__EX_CUSTOM_SRV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_interface/srv/detail/ex_custom_srv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_interface
{

namespace srv
{

namespace builder
{

class Init_ExCustomSrv_Request_b
{
public:
  explicit Init_ExCustomSrv_Request_b(::ros2_interface::srv::ExCustomSrv_Request & msg)
  : msg_(msg)
  {}
  ::ros2_interface::srv::ExCustomSrv_Request b(::ros2_interface::srv::ExCustomSrv_Request::_b_type arg)
  {
    msg_.b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interface::srv::ExCustomSrv_Request msg_;
};

class Init_ExCustomSrv_Request_a
{
public:
  Init_ExCustomSrv_Request_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExCustomSrv_Request_b a(::ros2_interface::srv::ExCustomSrv_Request::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_ExCustomSrv_Request_b(msg_);
  }

private:
  ::ros2_interface::srv::ExCustomSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interface::srv::ExCustomSrv_Request>()
{
  return ros2_interface::srv::builder::Init_ExCustomSrv_Request_a();
}

}  // namespace ros2_interface


namespace ros2_interface
{

namespace srv
{

namespace builder
{

class Init_ExCustomSrv_Response_sum
{
public:
  Init_ExCustomSrv_Response_sum()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2_interface::srv::ExCustomSrv_Response sum(::ros2_interface::srv::ExCustomSrv_Response::_sum_type arg)
  {
    msg_.sum = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interface::srv::ExCustomSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interface::srv::ExCustomSrv_Response>()
{
  return ros2_interface::srv::builder::Init_ExCustomSrv_Response_sum();
}

}  // namespace ros2_interface

#endif  // ROS2_INTERFACE__SRV__DETAIL__EX_CUSTOM_SRV__BUILDER_HPP_
