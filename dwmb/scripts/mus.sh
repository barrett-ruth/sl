#!/bin/sh

[ "$(ps aux | rg mpv)" ] || exit

music="$(echo '{ "command": ["get_property", "filtered-metadata"] }' | socat - /tmp/mpvsocket | jq -r '[ .data.Artist, .data.Title ] | join (" - ")' | tr '\n' ' ')"

[ "$music" = '' ] || music=" $music│"

echo "^b#504945^$music"
