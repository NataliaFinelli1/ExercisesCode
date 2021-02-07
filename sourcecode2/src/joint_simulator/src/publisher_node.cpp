#include "ros/ros.h"
#include "joint_msgs/joint_msg.h"
#include "joint_msgs/joint_array.h"
#include <stdlib.h> 


int main(int argc, char **argv)
{

    ros::init(argc, argv, "joint_publisher");
    ROS_INFO("Joint publisher started");

    ros::NodeHandle nh;
    ros::Publisher pub =  nh.advertise<joint_msgs::joint_array>("position", 1000);

    ros::Rate loop_rate(10);

    ::joint_msgs::joint_msg joint;
    ::joint_msgs::joint_array joint_array;
    
   while (ros::ok() ){
	for (int i=0; i<6; i++){
		joint.label = "joint " + std::to_string(i+1);
		joint.angle = rand() % 361;
		joint.elongation = rand() % 10+1;

		joint_array.joint_array.push_back(joint);
	}
    pub.publish(joint_array);
    ROS_INFO("Published new message!");
    ros::spinOnce();
    loop_rate.sleep();

    }
    return 0;
}
