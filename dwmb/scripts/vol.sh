#!/bin/sh

sink="$(pacmd list-sinks | grep '\* index: ' | tail -c 2)"

vol=$(pactl get-sink-volume "$sink" | awk '{ print $5 }')
vol="${vol%?}"
[ "$vol" -gt 49 ] && icon= || icon=
[ "$(pactl get-sink-mute "$sink" | awk '{ print $2 }')" = 'yes' ] && icon= && vol=
vol=" $icon ${vol:-n/a}"

echo "^b#504945^^c#d4be98^$vol"

unset vol muted sink
