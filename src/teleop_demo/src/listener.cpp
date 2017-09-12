//listener

# include "ros/ros.h"
# include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "nav_msgs/Odometry.h"

void chatterCallback(const std_msgs::String::ConstPtr& vel)
{
	ROS_INFO("I heard -> [%s]", vel->data.c_str());
	//ROS_INFO("I heard angular: [%f,%f]", vel->linear_velocity, vel->angular_velocity);

}

int main (int argc, char **argv)
{
ros::init(argc, argv, "listener");
ros::start();
ROS_INFO_STREAM("Listener Start");
ros::NodeHandle chat;
ros::Subscriber sub = chat.subscribe("chatter", 1000, chatterCallback);
ros::spin();
ros::shutdown();
return 0;
}
