#!/bin/bash
while read file
do
	name=$(echo $file | awk '{print $1}')
	number=$(echo $file | awk '{print $2}')
	number=$(/home/hamza/PROJECTS/clang/base.c/base hexa ${number:0:2} ${number:2:2} ${number:4:2} | tr ' ' ';')
	printf "\t\t\t"
	echo -n "{\"${name^^}\", \"${number}\"},"
	echo
done
