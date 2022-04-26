//shell for navigation service
// this is compatible with dummy_robot_coordinator
// start this node before running dummy_robot_coordinator



#include <ros/ros.h>
#include <mobot_coord/MobotCoord.h> // this message type is defined in the current package
#include <geometry_msgs/PoseStamped.h>
#include <iostream>
#include <string>
using namespace std;


bool callback(mobot_coord::MobotCoordRequest& request, mobot_coord::MobotCoordResponse& response)
{
    ROS_INFO("callback activated");
    int destination_code = request.request_code;
    if (destination_code==mobot_coord::MobotCoordRequest::GO_TO_STATION_1) {
      ROS_INFO("I have been instructed to navigate to station 1"); 
      //so...insert code here to do it!
          ros::Duration(2.0).sleep();  //dummy wait time to look like robot is working
          response.response_code = mobot_coord::MobotCoordResponse::SUCCESS;
          ROS_INFO("done");
          }
    else if (destination_code==mobot_coord::MobotCoordRequest::GO_TO_STATION_2) {
      ROS_INFO("I have been instructed to navigate to station 2"); 
      //ditto 
          ros::Duration(2.0).sleep();  //dummy wait time to look like robot is working
          response.response_code = mobot_coord::MobotCoordResponse::SUCCESS;  
          ROS_INFO("done");    
      }
    else if (destination_code==mobot_coord::MobotCoordRequest::GO_HOME) {      
      ROS_INFO("I have been instructed to navigate to home"); 
      //so do it... 
          ros::Duration(2.0).sleep();  //dummy wait time to look like robot is working
          response.response_code = mobot_coord::MobotCoordResponse::SUCCESS;    
          ROS_INFO("done");  
      }
      else {
        ROS_WARN("navigation code not recognized!");
        response.response_code = mobot_coord::MobotCoordResponse::FAILURE;
      }




  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "dummy_nav_svc");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("navigation_service", callback);
  ROS_INFO("ready to accept navigation requests");
  ros::spin();

  return 0;
}


