#!/bin/sh

STATE_FILE="$XDG_STATE_HOME/".battery_notify_state
filler_icon='/usr/share/icons/Adwaita/16x16/status/airplane-mode-symbolic.symbolic.png'

bat="$(cat /sys/class/power_supply/BAT0/capacity)"
status="$(cat /sys/class/power_supply/BAT0/status)"

if [ "$status" = "Discharging" ]; then
  if [ "$bat" -eq 30 ] && ! grep -q "^30$" "$STATE_FILE" 2>/dev/null; then
    notify-send --urgency normal -i "$filler_icon" "Battery at 30%"
    echo 30 >"$STATE_FILE"
  fi

  if [ "$bat" -eq 15 ] && ! grep -q "^15$" "$STATE_FILE" 2>/dev/null; then
    notify-send --urgency critical -i "$filler_icon" "Battery at 15%"
    echo 15 >"$STATE_FILE"
  fi
else
  true>"$STATE_FILE" 2>/dev/null
fi

[ -n "$bat" ] && echo "$bat% | "

unset bat status
