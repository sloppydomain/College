#!/bin/bash
echo "Enter the number of terms:"
read a
for ((i=1; i<=a; i++))
do
temp=$((i * i))
echo "Square of $i is $temp"
done
