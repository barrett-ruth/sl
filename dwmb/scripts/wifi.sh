#!/bin/sh

ssid="$(iwctl station wlan0 get-networks | grep '>' | awk '{ print $2 }')"
ssid="${ssid#????}"
ssid="${ssid:-n/a}"
ssid="^c#d4be98^^b#504945^ $ssid"

echo "$ssid "

unset ssid
