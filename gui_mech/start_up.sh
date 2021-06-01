#!/bin/sh
source ~/.bashrc
roscore &
sleep 3
cd ~/gui_mech/build-GUI_MECH-Desktop-Debug/
./GUI_MECH
