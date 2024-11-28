#!/bin/sh

sink_info="$(pacmd list-sinks | sed '/\* index/p')"
sink_id="$(echo "$sink_info" | rg '\* index')"
sink_id="${sink_id##* }"

vol=$(pactl get-sink-volume "$sink_id" | awk '{ print $5 }')
vol="${vol%?}"
[ "$(pactl get-sink-mute "$sink_id" | awk '{ print $2 }')" = 'yes' ] && muted=!

vol=" ${vol:-n/a}$muted"

echo "$vol | "

unset vol muted sink_info sink_id
