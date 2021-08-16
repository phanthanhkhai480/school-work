# Assignment 2
# Course:                DPS918
# Family Name:           Phan
# Given Name:            Khai
# Student Number:        100-901-164
# Login name:            kphan6
# Professor:             Shahdad Shariatmadari
# Due Date:              July 24, 2020
#
# I declare that the attached assignment is my own work in accordance with
# Seneca Academic Policy.  No part of this assignment has been copied manually
# or electronically from any other source (including web sites) or distributed
# to other students.

#!/bin/bash
lines=$(tput lines)
columns=$(tput cols)
trap "stty icanon echo; tput cup $lines 0; exit 0" SIGINT

#set error message for arguments
case $# in
	0) dir=.  ;;
	1) dir=$1 ;;
	*) echo "Usage: showpath [filename]" >&2
	   exit 1 ;;
esac
if [ ! -e $dir ]
then echo "$1 is not a valid file name" >&2
	exit 1
fi

#create a directory array
directory[0]="/"
#look up the directory absolute path to count the level from home to current
count=$(readlink -f $dir | tr "/" " " | wc -w)
currentLevel=0
currentCol=9
col=([0]=2 [1]=4 [2]=6 [3]=10 [4]=12 [5]=14 [6]=18 [7]=20 [8]=22 [9]=26)
numLevels=$(( count ))

#set each of the path level name to directory array for display
for (( i = 1; i <= count; i++ ))
do
   directory[i]=$(readlink -f $dir | tr "/" " " | awk '{print $'$i'}')
done
currentLevel=$numLevels

stty -icanon min 1 time 10
stty -echo
clear

#header display
tput cup 0 2
echo "Owner   Group   Oother   Filename"
tput cup 1 2
echo "-----   -----   -----   --------" 
tput cup 3 0

#adding spaces for each permission and permission group
pathNames[0]=${directory[0]}
permission=$(ls -ld ${pathNames[0]} | cut -c1-10 | sed 's/./& /g' | sed 's/[^ ]* *[^ ] [^ ] [^ ]/&  /g')
permission="$permission${directory[0]}"
echo "$permission"

for ((i = 1; i <= count; i++))
do
	if [ ! -d "${pathNames[i-1]}${dirNames[i]}/" ]; then
		pathNames[i]="${pathNames[i-1]}${directory[i]}"
	else
	        pathNames[i]="${pathNames[i-1]}${directory[i]}/"
	fi
	permission=$(ls -ld ${pathNames[i]} | cut -c1-10 | sed 's/./& /g' | sed 's/[^ ]* *[^ ] [^ ] [^ ]/&  /g')
	permission="$permission${directory[i]}"
	tput cup $(( ( ( i + 1 ) * 2 ) + 1 )) 0
	echo "$permission" | cut -c1-$columns
done

tput cup $(( lines - 2 )) 0
echo -n "Valid commands: u(p) d(own) q(uit)"
tput cup $(( ( ( currentLevel + 1 ) * 2 ) + 2 )) 2
ls -ld ${pathNames[currentLevel]} | awk '{ print "Links: " $2 "  Owner: " $3 "  Group: " $4 "  Size: " $5 "  Modified: " $6 " " $7 " " $8}'

commands=
while true
do
	if [ $currentLevel = 0 ]; then
		tput cup 3 ${col[$currentCol]}
	else
        	tput cup $(( ( ( currentLevel + 1 ) * 2 ) + 1 )) ${col[$currentCol]}
	fi

	commands=$(dd bs=1 count=1 2> /dev/null)
	case $commands in
		#set control method for button up
		u)
		if [[ $currentLevel != 0 ]]; then
			tput cup $(( ( ( currentLevel + 1 ) * 2 ) + 2 )) 0
			tput el
			currentLevels=$(( currentLevel-- ))
			if [ $currentLevel = 0 ]; then
				tput cup 4 2
			else
			        tput cup $(( ( ( currentLevel + 1 ) * 2 ) + 2 )) 2
			fi
			ls -ld ${pathNames[currentLevel]} | awk '{ print "Links: " $2 "  Owner: " $3 "  Group: " $4 "  Size: " $5 "  Modified: " $6 " " $7 " " $8 }'
		fi	;;

		#set control method for button down
		d)
	      	if [[ $currentLevel < $numLevels ]]; then
		      tput cup $(( ( ( currentLevel + 1 ) * 2 ) + 2 )) 0
		      tput el
		      currentLevels=$(( currentLevel++ ))
		      tput cup $(( ( ( currentLevel + 1 ) * 2 ) + 2 )) 2
		      ls -ld ${pathNames[currentLevel]} | awk '{ print "Links: " $2 "  Owner: " $3 "  Group: " $4 "  Size: " $5 "  Modified: " $6 " " $7 " " $8 }'
	      	fi	;;

		#set control method for quit button
		q)
		stty icanon echo
		tput cup $lines 0
		exit 0	;;	
	esac
done

