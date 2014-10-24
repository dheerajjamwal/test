#!/bin/bash
while read line
do
#echo -e "$line \n"; 
str="ls $line";
#echo $str
#echo 'ls $line ' > l
#str1=(system($str))
#echo "STR1 == $str1"
#if  "$str1" ; then 
if  ls file ; then 
echo "in"
#reak
else
echo "in else"
break
fi
done < file
