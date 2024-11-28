#!/bin/sh

station="$(iwctl station list | rg ' connected' | awk '{ print $2 }')"
if [ -n "$station" ]; then
  station_info="$(iwctl station "$station" show)"
  ssid="$(echo "${station_info#*Connected network}" | head -n 1 | xargs)"
fi
ssid="${ssid:-n/a}"

echo "$ssid | "
