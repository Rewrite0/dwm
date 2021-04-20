#!/bin/bash
#########################################################################
# File Name: light-up.sh
# Created Time: 2020年06月17日 星期三 20时53分39秒
#########################################################################
xbacklight -inc 10
dunstify "当前亮度: `xbacklight -get`%" -h int:value:"`xbacklight -get`"
