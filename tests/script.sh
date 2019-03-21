#!/bin/bash
# My script to make loads of invalid tests
A="invalid"
B=9
C=".fillit"
D="$A$B$C"
COUNT=0
echo "making $N files!"
while [ $COUNT -lt 10 ]; do
	echo The count is $COUNT
	touch $D
	let COUNT=COUNT+1
	let B=B+1
	done
echo "DONE"