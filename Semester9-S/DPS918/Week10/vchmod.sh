# Assignment 3
# Course:                DPS918
# Family Name:           Phan
# Given Name:            Khai
# Student Number:        100-901-164
# Login name:            kphan6
# Professor:             Shahdad Shariatmadari
# Due Date:              August 7, 2020
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
        *) echo "Usage: vchmod [filename]" >&2
           exit 1 ;;
esac
if [ ! -e $dir ]
then echo "'$1' is not exist or is inaccessible" >&2
        exit 1
fi

directory[0]="/"        #create a directory array
#look up the directory absolute path to count the level from home to current
count=$(readlink -f $dir | tr "/" " " | wc -w)
numLevels=$((count))    #count number of level from root to current
currentLevel=0          #create a currentLevel variable for moving up and down
currentCol=9            #create a currentColumn variable for moving left and right
#initialize place where the cursor will be
col=([0]=2 [1]=4 [2]=6 [3]=10 [4]=12 [5]=14 [6]=18 [7]=20 [8]=22 [9]=26)

#set each of the path level name to directory array for display
for (( i = 1; i <= count; i++ )); do
           directory[i]=$(readlink -f $dir | tr "/" " " | awk '{print $'$i'}')
done
currentLevel=$numLevels #set currentLevel value for starting position

stty -icanon min 1 time 10
stty -echo
clear

#header display
tput cup 0 2
echo "Owner   Group   Other   Filename"
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

tput cup $(( lines - 4 )) 0
echo -n "Valid key: k (up)   , j (down) : move between filenames
           h (left) , l (right): move between permission
           r, w, x, -: change permission; q: quit"
tput cup $(( ( ( currentLevel + 1 ) * 2 ) + 2 )) 2
ls -ld ${pathNames[currentLevel]} | awk '{ print "Links: " $2 "  Owner: " $3 "  Group: " $4 "  Size: " $5 "  Modified: " $6 " " $7 " " $8}'

commands=
while true
do
        if [[ "$currentLevel" -eq 0 ]]; then
                tput cup 3 ${col[$currentCol]}
        else
                tput cup $(( ( ( currentLevel + 1 ) * 2 ) + 1 )) ${col[$currentCol]}
        fi

        commands=$(dd bs=1 count=1 2> /dev/null)
        case $commands in
                #set control method for button up
                k)
                if [[ "$currentLevel" != 0 ]]; then
                        tput cup $(( ( ( currentLevel + 1 ) * 2 ) + 2 )) 0
                        tput el
                        currentLevels=$(( currentLevel-- ))
                        if [ $currentLevel = 0 ]; then
                                tput cup 4 2
                        else
                                tput cup $(( ( ( currentLevel + 1 ) * 2 ) + 2 )) 2
                        fi
                        ls -ld ${pathNames[currentLevel]} | awk '{ print "Links: " $2 "  Owner: " $3 "  Group: " $4 "  Size: " $5 "  Modified: " $6 " " $7 " " $8 }'
                fi      ;;

                #set control method for button down
                j)
                if [[ "$currentLevel" < "$numLevels" ]]; then
                      tput cup $(( ( ( currentLevel + 1 ) * 2 ) + 2 )) 0
                      tput el
                      currentLevels=$(( currentLevel++ ))
                      tput cup $(( ( ( currentLevel + 1 ) * 2 ) + 2 )) 2
                      ls -ld ${pathNames[currentLevel]} | awk '{ print "Links: " $2 "  Owner: " $3 "  Group: " $4 "  Size: " $5 "  Modified: " $6 " " $7 " " $8 }'
                fi      ;;

                #set control method for button left
                h)
                if [[ "$currentCol" > 0 ]]; then
                        currentCols=$((currentCol--));          fi ;;

                #set control method for button right
                l)
                if [[ "$currentCol" < 9 ]]; then
                        currentCols=$((currentCol++));          fi ;;

                #set read permission for user, group and other
                r)
                #set read permission for user
                if [[ "$currentCol" -eq 0 ]]; then
                        chmod u+r ${pathNames[currentLevel]}  2> /dev/null;     fi
                #set read permission for group
                if [[ "$currentCol" -eq 3 ]]; then
                        chmod g+r ${pathNames[currentLevel]}  2> /dev/null;     fi
                #set read permission for other
                if [[ "$currentCol" -eq 6 ]]; then
                        chmod o+r ${pathNames[currentLevel]}  2> /dev/null;     fi

                #retrieve the new permission display and replace the current screen
                permission=$(ls -ld ${pathNames[currentLevel]} | cut -c1-10 | sed 's/./& /g' | sed 's/[^ ]* *[^ ] [^ ] [^ ]/&  /g')
                permission="$permission${directory[currentLevel]}"
                tput cup $(( ( ( currentLevel +1 ) * 2 ) + 1 )) 0
                echo "$permission"      ;;

                #set write permission for user, group and other
                w)
                #set write permission for user
                if [[ "$currentCol" -eq 1 ]]; then
                        chmod u+w ${pathNames[currentLevel]}  2> /dev/null;     fi
                #set write permission for group
                if [[ "$currentCol" -eq 4 ]]; then
                        chmod g+w ${pathNames[currentLevel]}  2> /dev/null;     fi
                #set write permission for other
                if [[ "$currentCol" -eq 7 ]]; then
                        chmod o+w ${pathNames[currentLevel]}  2> /dev/null;     fi

                #retrieve the new permission display and replace the current screen
                permission=$(ls -ld ${pathNames[currentLevel]} | cut -c1-10 | sed 's/./& /g' | sed 's/[^ ]* *[^ ] [^ ] [^ ]/&  /g')
                permission="$permission${directory[currentLevel]}"
                tput cup $(( ( ( currentLevel +1 ) * 2 ) + 1 )) 0
                echo "$permission"      ;;

                #set write permission for user, group and other
                x)
                #set write permission for user
                if [[ "$currentCol" -eq 2 ]]; then
                        chmod u+x ${pathNames[currentLevel]}  2> /dev/null;     fi
                #set write permission for group
                if [[ "$currentCol" -eq 5 ]]; then
                        chmod g+x ${pathNames[currentLevel]}  2> /dev/null;     fi
                #set write permission for other
                if [[ "$currentCol" -eq 8 ]]; then
                        chmod o+x ${pathNames[currentLevel]}  2> /dev/null;     fi

                #retrieve the new permission display and replace the current screen
                permission=$(ls -ld ${pathNames[currentLevel]} | cut -c1-10 | sed 's/./& /g' | sed 's/[^ ]* *[^ ] [^ ] [^ ]/&  /g')
                permission="$permission${directory[currentLevel]}"
                tput cup $(( ( ( currentLevel +1 ) * 2 ) + 1 )) 0
                echo "$permission"      ;;

                #remove permission for user, group and other
                -)
                #remove read permission for user
                if [[ "$currentCol" -eq 0 ]]; then
                        chmod u-r ${pathNames[currentLevel]}  2> /dev/null;     fi
                #remove read permission for group
                if [[ "$currentCol" -eq 3 ]]; then
                        chmod g-r ${pathNames[currentLevel]}  2> /dev/null;     fi
                #remove read permission for other
                if [[ "$currentCol" -eq 6 ]]; then
                        chmod o-r ${pathNames[currentLevel]}  2> /dev/null;     fi
                #remove write permission for user
                if [[ "$currentCol" -eq 1 ]]; then
                        chmod u-w ${pathNames[currentLevel]}  2> /dev/null;     fi
                #remove write permission for group
                if [[ "$currentCol" -eq 4 ]]; then
                        chmod g-w ${pathNames[currentLevel]}  2> /dev/null;     fi
                #remove write permission for other
                if [[ "$currentCol" -eq 7 ]]; then
                        chmod o-w ${pathNames[currentLevel]}  2> /dev/null;     fi
                #remove write permission for user
                if [[ "$currentCol" -eq 2 ]]; then
                        chmod u-x ${pathNames[currentLevel]}  2> /dev/null;     fi
                #remove write permission for group
                if [[ "$currentCol" -eq 5 ]]; then
                        chmod g-x ${pathNames[currentLevel]}  2> /dev/null;     fi
                #rmove write permission for other
                if [[ "$currentCol" -eq 8 ]]; then
                        chmod o-x ${pathNames[currentLevel]}  2> /dev/null;     fi

                #retrieve the new permission display and replace the current screen
                permission=$(ls -ld ${pathNames[currentLevel]} | cut -c1-10 | sed 's/./& /g' | sed 's/[^ ]* *[^ ] [^ ] [^ ]/&  /g')
                permission="$permission${directory[currentLevel]}"
                tput cup $(( ( ( currentLevel +1 ) * 2 ) + 1 )) 0
                echo "$permission"      ;;

                #set control method for quit button
                q)
                stty icanon echo
                tput cup $lines 0
                exit 0  ;;
        esac
done