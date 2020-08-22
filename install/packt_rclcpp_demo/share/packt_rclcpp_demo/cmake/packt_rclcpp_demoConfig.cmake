# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_packt_rclcpp_demo_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED packt_rclcpp_demo_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(packt_rclcpp_demo_FOUND FALSE)
  elseif(NOT packt_rclcpp_demo_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(packt_rclcpp_demo_FOUND FALSE)
  endif()
  return()
endif()
set(_packt_rclcpp_demo_CONFIG_INCLUDED TRUE)

# output package information
if(NOT packt_rclcpp_demo_FIND_QUIETLY)
  message(STATUS "Found packt_rclcpp_demo: 0.0.0 (${packt_rclcpp_demo_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'packt_rclcpp_demo' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${packt_rclcpp_demo_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(packt_rclcpp_demo_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${packt_rclcpp_demo_DIR}/${_extra}")
endforeach()
