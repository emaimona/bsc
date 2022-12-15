#!/bin/sh

if test $# -ne 1
then
	echo Exactly one argument is needed	
	exit 1
fi

if test -f $1
then
	awk '{print length, $0}' $1 | sort -nr | sed "s/^[0-9]\+ //g" | head -n 1
else
	echo Please input a valid file!
fi
