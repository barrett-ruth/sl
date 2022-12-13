#!/bin/sh

[ "$(ps aux | rg mpv)" ] || exit

music="$(echo '{ "command": ["get_property", "filtered-metadata"] } | join("\\:")' | socat - /tmp/mpvsocket | jq -r '[ .data.Artist, .data.Album, .data.Title ] | join(":")' | tr '\n' ' ' | sed 's/:/ - /;s/:/ \/ /')"

[ "${#music}" -gt 56 ] && music="$(echo "$music" | sed 's/-.*\/ /-/')"
[ "$music" = '' ] || music="$music│ "

echo "$music"

unset music
