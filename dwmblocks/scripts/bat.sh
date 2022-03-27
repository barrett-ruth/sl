#!/bin/sh

bat="$(cat /sys/class/power_supply/BAT0/capacity)%"
status="$(cat /sys/class/power_supply/BAT0/status)"
case "$status" in
Charging)
    state='+'
    ;;
Discharging)
    state='-'
    ;;
Full)
    state=''
    ;;
esac
echo "$state$bat"
unset bat state
