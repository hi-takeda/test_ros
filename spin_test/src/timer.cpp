#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <std_msgs/String.h>

ros::Publisher pub; // グローバルで宣言

void timer_cb(const ros::TimerEvent&) // 処理はcbで記述
{
  std_msgs::String str;
  str.data = "hello, world!";
  pub.publish(str);
}

void cb(const std_msgs::Header& msg)
{
  ROS_INFO("callback:      %d %f", msg.seq,
           ros::Time::now().toSec() - msg.stamp.toSec());
}

int main (int argc, char** argv)
{
  ros::init(argc, argv, "spin");
  ros::NodeHandle nh;

  pub = nh.advertise<std_msgs::String>("chatter", 1); // main()で実体化

  ros::Subscriber sub;
  sub = nh.subscribe("/header", 1, cb);

  ros::Timer timer = nh.createTimer(ros::Duration(0.5), timer_cb); // cbに引数を渡すのが面倒
  ros::spin();

  return 0;
}
