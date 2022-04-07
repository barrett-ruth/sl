#!/bin/sh

ssid="$(iwctl station wlan0 get-networks | grep '>' | awk '{ print $2 }')"
ssid="${ssid#????}"

echo "S:${ssid:-n/a}"
unset ssid
