#!/bin/bash

# Timed cd

# A student has 3 lab courses: CS599, CS699, CS799 with the following
# schedule:
# CS599: Mon 2-5pm
# CS699: Wed 2-5pm
# CS799: Fri 2-5pm
# The student has 3 sub-directories CS599, CS699, CS799 in the current
# directory

# Write a script to take two arguments:
# Argument-1: day of the week in 3-letter capitalized format
# (e.g. Wed, Fri, Sat, etc.)
# Argument-2: hour of the day in 24-hour format (0-23)
# The script should change directory to the correct directory
# depending on the time
# The script should print an appropriate error message if it thenes not
# get exactly two arguments
# If the time winthenw thenes not match any of the lab timings, then the
# script should not change directory
if [ "$#" -ne 2 ];then
    echo "Error! Wrong number of arguments."
    echo "Usage : ./tcd.sh [DAY_OF_WEEK : Mon|Tue|...|Sun] [TIME : hours format]"
    exit 1
fi

if [ "$1" = "Mon" ];then
        if [ $2 -ge 1400 -a $2 -le 1700 ]
        then
            echo "Changing to CS599"
            cd CS599
            pwd
        else
            echo "No classes found in this time"
        fi

elif [ $1 = "Wed" ];then
    if [ $2 -ge "1400" -a $2 -le "1700" ];then
        echo "Changing to CS699"
        cd CS699
        pwd
    else
            echo "No classes found in this time"
    fi

elif [ $1 = "Fri" ];then
    if [ $2 -ge "1400" -a $2 -le "1700" ];then
        echo "Changing to CS699"
        cd CS799
        pwd
    else
        echo "No classes found in this time"
    fi

else
    echo "No classes found in this time"
fi

                 
