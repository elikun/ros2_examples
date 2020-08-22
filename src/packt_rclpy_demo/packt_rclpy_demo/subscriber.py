import rclpy

from rclpy.node import Node
from rclpy.qos import QoSHistoryPolicy, QoSProfile
from std_msgs.msg import String

# Inherit from Node base class
class Subscriber(Node):
    def __init__(self):
        # Assign name of this Node to 'listener'
        super().__init__('listener')

        # Configure QoS profile
        qos_profile = QoSProfile(history=QoSHistoryPolicy.RMW_QOS_POLICY_HISTORY_KEEP_LAST, depth=10)

        # Configure this Node to subscribe and get String data from '/chatter' topic
        self.subscription = self.create_subscription(String, 'chatter', self.listener_callback, qos_profile)

    def listener_callback(self, msg):
        self.get_logger().info("I heard: {0}".format(msg.data))

def main(args=None):
    rclpy.init(args=args)

    try:
        subscriber = Subscriber()
        rclpy.spin(subscriber)
    finally:
        subscriber.destroy_node()
        rclpy.shutdown()

if __name__ == 'main':
    main()