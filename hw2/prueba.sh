#!/bin/bash

# Define the input file
file="dictionary.txt"

# Check if the file exists
if [[ ! -f "$file" ]]; then
    echo "Error: File '$file' not found!"
    exit 1
fi

# Count words with exactly three 'e's where each 'e' is separated by at least one non-'e' character
count=$(grep -Ei '^[^e]*e[^e]+e[^e]+e[^e]*$' "$file" | wc -l)

# Display the count
echo "Number of words matching the criteria: $count"

last=$(grep -o '(.*$){3}' "$file")
for word in $last; do
        echo $word
done
