#! /bin/bash
# DWM自启动脚本 仅作参考
# 搭配 https://github.com/yaocccc/scripts 仓库使用 目录位置 ~/scripts
# 部分配置文件在 ~/scripts/config 目录下

_thisdir=$(
	cd $(dirname $0)
	pwd
)

settings() {
	[ $1 ] && sleep $1
	xset -b # 关闭蜂鸣器
	# syndaemon -i 1 -t -K -R -d # 设置使用键盘时触控板短暂失效
	$DWM/config/set_screen.sh two # 设置显示器
}

daemons() {
	[ $1 ] && sleep $1
	$_thisdir/statusbar/statusbar.sh cron &                  # 开启状态栏定时更新
	picom --config $DWM/config/picom.conf >>/dev/null 2>&1 & # 开启picom
	dunst &                                                  # 开启通知server
	fcitx5 &                                                 # 开启输入法
	blueman-applet &                                         # 蓝牙托盘
	nm-applet &                                              #网络托盘
	polkit-dumb-agent &
	flameshot & # 截图要跑一个程序在后台 不然无法将截图保存到剪贴板
	# xss-lock -- ~/scripts/blurlock.sh &                                              # 开启自动锁屏程序
}

cron() {
	[ $1 ] && sleep $1
	let i=10
	while true; do
		[ $((i % 10)) -eq 0 ] && $DWM/config/set_screen.sh check                   # 每10秒检查显示器状态 以此自动设置显示器
		[ $((i % 300)) -eq 0 ] && feh --randomize --bg-fill ~/Pictures/wallpaper/* # 每300秒更新壁纸
		sleep 10
		let i+=10
	done
}

settings & # 初始化设置项
daemons &  # 后台程序项
cron 5 &   # 定时任务项
