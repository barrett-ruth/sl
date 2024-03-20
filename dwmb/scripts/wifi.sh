#!/bin/sh

ssid="$(iwctl station wlan0 get-networks | grep '>' | awk '{ print $4 }')"
if [ -z "$ssid" ]; then
  if ping archlinux.org -c 1 >/dev/null 2>&1; then
    ssid='eth'
  fi
fi
ssid="${ssid:-n/a}"

echo "$ssid │ "
