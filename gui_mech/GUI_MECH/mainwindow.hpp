#ifndef NAV_UI_MAINWINDOW_H
#define NAV_UI_MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "gnode.hpp"

namespace nav_ui {

//Qt central, all operations relating to the view part here.

class MainWindow : public QMainWindow {
Q_OBJECT

public:
  MainWindow(int argc, char** argv, QWidget *parent = 0);
  ~MainWindow();

  void closeEvent(QCloseEvent *event); // Overloaded function

public Q_SLOTS:

    void on_actionQuit_triggered();

    void pushplug();

    void pushming();

    void pushplur();

    void pushminr();

    void pushpluy();

    void pushminy();

    void pushplub();

    void pushminb();

    void chatter();

private:
  Ui::MainWindowDesign ui; //can pick any element in our .ui file with this
  QNode qnode; //create ROS node
};

}  // namespace nav_ui

#endif // NAV_UI_MAINWINDOW_H
