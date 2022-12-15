#!/bin/sh


for i in `who | cut -f1 -d " "`
do
	echo hello $i
done
