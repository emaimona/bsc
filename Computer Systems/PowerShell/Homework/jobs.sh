#!/bin/sh



if test $# -ne 1
then
	echo Exactly one argument is needed!
	exit 1
fi




NoViolentWorkPlaces() {

	r=`cat $1 | grep -c ".\+, 0,.\{2\}"`
	echo Workplaces where no violent acts have been reported:
	if test $r -eq 0
	then
		echo NONE
		echo
	else
		cat $1 | grep ".\+, 0,.\{2\}" | cut -f1 -d"," | nl
		echo
	fi
}


NbrOfGuards() {
	r=`cat $1 | cut -f4 -d"," | sed "s/ //g"`
	sum=0
	for i in $r
	do
		sum=`expr $i + $sum`
	done

	echo Total number of security guards according to the data file provided: $sum
	echo

}

HighestIncidents() {
	highest=`cat $1 | cut -f3 -d"," | sort -nr | sed "s/ //g" | head -n 1`
	echo "The names of the workplaces with the highest number of violent incidents are located, their name(s) and address(es)."
	cat $1 | grep ".\+, $highest, [0-9]" | cut -f1,2 -d"," | sed "s/,/\\t/g" | nl
	echo
}

if test -f $1
then
	echo
	NoViolentWorkPlaces $1
	NbrOfGuards $1
	HighestIncidents $1
else
	echo Please provide a valid file!
	exit 1
fi





