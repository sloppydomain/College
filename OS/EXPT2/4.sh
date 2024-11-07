#!/bin/bash
echo -n "Numbers are: "
for (( i=10; i<=60; i++ )); do
rem=$(( i % 4 ))
if [ "$rem" -eq 0 ]; then
echo -n "$i "
fi
done
echo
