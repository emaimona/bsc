#!/bin/sh

if test $# -ne 2
then
	echo "Exactly two arguments are neeed"
	exit
else
	n=$1
	for i in `seq 0 $2`
	do
		echo "$n^$i -n" |bc
	done	
	echo 
fi
