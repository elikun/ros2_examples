// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "composition/listener_component.hpp"

#include <iostream>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace composition
{

// Create a Listener "component" that subclasses the generic rclcpp::Node base class.
// Components get built into shared libraries and as such do not write their own main functions.
// The process using the component's shared library will instantiate the class as a ROS node.
Listener::Listener(rclcpp::NodeOptions options)
: Node("listener", options)
{
  // Create a callback function for when messages are received.
  // Variations of this function also exist using, for example, UniquePtr for zero-copy transport.
  auto callback =
    [this](const typename std_msgs::msg::String::SharedPtr msg) -> void
    {
      RCLCPP_INFO(this->get_logger(), "I heard: [%s]", msg->data.c_str());
      std::flush(std::cout);
    };

  // Configure QoS settings
  rmw_qos_history_policy_t history_policy_arg = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  size_t depth_arg = 10;
  rclcpp::QoS qos(rclcpp::QoSInitialization(history_policy_arg, depth_arg));

  // Create a subscription to the "chatter" topic which can be matched with one or more
  // compatible ROS publishers.
  // Note that not all publishers on the same topic with the same type will be compatible:
  // they must have compatible Quality of Service policies.
  sub_ = this->create_subscription<std_msgs::msg::String>("chatter", qos, callback);
}

}  // namespace composition

#include "rclcpp_components/register_node_macro.hpp"
// #include "class_loader/register_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(composition::Listener)
// CLASS_LOADER_REGISTER_CLASS(composition::Listener, rclcpp::Node)
