#!/bin/sh

disk="$(df -h | grep '/home' | awk '{ print $4 }')"
ram="$(free -h | grep 'Mem' | awk '{ print $7 }')"

echo "R:${ram%??} & D:${disk%?}"
unset disk ram
