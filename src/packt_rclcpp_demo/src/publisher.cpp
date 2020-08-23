#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

// Inherit from Node base class
class Publisher : public rclcpp::Node
{
    public:
        Publisher() : Node("publisher"), count(0) {
            // Configure QoS settings
            rmw_qos_history_policy_t history_policy_arg = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
            size_t depth_arg = 10;
            rclcpp::QoS qos(rclcpp::QoSInitialization(history_policy_arg, depth_arg));

            // Configure this Node to publish String data to '/chatter' topic
            publisher = this->create_publisher<std_msgs::msg::String>("chatter", qos);

            // Create Timer
            timer = this->create_wall_timer(500ms, std::bind(&Publisher::timer_callback, this));
        }

    private:
        void timer_callback() {
            // Fill the message data
            std_msgs::msg::String message = std_msgs::msg::String();
            message.data = "Hello world! " + std::to_string(count++);

            // Log the sent message
            RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());

            // Publish the message in the /chatter
            publisher->publish(message);
        }

        rclcpp::TimerBase::SharedPtr timer;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher;
        size_t count;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Publisher>());
    rclcpp::shutdown();

    return 0;
}