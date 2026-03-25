// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_interface:action/Fibonnacci.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACE__ACTION__DETAIL__FIBONNACCI__BUILDER_HPP_
#define ROS2_INTERFACE__ACTION__DETAIL__FIBONNACCI__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_interface/action/detail/fibonnacci__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_interface
{

namespace action
{

namespace builder
{

class Init_Fibonnacci_Goal_order
{
public:
  Init_Fibonnacci_Goal_order()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2_interface::action::Fibonnacci_Goal order(::ros2_interface::action::Fibonnacci_Goal::_order_type arg)
  {
    msg_.order = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interface::action::Fibonnacci_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interface::action::Fibonnacci_Goal>()
{
  return ros2_interface::action::builder::Init_Fibonnacci_Goal_order();
}

}  // namespace ros2_interface


namespace ros2_interface
{

namespace action
{

namespace builder
{

class Init_Fibonnacci_Result_sequence
{
public:
  Init_Fibonnacci_Result_sequence()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2_interface::action::Fibonnacci_Result sequence(::ros2_interface::action::Fibonnacci_Result::_sequence_type arg)
  {
    msg_.sequence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interface::action::Fibonnacci_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interface::action::Fibonnacci_Result>()
{
  return ros2_interface::action::builder::Init_Fibonnacci_Result_sequence();
}

}  // namespace ros2_interface


namespace ros2_interface
{

namespace action
{

namespace builder
{

class Init_Fibonnacci_Feedback_partial_sequence
{
public:
  Init_Fibonnacci_Feedback_partial_sequence()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2_interface::action::Fibonnacci_Feedback partial_sequence(::ros2_interface::action::Fibonnacci_Feedback::_partial_sequence_type arg)
  {
    msg_.partial_sequence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interface::action::Fibonnacci_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interface::action::Fibonnacci_Feedback>()
{
  return ros2_interface::action::builder::Init_Fibonnacci_Feedback_partial_sequence();
}

}  // namespace ros2_interface


namespace ros2_interface
{

namespace action
{

namespace builder
{

class Init_Fibonnacci_SendGoal_Request_goal
{
public:
  explicit Init_Fibonnacci_SendGoal_Request_goal(::ros2_interface::action::Fibonnacci_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::ros2_interface::action::Fibonnacci_SendGoal_Request goal(::ros2_interface::action::Fibonnacci_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interface::action::Fibonnacci_SendGoal_Request msg_;
};

class Init_Fibonnacci_SendGoal_Request_goal_id
{
public:
  Init_Fibonnacci_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Fibonnacci_SendGoal_Request_goal goal_id(::ros2_interface::action::Fibonnacci_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Fibonnacci_SendGoal_Request_goal(msg_);
  }

private:
  ::ros2_interface::action::Fibonnacci_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interface::action::Fibonnacci_SendGoal_Request>()
{
  return ros2_interface::action::builder::Init_Fibonnacci_SendGoal_Request_goal_id();
}

}  // namespace ros2_interface


namespace ros2_interface
{

namespace action
{

namespace builder
{

class Init_Fibonnacci_SendGoal_Response_stamp
{
public:
  explicit Init_Fibonnacci_SendGoal_Response_stamp(::ros2_interface::action::Fibonnacci_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::ros2_interface::action::Fibonnacci_SendGoal_Response stamp(::ros2_interface::action::Fibonnacci_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interface::action::Fibonnacci_SendGoal_Response msg_;
};

class Init_Fibonnacci_SendGoal_Response_accepted
{
public:
  Init_Fibonnacci_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Fibonnacci_SendGoal_Response_stamp accepted(::ros2_interface::action::Fibonnacci_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Fibonnacci_SendGoal_Response_stamp(msg_);
  }

private:
  ::ros2_interface::action::Fibonnacci_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interface::action::Fibonnacci_SendGoal_Response>()
{
  return ros2_interface::action::builder::Init_Fibonnacci_SendGoal_Response_accepted();
}

}  // namespace ros2_interface


namespace ros2_interface
{

namespace action
{

namespace builder
{

class Init_Fibonnacci_GetResult_Request_goal_id
{
public:
  Init_Fibonnacci_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2_interface::action::Fibonnacci_GetResult_Request goal_id(::ros2_interface::action::Fibonnacci_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interface::action::Fibonnacci_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interface::action::Fibonnacci_GetResult_Request>()
{
  return ros2_interface::action::builder::Init_Fibonnacci_GetResult_Request_goal_id();
}

}  // namespace ros2_interface


namespace ros2_interface
{

namespace action
{

namespace builder
{

class Init_Fibonnacci_GetResult_Response_result
{
public:
  explicit Init_Fibonnacci_GetResult_Response_result(::ros2_interface::action::Fibonnacci_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::ros2_interface::action::Fibonnacci_GetResult_Response result(::ros2_interface::action::Fibonnacci_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interface::action::Fibonnacci_GetResult_Response msg_;
};

class Init_Fibonnacci_GetResult_Response_status
{
public:
  Init_Fibonnacci_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Fibonnacci_GetResult_Response_result status(::ros2_interface::action::Fibonnacci_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Fibonnacci_GetResult_Response_result(msg_);
  }

private:
  ::ros2_interface::action::Fibonnacci_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interface::action::Fibonnacci_GetResult_Response>()
{
  return ros2_interface::action::builder::Init_Fibonnacci_GetResult_Response_status();
}

}  // namespace ros2_interface


namespace ros2_interface
{

namespace action
{

namespace builder
{

class Init_Fibonnacci_FeedbackMessage_feedback
{
public:
  explicit Init_Fibonnacci_FeedbackMessage_feedback(::ros2_interface::action::Fibonnacci_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::ros2_interface::action::Fibonnacci_FeedbackMessage feedback(::ros2_interface::action::Fibonnacci_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_interface::action::Fibonnacci_FeedbackMessage msg_;
};

class Init_Fibonnacci_FeedbackMessage_goal_id
{
public:
  Init_Fibonnacci_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Fibonnacci_FeedbackMessage_feedback goal_id(::ros2_interface::action::Fibonnacci_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Fibonnacci_FeedbackMessage_feedback(msg_);
  }

private:
  ::ros2_interface::action::Fibonnacci_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_interface::action::Fibonnacci_FeedbackMessage>()
{
  return ros2_interface::action::builder::Init_Fibonnacci_FeedbackMessage_goal_id();
}

}  // namespace ros2_interface

#endif  // ROS2_INTERFACE__ACTION__DETAIL__FIBONNACCI__BUILDER_HPP_
