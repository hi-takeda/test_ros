#include <ros/ros.h>
#include <std_msgs/Header.h>

int main (int argc, char** argv)
{
  ros::init(argc, argv, "spin_once");
  ros::NodeHandle nh;
  
  ros::Publisher pub;
  pub = nh.advertise<std_msgs::Header>("/header", 1);
  
  ros::Rate rate(100);
  int count = 0;

  while(ros::ok())
    {
      std_msgs::Header header;
      header.seq = count++;
      header.stamp = ros::Time::now();
      
      pub.publish(header);
      ROS_INFO("pub.publish(): %d %f", header.seq,
               ros::Time::now().toSec() - header.stamp.toSec());
      
      ros::spinOnce();
      rate.sleep();
    }

  return 0;
}
