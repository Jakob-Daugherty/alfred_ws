//talker.cpp 
#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"


int main(int argc, char **argv) 
{
	ros::init(argc,argv,"talker");
	ros::start();
	ROS_INFO_STREAM("Talker Start");
	ros::NodeHandle chat;
	ros::Publisher chatter_pub = chat.advertise<std_msgs::String>("chatter", 1000);
	ros::Rate loop_rate(1);
	int count = 0;
	loop_rate.sleep();
	while(ros::ok()){
		std_msgs::String msg;
		std::stringstream ss;
		ss << "hello world" << count;
		msg.data = ss.str();
		ROS_INFO("I said -> [%s]", msg.data.c_str());
		sleep(1);
		chatter_pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
		count++;
	}
	ros::shutdown();
	return 0;

}
