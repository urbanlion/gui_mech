#include <QtWidgets> //includes all of Qt's GUI classes
#include <QMessageBox> //for information, about etc.
#include <iostream>
#include "mainwindow.hpp"

namespace nav_ui {

using namespace Qt;

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
  : QMainWindow(parent)
  , qnode(argc,argv)
{
  qnode.init(); //initializes ROS node and starts QThread with spin
  ui.setupUi(this); //initializing ui, calling this incidentally connects all ui's triggers to on_...() callbacks in this class.

  QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

  //State:
  QObject::connect(&qnode, SIGNAL(stateUpdated()), this, SLOT(updateStateView()));

  // Logging:
  QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));

  QObject::connect(ui.push_mr, SIGNAL(clicked()), this, SLOT(pushminr()));
  QObject::connect(ui.push_pr, SIGNAL(clicked()), this, SLOT(pushplur()));
  QObject::connect(ui.push_mb, SIGNAL(clicked()), this, SLOT(pushminb()));
  QObject::connect(ui.push_pb, SIGNAL(clicked()), this, SLOT(pushplub()));
  QObject::connect(ui.push_my, SIGNAL(clicked()), this, SLOT(pushminy()));
  QObject::connect(ui.push_py, SIGNAL(clicked()), this, SLOT(pushpluy()));
  QObject::connect(ui.push_mg, SIGNAL(clicked()), this, SLOT(pushming()));
  QObject::connect(ui.push_pg, SIGNAL(clicked()), this, SLOT(pushplug()));
  QObject::connect(ui.call_pub, SIGNAL(clicked()), this, SLOT(chatter()));
}

MainWindow::~MainWindow() {}

// slot implementation
void MainWindow::pushminr()
{
    qnode.ord.ROT--;
    ui.lcdNumber_red->display(qnode.ord.ROT);
}

void MainWindow::pushplur()
{
    qnode.ord.ROT++;
    ui.lcdNumber_red->display(qnode.ord.ROT);

}

void MainWindow::pushminb()
{
    qnode.ord.BRAUN--;
    ui.lcdNumber_blue->display(qnode.ord.BRAUN);

}

void MainWindow::pushplub()
{
    qnode.ord.BRAUN++;
    ui.lcdNumber_blue->display(qnode.ord.BRAUN);
}

void MainWindow::pushminy()
{
    qnode.ord.GELB--;
    ui.lcdNumber_yel->display(qnode.ord.GELB);
}

void MainWindow::pushpluy()
{
    qnode.ord.GELB++;
    ui.lcdNumber_yel->display(qnode.ord.GELB);
}

void MainWindow::pushming()
{
    qnode.ord.GRUEN--;
    ui.lcdNumber_green->display(qnode.ord.GRUEN);
}

void MainWindow::pushplug()
{
    qnode.ord.GRUEN++;
    ui.lcdNumber_green->display(qnode.ord.GRUEN);
}

void MainWindow::chatter(){
    qnode.pub.publish(qnode.ord);
    qnode.listoforder.push_back(qnode.ord);
}

// menu implementation

void MainWindow::on_actionQuit_triggered()
{
  QApplication::quit();
}

//void MainWindow::updateStateView() {
//  ui.q_actual_x->display(qnode.x_value);

//}


void MainWindow::closeEvent(QCloseEvent *event)
{
  QMainWindow::closeEvent(event);
}

}  // namespace nav_ui




