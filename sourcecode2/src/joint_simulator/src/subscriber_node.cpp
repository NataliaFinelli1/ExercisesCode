#include "ros/ros.h"
#include "joint_msgs/joint_msg.h"
#include "joint_msgs/joint_array.h"
#include <iostream>

void receiverCallback(const joint_msgs::joint_array::ConstPtr& msg){
    ROS_INFO("Ricevuto ");
    
    for(int i=0; i<((*msg).joint_array).size(); i++){ 
            
            std::cout << "joint: " << (*msg).joint_array[i].label << "\nAngle: " << (*msg).joint_array[i].angle << "\nElongation: " << (*msg).joint_array[i].elongation << "\n\n"; 
    }

}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "joint_subscriber");
    ROS_INFO("Joint subscriber started");

    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("position", 1, receiverCallback);

    ros::spin();

    return 0;

}
