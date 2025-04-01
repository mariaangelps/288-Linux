#!/bin/bash

# Problem 1:

# Find the number/count of words in dictionary.txt that have at 
# least three 'a's (e.g., banana, apparatus, madagascar, etc.). (case insensitive)

# Verify if file exists
if [[ ! -f dictionary.txt ]]; then
    echo "dictionary.txt does not exist."
    exit 1
fi

# Convert all text to lowercase
lower_words=$(tr '[:upper:]' '[:lower:]' < dictionary.txt)

# Find words with at least 3 'a's and count them
count=$(echo "$lower_words" | grep -E '([^a]*a){3,}' | wc -l)

echo "Number of words with at least 3 'a's: $count"


# Problem 2:

# Find the number of words in dictionary.txt that have exactly three 'e's
# and where all 'e's are separated by at least one non-'e' character.

word_3e=$(grep -iE '^[^e]*e[^e]+e[^e]+e[^e]*$' dictionary.txt | wc -l)

echo "Number of words with exactly 3 'e's (separated by non-'e' characters): $word_3e"


# Problem 3:

# 3a: Find words with at least two adjacent 'e's and count them.
word_ade_count=$(grep -i 'ee' dictionary.txt | wc -l)

echo "Number of words with at least one adjacent 'ee': $word_ade_count"

# 3b: Find the three most common final three letters of these words.
last=$(grep -i 'ee' dictionary.txt | grep -oE '.{3}$' | sort | uniq -c | sort -nr | head -n 3)

echo "3 most common final three letters:"
echo "$last"

