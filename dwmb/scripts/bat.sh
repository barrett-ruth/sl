#!/bin/sh

bat="$(cat /sys/class/power_supply/BAT0/capacity)"
filler_icon='/usr/share/icons/Adwaita/16x16/status/airplane-mode-symbolic.symbolic.png'

leave() {
    echo "^c#d4be98^$bat% "
    exit 0
}

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

test -f /tmp/bat || touch /tmp/bat
test -f /tmp/battmp || touch /tmp/battmp

while read -r line; do
    [ $bat -gt "$line" ] && rg -v -x "$line" /tmp/battmp >/tmp/bat
done </tmp/battmp

[ "$(cat /sys/class/power_supply/BAT0/status)" = Charging ] && leave

case "$bat" in
50 | 30 | 20 | 10 | 5)
    if [ ! "$(rg -x "$bat" /tmp/bat)" ]; then
        dunstify -r 3 -i "$filler_icon" -u critical "$(final_bar)B"
        echo "$bat" >>/tmp/bat
    fi
    ;;
esac

leave
