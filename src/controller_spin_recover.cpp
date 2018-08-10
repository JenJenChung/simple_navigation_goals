#include <ros/ros.h>
#include "controller_spin_recover.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "controller_spin_recover") ;

  ros::NodeHandle nHandle ;
  
  MoveBaseRecover recover(nHandle) ;
  
  ros::spin();
  return 0;
}
