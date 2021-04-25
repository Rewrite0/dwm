#!/bin/bash
#########################################################################
# File Name: live-wallpaper-console.sh
# Created Time: 2020年08月15日 星期六 20时30分10秒
#########################################################################
command=$1

pause(){
	echo 'pause' > /tmp/wallpaper
}
next(){
	echo 'pt_step down' > /tmp/wallpaper
}
quit(){
	killall xwinwrap
}
volup(){
	echo 'volume +10%' > /tmp/wallpaper
}
voldown(){
	echo 'volume -10%' > /tmp/wallpaper
}
voloff(){
	echo 'volume 0 1' > /tmp/wallpaper
}
helpme(){
	echo 'puase - 暂停'
	echo 'next  - 下一个'
	echo 'vup   - 音量加'
	echo 'vdown - 音量减'
	echo 'voff  - 静音'
	echo 'quit  - 退出'
}

if [ $command == puase ];then
	pause
elif [ $command == next ];then
	next
elif [ $command == quit ];then
	quit
elif [ $command == vup ];then
	volup	
elif [ $command == vdown ];then
	voldown
elif [ $command == voff ];then
	voloff
elif [ $command == help ];then
	helpme
fi
