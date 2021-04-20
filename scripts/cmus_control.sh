#!/bin/bash
#########################################################################
# File Name: cmus_control.sh
# Created Time: 2020年04月10日 星期五 19时07分04秒
#########################################################################
play() {
	tmux new -s cmus -d
	tmux send-keys -t cmus "cmus" C-m
	sleep 1s
	cmus-remote --play
	pkill xss-lock
}

quit() {
	tmux send-keys -t cmus "cqy"
	tmux kill-session -t cmus
	setsid xss-lock slock
}

if [ $1 == "play" ];then
	play
elif [ $1 == "quit" ];then
	quit
else
	echo "指令错误!"
fi
