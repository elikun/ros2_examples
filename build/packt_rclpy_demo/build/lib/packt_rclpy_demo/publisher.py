import rclpy

from rclpy.node import Node
from rclpy.qos import QoSHistoryPolicy, QoSProfile
from std_msgs.msg import String

# Inherit from Node base class
class Publisher(Node):
    def __init__(self):
        # Assign name of this Node to 'talker'
        super().__init__('talker')
        self.i = 0

        # Configure QoS profile
        qos_profile = QoSProfile(history=QoSHistoryPolicy.RMW_QOS_POLICY_HISTORY_KEEP_LAST, depth=10)

        # Configure this Node to publish String data to '/chatter' topic
        self.publisher = self.create_publisher(String, 'chatter', qos_profile)

        # Create 1-second periodic timer
        self.time = self.create_timer(1.0, self.timer_callback)

    def timer_callback(self):
        msg = String()
        msg.data = "Hello World: {0}".format(self.i)
        self.i += 1
        self.get_logger().info('Publishing "{0}"'.format(msg.data))
        self.publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)

    try:
        publisher = Publisher()
        rclpy.spin(publisher)
    finally:
        publisher.destroy_node()
        rclpy.shutdown()

if __name__ == 'main':
    main()