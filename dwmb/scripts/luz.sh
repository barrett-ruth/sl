#!/bin/sh

luz="$(xbacklight -get)"
luz="L:${luz%%.*}"
luz=" ^c#d4be98^^b#504945^ $luz^c#a89984^ "

echo "$luz"
unset luz
