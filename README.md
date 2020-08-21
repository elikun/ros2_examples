https://github.com/eborghi10/ros2_examples

ros2 topic list
ros2 pkg create packt_rclcpp_demo
ros2 topic echo topic

// In colcon_ws directory,
colcon build --event-handlers console_direct+
source install/setup.bash
ros2 run packt_rclpy_demo listener
ros2 run packt_rclpy_demo talker

// In colcon_ws directory,
colcon build --event-handlers console_direct+
source install/setup.bash
ros2 run packt_rclcpp_demo listener
ros2 run packt_rclcpp_demo talker

http://docs.ros2.org/latest/api/rclpy/index.html
http://docs.ros2.org/latest/api/rclcpp/index.html

https://index.ros.org/doc/ros2/Releases/Release-Dashing-Diademata/#rclcpp
https://index.ros.org/doc/ros2/Releases/Release-Dashing-Diademata/#changes-to-creating-publishers-and-subscriptions

https://index.ros.org/doc/ros2/Releases/Release-Dashing-Diademata/#rclpy
https://index.ros.org/doc/ros2/Releases/Release-Dashing-Diademata/#changes-to-creating-publishers-subscriptions-and-qos-profiles

