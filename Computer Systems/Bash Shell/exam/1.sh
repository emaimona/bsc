#!/bin/sh

if test $# -ne 3
then
	echo Exactly 3 parameters are needed!
	exit 1
fi

isInt() {
r=`echo $1 | grep -c -E ^\-?[0-9]?\.?[0-9]+$`
test $r -eq 0
return $?
}

if isInt $1
then
	echo $1 is not an integer
else
	a=`expr $1 \* 2`
	echo -n "$a "
fi

if isInt $2
then
	echo $2 is not an integer
else
	b=`expr $2 \* 2`
	echo -n "$b "
fi


if isInt $3
then
	echo $3 is not an integer
else
	c=`expr $3 \* 2`
	echo -n "$c "
fi

echo
