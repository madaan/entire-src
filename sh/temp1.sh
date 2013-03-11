#!/bin/bash
clear
echo 'This script will install: Firefox 17.0.1 (language: enGB or itIT or enUS) and flash 11 in Firefox17.0.1, continue?'
read  reply
b="yes";
if  [[ "$reply" = "yes" ]]; then
echo "Got you!";
else
  echo "I'm quitting the script..."
  exit
fi
