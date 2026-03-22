// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2_interface:srv/ExCustomSrv.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACE__SRV__DETAIL__EX_CUSTOM_SRV__STRUCT_HPP_
#define ROS2_INTERFACE__SRV__DETAIL__EX_CUSTOM_SRV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ros2_interface__srv__ExCustomSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__ros2_interface__srv__ExCustomSrv_Request __declspec(deprecated)
#endif

namespace ros2_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ExCustomSrv_Request_
{
  using Type = ExCustomSrv_Request_<ContainerAllocator>;

  explicit ExCustomSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->a = 0ll;
      this->b = 0ll;
    }
  }

  explicit ExCustomSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->a = 0ll;
      this->b = 0ll;
    }
  }

  // field types and members
  using _a_type =
    int64_t;
  _a_type a;
  using _b_type =
    int64_t;
  _b_type b;

  // setters for named parameter idiom
  Type & set__a(
    const int64_t & _arg)
  {
    this->a = _arg;
    return *this;
  }
  Type & set__b(
    const int64_t & _arg)
  {
    this->b = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_interface::srv::ExCustomSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_interface::srv::ExCustomSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_interface::srv::ExCustomSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_interface::srv::ExCustomSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_interface::srv::ExCustomSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_interface::srv::ExCustomSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_interface::srv::ExCustomSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_interface::srv::ExCustomSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_interface::srv::ExCustomSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_interface::srv::ExCustomSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_interface__srv__ExCustomSrv_Request
    std::shared_ptr<ros2_interface::srv::ExCustomSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_interface__srv__ExCustomSrv_Request
    std::shared_ptr<ros2_interface::srv::ExCustomSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExCustomSrv_Request_ & other) const
  {
    if (this->a != other.a) {
      return false;
    }
    if (this->b != other.b) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExCustomSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExCustomSrv_Request_

// alias to use template instance with default allocator
using ExCustomSrv_Request =
  ros2_interface::srv::ExCustomSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros2_interface


#ifndef _WIN32
# define DEPRECATED__ros2_interface__srv__ExCustomSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__ros2_interface__srv__ExCustomSrv_Response __declspec(deprecated)
#endif

namespace ros2_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ExCustomSrv_Response_
{
  using Type = ExCustomSrv_Response_<ContainerAllocator>;

  explicit ExCustomSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sum = 0ll;
    }
  }

  explicit ExCustomSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sum = 0ll;
    }
  }

  // field types and members
  using _sum_type =
    int64_t;
  _sum_type sum;

  // setters for named parameter idiom
  Type & set__sum(
    const int64_t & _arg)
  {
    this->sum = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_interface::srv::ExCustomSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_interface::srv::ExCustomSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_interface::srv::ExCustomSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_interface::srv::ExCustomSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_interface::srv::ExCustomSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_interface::srv::ExCustomSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_interface::srv::ExCustomSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_interface::srv::ExCustomSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_interface::srv::ExCustomSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_interface::srv::ExCustomSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_interface__srv__ExCustomSrv_Response
    std::shared_ptr<ros2_interface::srv::ExCustomSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_interface__srv__ExCustomSrv_Response
    std::shared_ptr<ros2_interface::srv::ExCustomSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExCustomSrv_Response_ & other) const
  {
    if (this->sum != other.sum) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExCustomSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExCustomSrv_Response_

// alias to use template instance with default allocator
using ExCustomSrv_Response =
  ros2_interface::srv::ExCustomSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros2_interface

namespace ros2_interface
{

namespace srv
{

struct ExCustomSrv
{
  using Request = ros2_interface::srv::ExCustomSrv_Request;
  using Response = ros2_interface::srv::ExCustomSrv_Response;
};

}  // namespace srv

}  // namespace ros2_interface

#endif  // ROS2_INTERFACE__SRV__DETAIL__EX_CUSTOM_SRV__STRUCT_HPP_
