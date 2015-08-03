#include <ros/ros.h>
#include "geometry_msgs/Twist.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "publish_base_link_goal") ;

  // Set up publisher
  ros::NodeHandle nHandle ;
  ros::Publisher pub = nHandle.advertise<geometry_msgs::Twist>("base_link_goal", 50) ;
  
  geometry_msgs::Twist goal ;
  
  double temp = 0;
  ros::param::get("/simple_navigation_goals/position/x", temp);
  goal.linear.x = temp;
  ros::param::get("/simple_navigation_goals/position/y", temp);
  goal.linear.y = temp;
  ros::param::get("/simple_navigation_goals/position/z", temp);
  goal.linear.z = temp;
  ros::param::get("/simple_navigation_goals/orientation/phi", temp);
  goal.angular.x = temp;
  ros::param::get("/simple_navigation_goals/orientation/theta", temp);
  goal.angular.y = temp;
  ros::param::get("/simple_navigation_goals/orientation/psi", temp);
  goal.angular.z = temp;
  
  // Publish the message
  pub.publish(goal);

  ros::spin();
  return 0;
}
