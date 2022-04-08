#!/bin/sh

sink="$(sink)"
vol=$(pactl get-sink-volume "$sink" | awk '{ print $5 }')
[ "$(pactl get-sink-mute "$sink" | awk '{ print $2 }')" = 'yes' ] && muted='!'
out="${vol%?}$muted"
out=" V:${out:-n/a}"

echo "^b#504945^^c#d4be98^$out"

unset vol muted out sink
