// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_interface:srv/ExCustomSrv.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACE__SRV__DETAIL__EX_CUSTOM_SRV__STRUCT_H_
#define ROS2_INTERFACE__SRV__DETAIL__EX_CUSTOM_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ExCustomSrv in the package ros2_interface.
typedef struct ros2_interface__srv__ExCustomSrv_Request
{
  int64_t a;
  int64_t b;
} ros2_interface__srv__ExCustomSrv_Request;

// Struct for a sequence of ros2_interface__srv__ExCustomSrv_Request.
typedef struct ros2_interface__srv__ExCustomSrv_Request__Sequence
{
  ros2_interface__srv__ExCustomSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_interface__srv__ExCustomSrv_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/ExCustomSrv in the package ros2_interface.
typedef struct ros2_interface__srv__ExCustomSrv_Response
{
  int64_t sum;
} ros2_interface__srv__ExCustomSrv_Response;

// Struct for a sequence of ros2_interface__srv__ExCustomSrv_Response.
typedef struct ros2_interface__srv__ExCustomSrv_Response__Sequence
{
  ros2_interface__srv__ExCustomSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_interface__srv__ExCustomSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_INTERFACE__SRV__DETAIL__EX_CUSTOM_SRV__STRUCT_H_
