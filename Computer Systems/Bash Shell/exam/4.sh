#!/bin/sh


if test -f $1
then
	while read line
	do
		for i in $line
		do
			r=`echo $i | grep -c -E ^\-?[0-9]?\.?[0-9]+$`

			if test $r -ne 0
			then
				if test `expr $i % 2` -eq 0
				then
					echo -n "$i "
				fi
			fi
		done
		echo
	done < $1	
else
	echo Please give a valid file
	exit 1
fi
