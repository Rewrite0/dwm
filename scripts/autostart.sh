#!/bin/bash

mkdir /tmp/log

$DWMHOME/dwmBar/dwm_bar.sh &
$DWMHOME/show-display.sh
#$DWMHOME/only-hdmi.sh
$DWMHOME/bg-autochange.sh &
$DWMHOME/prog.sh
$DWMHOME/mount-list.sh
