#!/usr/bin/env python3
import getch
import rclpy
from rclpy.node import Node
from std_msgs.msg import String

#This program is used to publish keyboard arrow keys to a ros node that sends signals to the arduino 

class TeleopKeyboardNode(Node):
    def __init__(self):
        super().__init__("teleop_keyboard")
        self.keyboard_publisher_ = self.create_publisher(String,"serial_transmitter", 5)
        self.timer_ = self.create_timer(0.1,self.callback_keyboard_cmd)

    def callback_keyboard_cmd(self):
        msg = String()
        k=ord(getch.getch())
        if ((k>=65)&(k<=68)|(k==115)|(k==113)|(k==97)|(k==10)):
            
            if k==65:
                msg.data = 'f'
                self.keyboard_publisher_.publish(msg)
            elif k==66:
                msg.data = 'b'
                self.keyboard_publisher_.publish(msg)
            elif k==67:
                msg.data = 'r'
                self.keyboard_publisher_.publish(msg)
            elif k==68:
                msg.data = 'l'
                self.keyboard_publisher_.publish(msg)
            elif k==10:
                msg.data = 's'
                self.keyboard_publisher_.publish(msg)
            


    

   
def main(args=None):
    rclpy.init(args=args)
    node = TeleopKeyboardNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
