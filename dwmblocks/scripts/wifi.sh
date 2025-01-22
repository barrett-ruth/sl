#!/bin/sh

exists() {
  command -v "$1" >/dev/null 2>&1
}

if exists nmcli; then
  nmcli -t -f DEVICE,TYPE,NAME connection show --active | {
    IFS=":" read -r device type_ name
    case "$type_" in
    *ethernet)
      ssid="$device"
      ;;
    *)
      ssid="$device:$name"
      ;;
    esac
    echo "$ssid | "
  }
elif exists iwctl; then
  station="$(iwctl station list | rg ' connected' | awk '{ print $2 }')"
  if [ -n "$station" ]; then
    station_info="$(iwctl station "$station" show)"
    ssid="$(echo "${station_info#*Connected network}" | head -n 1 | xargs)"
  fi
  ssid="${ssid:-n/a}"
  echo "$ssid | "
fi

unset ssid device name
