#!/bin/sh

bat="$(cat /sys/class/power_supply/BAT0/capacity)"

[ "$(cat /sys/class/power_supply/BAT0/status)" = Charging ] && leave

echo "^c#d4be98^$bat% "
