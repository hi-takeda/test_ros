#include <ros/ros.h>
#include <std_msgs/Header.h>

void cb(const std_msgs::Header& msg)
{
  ROS_INFO("callback:      %d %f", msg.seq,
           ros::Time::now().toSec() - msg.stamp.toSec());
}

int main (int argc, char** argv)
{
  ros::init(argc, argv, "spin_once");
  ros::NodeHandle nh;

  ros::Subscriber sub;
  sub = nh.subscribe("/header", 1, cb);

  ros::Rate rate(1);

  while(ros::ok())
    {
      ros::spinOnce();
      rate.sleep();
    }

  return 0;
}
