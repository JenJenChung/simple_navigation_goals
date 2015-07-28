#include <ros/ros.h>
#include "geometry_msgs/Pose.h"
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

void goalCallback(const geometry_msgs::Pose& msg)
{
  //tell the action client that we want to spin a thread by default
  actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> ac("move_base",true) ;
  
  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }
  
  move_base_msgs::MoveBaseGoal goal ;
  
  goal.target_pose.header.frame_id = "base_link" ;
  goal.target_pose.header.stamp = ros::Time::now() ;

  goal.target_pose.pose.position.x = msg.position.x ;
  goal.target_pose.pose.position.y = msg.position.y ;
  goal.target_pose.pose.position.z = msg.position.z ;
  goal.target_pose.pose.orientation.x = msg.orientation.x ;
  goal.target_pose.pose.orientation.y = msg.orientation.y ;
  goal.target_pose.pose.orientation.z = msg.orientation.z ;
  goal.target_pose.pose.orientation.w = msg.orientation.w ;
  
  ROS_INFO("Sending goal") ;
  ac.sendGoal(goal) ;

  ac.waitForResult() ;

  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Waypoint reached.") ;
  else
    ROS_INFO("The base failed to reach the waypoint.") ;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "base_link_navigation_client") ;

  ros::NodeHandle nHandle ;
  
  ros::Subscriber sub = nHandle.subscribe("base_link_goal", 10, goalCallback);

  ros::spin();
  return 0;
}
