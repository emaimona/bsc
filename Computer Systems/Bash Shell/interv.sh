#!/bin/sh

if test $# -eq 1
then
res=`echo $1 | grep "^[0-9]\+$" | wc -l`
 if test $res -eq 1
 then
	if test $1 -gt 5 -a $1 -lt 10
	then
		echo good
	else
		echo not good
	fi
 else
	echo Not a number
 fi
else
	echo Give me just 1 number
fi
