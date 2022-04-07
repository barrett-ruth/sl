#!/bin/sh

bat="^b#3c3836^^c#d4b398^ $(cat /sys/class/power_supply/BAT0/capacity)%"
# bat="^b#3c3836^^c#d4b398^ $(cat /sys/class/power_supply/BAT0/capacity)%"
# bat="^b#3c3836^^c#d4be98^ $(cat /sys/class/power_supply/BAT0/capacity)%"
# status="$(cat /sys/class/power_supply/BAT0/status)"
# case "$status" in
# Charging)
#     state='+'
#     ;;
# Discharging)
#     state='-'
#     ;;
# Full)
#     state=''
#     ;;
# esac
# echo "$state$bat"
echo "$bat"
# unset bat state
unset bat
