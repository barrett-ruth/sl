#!/bin/sh

ssid="$(iwctl station wlan0 get-networks | grep '>' | awk '{ print $2 }')"
ssid="${ssid#????}"
ssid=" ${ssid:-n/a}"
ssid="^b#504945^^c#3c3836^^b#a89984^ $ssid"

echo "$ssid"

unset ssid
