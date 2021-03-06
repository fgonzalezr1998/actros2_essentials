// Copyright 2020 Intelligent Robotics Lab
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

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

rclcpp::Node::SharedPtr node = nullptr;

void callback(const std_msgs::msg::String::SharedPtr msg)
{
  RCLCPP_INFO(node->get_logger(), "I heard: [%s]", msg->data.c_str());
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  node = rclcpp::Node::make_shared("simple_node_sub");
  auto subscription = node->create_subscription<std_msgs::msg::String>(
    "chatter", rclcpp::QoS(100).transient_local(), callback);
  
  rclcpp::spin(node);

  rclcpp::shutdown();

  return 0;
}