#!/bin/bash

# This script should print the IP address of your linux machine's eth0
# interface.  The output should only be an IP address (remove the
# irrelevant parts of the ifconfig command output).
 ifconfig eth0|grep "inet addr"|cut -f2 -d':'|cut -f1 -d ' '
