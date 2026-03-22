// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_interface:srv/ExCustomSrv.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACE__SRV__DETAIL__EX_CUSTOM_SRV__TRAITS_HPP_
#define ROS2_INTERFACE__SRV__DETAIL__EX_CUSTOM_SRV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros2_interface/srv/detail/ex_custom_srv__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros2_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const ExCustomSrv_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: a
  {
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << ", ";
  }

  // member: b
  {
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExCustomSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << "\n";
  }

  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExCustomSrv_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros2_interface

namespace rosidl_generator_traits
{

[[deprecated("use ros2_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros2_interface::srv::ExCustomSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros2_interface::srv::ExCustomSrv_Request & msg)
{
  return ros2_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_interface::srv::ExCustomSrv_Request>()
{
  return "ros2_interface::srv::ExCustomSrv_Request";
}

template<>
inline const char * name<ros2_interface::srv::ExCustomSrv_Request>()
{
  return "ros2_interface/srv/ExCustomSrv_Request";
}

template<>
struct has_fixed_size<ros2_interface::srv::ExCustomSrv_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros2_interface::srv::ExCustomSrv_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros2_interface::srv::ExCustomSrv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ros2_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const ExCustomSrv_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: sum
  {
    out << "sum: ";
    rosidl_generator_traits::value_to_yaml(msg.sum, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExCustomSrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sum
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sum: ";
    rosidl_generator_traits::value_to_yaml(msg.sum, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExCustomSrv_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros2_interface

namespace rosidl_generator_traits
{

[[deprecated("use ros2_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros2_interface::srv::ExCustomSrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros2_interface::srv::ExCustomSrv_Response & msg)
{
  return ros2_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_interface::srv::ExCustomSrv_Response>()
{
  return "ros2_interface::srv::ExCustomSrv_Response";
}

template<>
inline const char * name<ros2_interface::srv::ExCustomSrv_Response>()
{
  return "ros2_interface/srv/ExCustomSrv_Response";
}

template<>
struct has_fixed_size<ros2_interface::srv::ExCustomSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros2_interface::srv::ExCustomSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros2_interface::srv::ExCustomSrv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros2_interface::srv::ExCustomSrv>()
{
  return "ros2_interface::srv::ExCustomSrv";
}

template<>
inline const char * name<ros2_interface::srv::ExCustomSrv>()
{
  return "ros2_interface/srv/ExCustomSrv";
}

template<>
struct has_fixed_size<ros2_interface::srv::ExCustomSrv>
  : std::integral_constant<
    bool,
    has_fixed_size<ros2_interface::srv::ExCustomSrv_Request>::value &&
    has_fixed_size<ros2_interface::srv::ExCustomSrv_Response>::value
  >
{
};

template<>
struct has_bounded_size<ros2_interface::srv::ExCustomSrv>
  : std::integral_constant<
    bool,
    has_bounded_size<ros2_interface::srv::ExCustomSrv_Request>::value &&
    has_bounded_size<ros2_interface::srv::ExCustomSrv_Response>::value
  >
{
};

template<>
struct is_service<ros2_interface::srv::ExCustomSrv>
  : std::true_type
{
};

template<>
struct is_service_request<ros2_interface::srv::ExCustomSrv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ros2_interface::srv::ExCustomSrv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROS2_INTERFACE__SRV__DETAIL__EX_CUSTOM_SRV__TRAITS_HPP_
