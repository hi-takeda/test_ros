#include <ros/ros.h>
#include <std_msgs/Header.h>

void cb(const std_msgs::Header& msg)
{
  ROS_INFO("callback:      %d %f", msg.seq,
           ros::Time::now().toSec() - msg.stamp.toSec());
}

int main (int argc, char** argv)
{
  ros::init(argc, argv, "spin");
  ros::NodeHandle nh;

  ros::Subscriber sub;
  sub = nh.subscribe("/header", 1, cb);

  ros::spin();

  return 0;
}
