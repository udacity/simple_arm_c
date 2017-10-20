#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <math.h>

int main(int argc, char **argv)
{
	
  
  ros::init(argc, argv, "simple_mover");

  ros::NodeHandle n1,n2;
  
  ros::Publisher joint1_pub = n1.advertise<std_msgs::Float64>("/simple_arm_c/joint_1_position_controller/command", 10);
  ros::Publisher joint2_pub = n2.advertise<std_msgs::Float64>("/simple_arm_c/joint_2_position_controller/command", 10);

  ros::Rate loop_rate(10);
  
  int start_time, elapsed;
  
  while(not start_time)
  {
  	start_time = ros::Time::now().toSec();
  }
  
  
  while (ros::ok())	
  {
    
    elapsed = ros::Time::now().toSec() - start_time;
    
    std_msgs::Float64 joint1_angle, joint2_angle;
    joint1_angle.data=sin(2*M_PI*0.1*elapsed)*(M_PI/2);
    joint2_angle.data=sin(2*M_PI*0.1*elapsed)*(M_PI/2);

	joint1_pub.publish(joint1_angle);
	joint2_pub.publish(joint2_angle);
	
	loop_rate.sleep();
 
  }

  return 0;
}
