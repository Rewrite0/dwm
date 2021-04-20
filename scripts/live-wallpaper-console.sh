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
	killall xwinwarp
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
echo $1 > /tmp/wallpaper

if [ $command == puase ];then
	pause
elif [ $command == next ];then
	next
elif [ $command == quit ];then
	quit
elif [ $command == volup ];then
	volup	
elif [ $command == voldown ];then
	voldown
elif [ $command == voloff ];then
	voloff
fi
