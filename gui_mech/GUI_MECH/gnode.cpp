#include <ros/ros.h>
#include <std_msgs/String.h>
#include "gnode.hpp"
#include <string>

namespace nav_ui {

QNode::QNode(int argc, char** argv ) :
  init_argc(argc),
  init_argv(argv)
  {}

QNode::~QNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
  wait();
}

bool QNode::init() {
  ros::init(init_argc,init_argv,"qt5_ros_melodic_gui");
  if ( ! ros::master::check() ) {
    return false;
  }
  ros::start(); // explicitly needed since our nodehandle is going out of scope.
  ros::NodeHandle nh;
  pub = nh.advertise<order_msgs::order>("delivery", 1);

  start(); //start a Qthread, which calls run()
  return true;
}

void QNode::run() {

  ros::Rate loop_rate(1); //too fast loop rate crashes the GUI
  while ( ros::ok() ) {

    ros::spinOnce();
    loop_rate.sleep();
  }

  Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

}  // namespace nav_ui
