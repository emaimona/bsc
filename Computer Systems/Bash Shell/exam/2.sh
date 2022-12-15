#!/bin/sh

if test $# -lt 1
then
	echo -n At least one argument is needed
fi

for i in $*
do
	if test `echo -n $i | wc -c` -ge 3
	then
		echo $i | head -c 3 | tail -c 1
		echo -n " "
	fi
done
echo
