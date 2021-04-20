#!/bin/bash
#########################################################################
# File Name: show-display.sh
# Created Time: 2020年05月23日 星期六 18时05分39秒
#########################################################################
xrandr --output HDMI-1 --auto --primary --output LVDS-1 --right-of HDMI-1 --auto
xrandr --output HDMI-1-1 --auto --primary --output LVDS-1-1 --right-of HDMI-1-1 --auto
