#!/bin/sh

bat="$(cat /sys/class/power_supply/BAT0/capacity)"

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

test -f /tmp/bat && cp /tmp/bat /tmp/battmp || touch /tmp/bat
test -f /tmp/battmp || touch /tmp/battmp

while read -r line; do
    [ $bat -gt "$line" ] && rg -v -x "$line" /tmp/battmp >/tmp/bat
done </tmp/battmp

[ "$(cat /sys/class/power_supply/BAT0/status)" = Charging ] && leave

case "$bat" in
50 | 30 | 20 | 10 | 5)
    if [ ! "$(rg -x "$bat" /tmp/bat)" ]; then
        cat /tmp/bat
        sdun -r 3 -u critical "' $(final_bar)B'"
        echo "$bat" >>/tmp/bat
    fi
    ;;
esac

leave
