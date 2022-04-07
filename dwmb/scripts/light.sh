#!/bin/sh

light="$(xbacklight -get)"

echo "L:${light%%.*}"
unset light
