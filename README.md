# ros2_examples

- Forked from https://github.com/eborghi10/ros2_examples
- Examples using ROS 2 for the Packt video course "ROS 2 - New Features" by Emiliano Javier Borghi Orué.
- Updated to support ROS 2 Foxy Fitzroy.
    - Major updates starting from ROS 2 Dashing Diademata:
        - https://index.ros.org/doc/ros2/Releases/Release-Dashing-Diademata/#changes-to-creating-publishers-and-subscriptions
        - https://index.ros.org/doc/ros2/Releases/Release-Dashing-Diademata/#changes-to-creating-publishers-subscriptions-and-qos-profiles
- Course Link: https://learning.oreilly.com/videos/ros-2-new/9781838552893 (requires O'Reilly account). Highly recommended course!

![cover](./docs/cover.jpg)

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
C:\> docker run -it --rm -v /c/ros2_examples:/colcon_ws ros
```

3. Open up another bash terminal when needed to start another ROS 2 node.
```console
C:\> docker exec -it <container-identifier> bash
```

# C++

- http://docs.ros2.org/latest/api/rclcpp/index.html
- https://index.ros.org/doc/ros2/Releases/Release-Dashing-Diademata/#rclcpp
- http://wiki.ros.org/CppStyleGuide

1. Compile with ROS 2's colcon build tool
```bash
root@123456abcdef:/colcon_ws# colcon build --event-handlers console_direct+ |& tee colcon_build.log
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
- http://wiki.ros.org/PyStyleGuide

1. Compile with ROS 2's colcon build tool
```bash
root@123456abcdef:/colcon_ws# colcon build --event-handlers console_direct+ |& tee colcon_build.log
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

# Other useful commands

- List existing ROS 2 nodes
```bash
root@123456abcdef:/colcon_ws# ros2 node list
```

- Get more info on '/publisher' node
```bash
root@123456abcdef:/colcon_ws# ros2 node info /publisher
```

- List existing ROS 2 topics
```bash
root@123456abcdef:/colcon_ws# ros2 topic list
```

- "Peek" into the contents of the '/chatter' topic
```bash
root@123456abcdef:/colcon_ws# ros2 topic echo chatter
```

- Publish a ROS 2 topic called '/estop' manually
```bash
root@123456abcdef:/colcon_ws# ros2 topic pub /estop std_msgs/String "data: Stop"
```

- Initialize a C++ ROS 2 Package named packt_rclcpp_demo
```bash
root@123456abcdef:/colcon_ws# ros2 pkg create packt_rclcpp_demo
```

- Execute launch file called composition_demo.launch.py file in composition
```bash
root@123456abcdef:/colcon_ws# ros2 launch composition demo.launch.py
```

- Clean up colcon build artifacts
```bash
root@123456abcdef:/colcon_ws# rm -rf build install log colcon_build.log
```

---

# Other useful links

- https://github.com/ros2/demos
- https://github.com/ros2/examples
- https://index.ros.org/doc/ros2/Tutorials/
- https://index.ros.org/doc/ros2/Tutorials/Composition/
- https://index.ros.org/doc/ros2/Tutorials/Launch-system/