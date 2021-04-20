#!/bin/bash

/usr/bin/amixer -qM set Master 5%- umute
#pactl set-sink-volume @DEFAULT_SINK@ -5%
dunstify "当前音量: `ponymix get-volume`%" -h int:value:"`ponymix get-volume`"
