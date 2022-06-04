#!/bin/sh

bat="$(cat /sys/class/power_supply/BAT0/capacity)"

format_chars() {
    in="$1"

    fill="$(printf "%$((in / 5))"s | sed 's| |-|g')"
    rest="$(printf "%$((20 - in / 5))"s)"

    echo "$fill$rest"
}

final_bar() {
    spacing='   '
    echo " $(format_chars "$bat")$spacing$bat"
}

[ "$(cat /sys/class/power_supply/BAT0/status)" = Charging ] && leave

echo "^c#d4be98^$bat% "
