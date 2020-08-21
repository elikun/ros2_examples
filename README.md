# ros2_examples

- Forked from https://github.com/eborghi10/ros2_examples
- Examples using ROS 2 for the Packt video course "ROS 2 - New Features".
- Course Link: https://learning.oreilly.com/videos/ros-2-new/9781838552893 (requires O'Reilly account). Highly recommended course!
- Updated to support ROS 2 Foxy Fitzroy.
    - Major updates starting from ROS 2 Dashing Diademata:
        - https://index.ros.org/doc/ros2/Releases/Release-Dashing-Diademata/#changes-to-creating-publishers-and-subscriptions
        - https://index.ros.org/doc/ros2/Releases/Release-Dashing-Diademata/#changes-to-creating-publishers-subscriptions-and-qos-profiles

---

# Git

1. Clone 'foxy' Git branch in C:\
```console
C:\> git clone -b foxy https://github.com/elikun/ros2_examples.git
```

# Docker

- https://hub.docker.com/_/ros
- http://wiki.ros.org/docker/Tutorials/Docker
- http://wiki.ros.org/docker

1. Pull official ROS 2 Docker image
```console
C:\> docker pull ros
```

2. Mount this repository's files to /colcon_ws/src in the Docker container
```console
C:\> docker run -it --rm -v /c/ros2_examples:/colcon_ws/src ros
```

3. Open up another bash terminal when needed to start another ROS 2 node.
```console
C:\> docker exec -it <container-identifier> bash
```

# C++

- http://docs.ros2.org/latest/api/rclcpp/index.html
- https://index.ros.org/doc/ros2/Releases/Release-Dashing-Diademata/#rclcpp

1. Compile with ROS 2's colcon build tool
```bash
root@123456abcdef:/colcon_ws# colcon build --event-handlers console_direct+
```

2. Source installed files
```bash
root@123456abcdef:/colcon_ws# source install/setup.bash
```

3. Run listener node
```bash
root@123456abcdef:/colcon_ws# ros2 run packt_rclcpp_demo listener
```

4. Run talker node (in a separate bash terminal)
```bash
root@123456abcdef:/colcon_ws# ros2 run packt_rclcpp_demo talker
```

# Python3

- http://docs.ros2.org/latest/api/rclpy/index.html
- https://index.ros.org/doc/ros2/Releases/Release-Dashing-Diademata/#rclpy

1. Compile with ROS 2's colcon build tool
```bash
root@123456abcdef:/colcon_ws# colcon build --event-handlers console_direct+
```

2. Source installed files
```bash
root@123456abcdef:/colcon_ws# source install/setup.bash
```

3. Run listener node
```bash
root@123456abcdef:/colcon_ws# ros2 run packt_rclpy_demo listener
```

4. Run talker node (in a separate bash terminal)
```bash
root@123456abcdef:/colcon_ws# ros2 run packt_rclpy_demo talker
```

# Useful ROS 2 Commands

- List existing ROS 2 topics
```bash
root@123456abcdef:/colcon_ws# ros2 topic list
```

- "Peek" into the contents of the '/chatter' topic
```bash
root@123456abcdef:/colcon_ws# ros2 topic echo chatter
```

- Initialize a C++ ROS 2 Package named packt_rclcpp_demo
```bash
root@123456abcdef:/colcon_ws# ros2 pkg create packt_rclcpp_demo
```

