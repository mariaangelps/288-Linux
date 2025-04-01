#!/bin/bash

#Problem 4:

if [ $# -ne 1 ]; then
    echo "File doesnt exist"
    exit 1
fi

file="$1"
currentYear=2024

if [ ! -f "$file" ]; then
    echo "File does not exist, Try again:("
    exit 1
fi

while read -r record; do
    fullName=$(echo "$record" | cut -d, -f1)
    birthDate=$(echo "$record" | cut -d, -f2 | xargs)
    hometown=$(echo "$record" | cut -d, -f3 | xargs)
    country=$(echo "$record" | cut -d, -f4 | xargs) 
    
    #conditional checks if it is composed by 2 names the town
    if [[ "$hometown" =~ ^[A-Za-z]+[[:space:]]+[A-Za-z]+ ]]; then
        birthYear=$(echo "$birthDate" | cut -d- -f1)
        personAge=$((currentYear - birthYear))
       	echo "$fullName, $personAge" 
    fi

done < "$file" | sort -t, -k2 -nr  
echo
echo "Overall List:"
cat "$file" | sort -t, -k2 -nr 

