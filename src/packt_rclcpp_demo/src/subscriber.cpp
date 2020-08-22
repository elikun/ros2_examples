#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class Subscriber : public rclcpp::Node
{
    public:
        Subscriber() : Node("subscriber") {
            // Configure QoS settings
            rmw_qos_history_policy_t history_policy_arg = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
            size_t depth_arg = 10;
            rclcpp::QoS qos(rclcpp::QoSInitialization(history_policy_arg, depth_arg));

            // Configure this Node to subscribe and get String data from '/chatter' topic
            subscription = this->create_subscription<std_msgs::msg::String>(
                "chatter", qos, std::bind(&Subscriber::topic_callback, this, _1)
            );
        }

    private:
        void topic_callback(const std_msgs::msg::String::SharedPtr msg) {
            RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
        }

        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Subscriber>());
    rclcpp::shutdown();

    return 0;
}