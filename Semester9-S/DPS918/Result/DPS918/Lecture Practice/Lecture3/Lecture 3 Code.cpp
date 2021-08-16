-3.1
if cd $1
then
   echo "Current directory has been changed to $PWD"
fi

-3.2
if cd $1
then
   echo "Current directory has been changed to $PWD"
else
   echo "Current directory is $PWD, could not be changed to $1"
fi

-3.3
if grep "Lamborghini" $1
then
   echo "We have at least one Lamborghini on the lot, hooray!"
else if grep "Mercedes" $1
     then
        echo "We have at least one Mercedes on the lot, yippee!"
     else if grep "Toyota" $1
          then
             echo "We have at least one Toyota on the lot, whoopie!"
          else if grep "Fiat" $1
               then
                 echo "We have at least one Fiat on the lot, too bad!"
               else
                  echo "What happened to all our cars?"
               fi
          fi
     fi
fi

if grep "Lamborghini" $1
then
   echo "We have at least one Lamborghini on the lot, hooray!"
elif grep "Mercedes" $1
then
   echo "We have at least one Mercedes on the lot, yippee!"
elif grep "Toyota" $1
then
   echo "We have at least one Toyota on the lot, whoopie!"
elif grep "Fiat" $1
then
   echo "We have at least one Fiat on the lot, too bad!"
else
   echo "What happened to all our cars?"
fi

--3.4
if test $1 = "-l"
then
   echo "A long listing will be produced:"
fi
ls $1

--3.5
if [ $1 = "-l" ]
then
   echo "A long listing will be produced:"
fi
ls $1

--3.6
grep "$1" cars
if [ $? = 0 ]
then
   echo "We have at least one $1 on the lot"
fi

--3.7
if grep "$1" cars
then
   echo "We have at least one $1 on the lot"
fi

--cars
hhuang66@matrix:~/DPS918/Lecture3> vi cars
test 3.6

-3.8
if [ $# != 3 ]
   then
      echo "This script requires 3 arguments"
      exit 1
fi

-3.9
if [ ! -r "$1" ]
   then
      echo "File $1 cannot be read"
      exit 1
fi

-3.10
if [ ! -d "$1" ]
   then
      echo "$1 is not a directory"
      exit 1
fi

-3.11
salary=5
if [ $salary -gt 4 ]
then
  echo "salary is great than 4"
fi

-3.12
salary=5
if test  $salary -gt 4 
then
  echo "salary is great than 4"
fi

-3.13
if [ ! -d "$1" -o ! -w "$1" -o ! -x "$1" ]
then
   echo "Cannot delete a filename from $1"
   exit 1
fi

-3.14
if [[ $1 > $2 || $2 > $3 ]]
then
   echo "Arguments are not in correct sort order"
   exit 1
fi

-3.15
if [[ -z $1 || $1 =~ [^0-9] ]]
then
   echo "First argument is not numeric"
   exit 1
fi

-3.16
if [ -z "$1" -o "$(echo $1 | grep "[^0-9]")" != "" ]
then
   echo "First argument is not numeric"
   exit 1
fi

-3.17
if (( $1 > $2 || $1 <= 0 ))
then
   echo "Range of first two arguments is incorrect"
   exit 1
fi

-3.18
echo -n "Please enter an integer: " > /dev/tty
read number
if [ -z "$number" ] || echo $number | grep "[^0-9]" > /dev/null
then
   echo "Sorry, '$number' is not a valid integer" >&2
else
   echo "Thank you!"
fi

