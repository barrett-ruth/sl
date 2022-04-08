#!/bin/sh

sink="$(sink)"
vol=$(pactl get-sink-volume "$sink" | awk '{ print $5 }')
[ "$(pactl get-sink-mute "$sink" | awk '{ print $2 }')" = yes ] && muted=!
out="${vol%?}$muted"
out="${out:-n/a}"

echo "^b#3c3836^^c#504945^^c#d4be98^^b#504945^ V:$out"

unset vol muted out sink
