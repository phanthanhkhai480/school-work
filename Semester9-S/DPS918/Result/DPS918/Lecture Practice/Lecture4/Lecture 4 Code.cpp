4.1
exec 4> myFiles 
echo "Here are my current files" >&4 
ls -l >&4 
exec 4>&-

-4.2
echo "Here are my current files" > myFiles 
ls -l >> myFiles

-4.3
exec 4< myFiles
read line1 <&4
read line2 <&4
exec 4<&-
echo $line1
echo $line2

-4.4
read line1 < myFiles 
read line2 < myFiles 
echo $line1 
echo $line2

-4.5
exec 4<> myFiles
read line1 <&4
read line2 <&4
echo "This will be a new third line" >&4
exec 4<&-