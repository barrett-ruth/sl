#!/bin/sh

bat="$(cat /sys/class/power_supply/BAT0/capacity)"
filler_icon='/usr/share/icons/Adwaita/16x16/status/airplane-mode-symbolic.symbolic.png'

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

case "$bat" in
50 | 30 | 20 | 10 | 5)
    dunstify -r 3 -i "$filler_icon" -u critical "$(final_bar)B"
    ;;
esac

bat="^c#d4be98^$bat%"

echo "$bat "

unset bat
