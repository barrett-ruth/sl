#!/bin/sh

sink="$(sink)"
vol=$(pactl get-sink-volume "$sink" | awk '{ print $5 }')

[ "$(pactl get-sink-mute "$sink" | awk '{ print $2 }')" = 'yes' ] && muted='!'
out="${vol%?}$muted"

echo "V:${out:-n/a}"
unset vol muted out sink
