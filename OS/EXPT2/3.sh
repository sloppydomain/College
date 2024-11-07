#!/bin/bash

read -p "Enter a number: " n

m=$n
digits=()
while [ $m -ne 0 ]; do
    digit=$((m % 10))
    digits+=($digit)
    m=$((m / 10))
done

num_digits=${#digits[@]}
for ((i = 0; i < num_digits; i++)); do
    for ((j = i + 1; j < num_digits; j++)); do
        if ((digits[i] > digits[j])); then
            temp=${digits[i]}
            digits[i]=${digits[j]}
            digits[j]=$temp
        fi
    done
done

largest=${digits[$((num_digits - 1))]}
smallest=${digits[0]}
second_largest='unset'
second_smallest='unset'
for ((i = num_digits - 2; i >= 0; i--)); do
    if [ "${digits[i]}" != "$largest" ]; then
        second_largest=${digits[i]}
        break
    fi
done
for ((i = 1; i < num_digits; i++)); do
    if [ "${digits[i]}" != "$smallest" ]; then
        second_smallest=${digits[i]}
        break
    fi
done
if [ "$second_largest" = 'unset' ] || [ "$second_smallest" = 'unset' ]; then
    echo "Not enough distinct digits to find second largest and second smallest."
else
    difference=$((second_largest - second_smallest))
    echo "Second Largest: $second_largest"
    echo "Second Smallest: $second_smallest"
    echo "Difference is: $difference"
fi

