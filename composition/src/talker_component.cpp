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

#include "composition/talker_component.hpp"

#include <chrono>
#include <iostream>
#include <memory>
#include <utility>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

namespace composition
{

// Create a Talker "component" that subclasses the generic rclcpp::Node base class.
// Components get built into shared libraries and as such do not write their own main functions.
// The process using the component's shared library will instantiate the class as a ROS node.
Talker::Talker(rclcpp::NodeOptions options)
: Node("talker", options), count_(0)
{
  // Configure QoS settings
  rmw_qos_history_policy_t history_policy_arg = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  size_t depth_arg = 10;
  rclcpp::QoS qos(rclcpp::QoSInitialization(history_policy_arg, depth_arg));

  // Create a publisher of "std_mgs/String" messages on the "chatter" topic.
  pub_ = create_publisher<std_msgs::msg::String>("chatter", qos);

  // Use a timer to schedule periodic message publishing.
  timer_ = create_wall_timer(1s, std::bind(&Talker::on_timer, this));
}

void Talker::on_timer()
{
  auto msg = std_msgs::msg::String();
  msg.data = "Hello World: " + std::to_string(++count_);
  RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg.data.c_str());
  std::flush(std::cout);

  // Put the message into a queue to be processed by the middleware.
  // This call is non-blocking.
  pub_->publish(msg);
}

}  // namespace composition

#include "rclcpp_components/register_node_macro.hpp"
// #include "class_loader/register_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(composition::Talker)
// CLASS_LOADER_REGISTER_CLASS(composition::Talker, rclcpp::Node)
