#ifndef NAV_UI_QNODE_HPP_
#define NAV_UI_QNODE_HPP_

#ifndef Q_MOC_RUN
#include <ros/ros.h>
#include "order.h"
#include <std_srvs/Trigger.h>
#include <rosgraph_msgs/Log.h>
#endif
#include <string>
#include "order.h"
#include <QThread>
#include <QStringListModel>

namespace nav_ui {


class QNode : public QThread {
    Q_OBJECT
public:

  order_msgs::order ord;
  std::vector<order_msgs::order> listoforder;
  ros::Publisher pub;

  QNode(int argc, char** argv );
  virtual ~QNode();
  bool init();
  void run();

Q_SIGNALS:
    void rosShutdown();
    void loggingUpdated();
    void stateUpdated();

private:
  int init_argc;
  char** init_argv;
  // Logging:
};

}

#endif
