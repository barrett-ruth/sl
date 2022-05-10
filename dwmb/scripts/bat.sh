#!/bin/sh

bat="$(cat /sys/class/power_supply/BAT0/capacity)%"
bat="^c#d4be98^$bat"

echo "$bat "

unset bat
