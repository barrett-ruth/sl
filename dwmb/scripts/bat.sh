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

test -f /tmp/bat && cp /tmp/bat /tmp/battmp || touch /tmp/bat

while read -r line; do
    [ $bat -gt "$line" ] && rg -v -x "$line" /tmp/battmp >/tmp/bat
done </tmp/battmp

case "$bat" in
50 | 30 | 20 | 10 | 5)
    if [ ! "$(rg -x "$bat" /tmp/bat)" ]; then
        dunstify -r 3 -i "$filler_icon" -u critical "$(final_bar)B"
        echo "$bat" >>/tmp/bat
    fi
    ;;
esac

bat="^c#d4be98^$bat%"

echo "$bat "
