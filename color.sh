#!/bin/bash
while read file
do
	something="$(/home/hamza/PROJECTS/clang/base.c/base hexa ${file:0:2} ${file:2:2} ${file:4:2} | tr ' ' ';')"
	printf "\t\t"
	echo  "\"\\e[38;2;${something}m\","
done
