#!/bin/sh

STATE_FILE="$XDG_STATE_HOME/".battery_notify_state

bat="$(cat /sys/class/power_supply/BAT0/capacity)"
status="$(cat /sys/class/power_supply/BAT0/status)"

if [ "$status" = "Discharging" ]; then
  if [ "$bat" -eq 24 ] && ! grep -q "^30$" "$STATE_FILE" 2>/dev/null; then
    notify-send --urgency normal "Battery at 30%"
    echo 30 >"$STATE_FILE"
  fi

  if [ "$bat" -eq 15 ] && ! grep -q "^15$" "$STATE_FILE" 2>/dev/null; then
    notify-send --urgency critical "Battery at 15%"
    echo 15 >"$STATE_FILE"
  fi
else
  >"$STATE_FILE" 2>/dev/null
fi

[ -n "$bat" ] && echo "$bat% | "

unset bat status
