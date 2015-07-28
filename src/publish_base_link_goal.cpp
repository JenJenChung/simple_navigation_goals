#include <ros/ros.h>
#include "geometry_msgs/Pose.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "publish_base_link_goal") ;

  // Set up publisher
  ros::NodeHandle nHandle ;
  ros::Publisher pub = nHandle.advertise<geometry_msgs::Pose>("base_link_goal", 50) ;
  
  geometry_msgs::Pose goal ;
  
  double temp = 0;
  ros::param::get("/simple_navigation_goals/position/x", temp);
  goal.position.x = temp;
  ros::param::get("/simple_navigation_goals/position/y", temp);
  goal.position.y = temp;
  ros::param::get("/simple_navigation_goals/position/z", temp);
  goal.position.z = temp;
  ros::param::get("/simple_navigation_goals/orientation/x", temp);
  goal.orientation.x = temp;
  ros::param::get("/simple_navigation_goals/orientation/y", temp);
  goal.orientation.y = temp;
  ros::param::get("/simple_navigation_goals/orientation/z", temp);
  goal.orientation.z = temp;
  ros::param::get("/simple_navigation_goals/orientation/w", temp);
  goal.orientation.w = temp;
  
  // Publish the message
  pub.publish(goal);

  ros::spin();
  return 0;
}
