#!/bin/sh

ssid="$(iwctl station wlan0 get-networks | grep '>' | awk '{ print $4 }')"
ssid="${ssid:-n/a}"

echo "^b#504945^ $ssid "
