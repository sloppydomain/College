#!/bin/bash
read -p "Enter a path: " path
if [ -d "$path" ]; then
echo "$path is a directory."
else
echo "$path is not a directory."
fi
