#!/bin/bash
let color=0
let bg=140
while read file
do
	name=$(echo $file | awk '{print $1}')
	printf "\t\t${name^^} = ${color},\n\t\t${name,,} = ${color},\n\t\tBG_${name^^} = ${bg},\n\t\tbg_${name,,} = ${bg},\n"
	((color++))
	((bg++))
done
