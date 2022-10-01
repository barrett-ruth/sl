#!/bin/sh

sink="$(pacmd list-sinks | grep '\* index: ' | tail -c 2)"

vol=$(pactl get-sink-volume "$sink" | awk '{ print $5 }')
vol="${vol%?}"
[ "$(pactl get-sink-mute "$sink" | awk '{ print $2 }')" = 'yes' ] && muted=!

vol=" ${vol:-n/a}$muted"

echo "$vol │ "

unset vol muted sink
