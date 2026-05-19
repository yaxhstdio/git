#!/bin/bash

# Palindrome Check
echo "Enter a string:"
read str

rev=$(echo "$str" | rev)

if [ "$str" = "$rev" ]; then
    echo "$str is a Palindrome"
else
    echo "$str is Not a Palindrome"
fi

# Factorial
echo "Enter a number:"
read num

fact=1
for ((i=1; i<=num; i++))
do
    fact=$((fact * i))
done

echo "Factorial of $num is $fact"