#! /bin/bash
: <<!
  设置屏幕分辨率的脚本(xrandr命令的封装)
  one: 只展示一个内置屏幕 2560x1600 缩放为 1440x900
  two: 左边展示外接屏幕 - 右边展示内置屏幕 都用匹配1080p屏幕DPI的缩放比
  check: 检测显示器连接状态是否变化 变化则自动调整输出情况
!

# 定义主屏幕接口和外接屏幕接口
# INNER_PORT=none
MAIN_PORT=DisplayPort-0
OUTPORT1=HDMI-A-1
OUTPORT2=none

two() {
	# 查找已连接、未连接的外接接口
	OUTPORT_CONNECTED=$(xrandr | grep -v $MAIN_PORT | grep -w 'connected' | awk '{print $1}')
	OUTPORT_DISCONNECTED=$(xrandr | grep -v $MAIN_PORT | grep -w 'disconnected' | awk '{print $1}')
	[ ! "$OUTPORT_CONNECTED" ] && one && return # 如果没有外接屏幕则直接调用one函数
	xrandr --output $MAIN_PORT --auto --primary \
		--output $OUTPORT_CONNECTED --right-of $MAIN_PORT --auto \
		--output $OUTPORT_DISCONNECTED --off
	feh --randomize --bg-fill ~/Pictures/wallpaper/*
}
one() {
	xrandr --output $MAIN_PORT --auto --pos 0x0 --scale 1x1 --primary \
		--output $OUTPORT1 --off \
		--output $OUTPORT2 --off
	feh --randomize --bg-fill ~/Pictures/wallpaper/*
}
check() {
	CONNECTED_PORTS=$(xrandr | grep -w 'connected' | awk '{print $1}' | wc -l)
	CONNECTED_MONITORS=$(xrandr --listmonitors | sed 1d | awk '{print $4}' | wc -l)
	[ $CONNECTED_PORTS -gt $CONNECTED_MONITORS ] && two # 如果当前连接接口多于当前输出屏幕 则调用two
	[ $CONNECTED_PORTS -lt $CONNECTED_MONITORS ] && one # 如果当前连接接口少于当前输出屏幕 则调用one
}

case $1 in
one) one ;;
two) two ;;
check) check ;;
*) check ;;
esac
