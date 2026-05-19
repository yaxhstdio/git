#!/bin/bash

echo "Enter file name:"
read file

echo "Lines: $(wc -l < $file)"
echo "Words: $(wc -w < $file)"
echo "Characters: $(wc -c < $file)"

echo "Enter a string:"
read str

rev=$(echo "$str" | rev)

if [ "$str" = "$rev" ]; then
    echo "$str is a Palindrome"
else
    echo "$str is Not a Palindrome"
fi