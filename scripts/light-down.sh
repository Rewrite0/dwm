#!/bin/bash
#########################################################################
# File Name: light-down.sh
# Created Time: 2020年06月17日 星期三 20时52分57秒
#########################################################################
xbacklight -dec 10
dunstify "当前亮度: `xbacklight -get`%" -h int:value:"`xbacklight -get`"
