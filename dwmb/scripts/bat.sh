#!/bin/sh

bat="$(cat /sys/class/power_supply/BAT0/capacity)"

[ -n "$bat" ] && echo "$bat% │ "

unset bat
