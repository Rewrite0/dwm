mkfifo /tmp/wallpaper
nohup xwinwrap -fs -nf -ov -- mplayer -af volume=-200 -softvol -softvol-max 200 -slave -quiet -input file=/tmp/wallpaper -loop 0 -wid WID -nolirc `find ~/Videos/live_wallpaper -type f` > /tmp/log/xwinwrap.log 2>&1 &
