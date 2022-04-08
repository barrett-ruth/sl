#!/bin/sh

bat="$(cat /sys/class/power_supply/BAT0/capacity)"
bat="^b#3c3836^^c#d4b398^$bat% "
bat="$bat^b#3c3836^^c#504945^"

echo "$bat"

unset bat
