mkfifo /tmp/wallpaper
STA=`xrandr | grep 1366x768+1920+0`
one(){
# 单屏
nohup xwinwrap -fs -nf -ov -- mplayer -af volume=-200 -softvol -softvol-max 200 -slave -quiet -input file=/tmp/wallpaper -loop 0 -wid WID -nolirc `find ~/Videos/live_wallpaper -type f` > /tmp/log/xwinwrap.log 2>&1 &
}

two(){
# 双屏
# left
nohup xwinwrap -g 1920x1080 -ni -s -st -sp -b -nf -ov -- mplayer -af volume=-200 -softvol -softvol-max 200 -slave -quiet -input file=/tmp/wallpaper -loop 0 -wid WID -nolirc `find ~/Videos/live_wallpaper -type f` > /tmp/log/xwinwrap_left.log 2>&1 &
# right
nohup xwinwrap -g 1366x768+1920+0 -ni -s -st -sp -b -nf -ov -- mplayer -af volume=-200 -softvol -softvol-max 200 -slave -quiet -input file=/tmp/wallpaper -loop 0 -wid WID -nolirc `find ~/Videos/live_wallpaper -type f` > /tmp/log/xwinwrap_right.log 2>&1 &
}

if [ -z "$STA" ];then
	one
else
	two
fi
