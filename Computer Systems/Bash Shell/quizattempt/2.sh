#!/bin/sh

prim() {
	n=2

	while test `expr $1 % 2` -eq 0
	do
			 n=`expr $n + 1`
  done

  if $n -ne $1

	
	return $?
}

echo prim($1)
