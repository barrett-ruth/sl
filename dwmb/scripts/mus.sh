#!/bin/sh

[ "$(ps aux | rg mpv)" ] || exit

music="$(echo '{ "command": ["get_property", "filtered-metadata"] } | join("\\:")' | socat - /tmp/mpvsocket | jq -r '[ .data.Artist, .data.Album, .data.Title ] | join(":")' | tr '\n' ' ' | sed 's/:/ - /;s/:/ \/ /')"

[ "$music" = ' -  /  ' -o "$music" = '' ] && unset music && exit
[ "${#music}" -gt 56 ] && music="$(echo "$music" | sed 's/-.*\/ /-/')"

echo "$music"

unset music
