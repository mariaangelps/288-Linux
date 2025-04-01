#!/bin/bash

function email(){
        local arg1="$1"

        if [ ! -d "$arg1" ]; then
                echo "no existe"
                return
        fi

	local entries=("$arg1"/*)
	for entry in "${entries[@]}"; do
                if [ -d "$entry" ]; then
                        email "$entry"
                elif [[ "$entry" == *.txt ]]; then
                        echo
		       	echo "Processing file: $entry"
			echo
			#accept emails with .com valid email address and append them to a list of all of them
                        grep -E -o '[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.com' "$entry" 
			grep -E -o '[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.com' "$entry" >> total_emails.txt
                fi
        done
}

# Ensure the temporary file is empty before starting
> total_emails.txt
email "email_dir"
#list the duplicate ones
echo 

echo Duplicate emails:
sort total_emails.txt | uniq -d 
# Remove duplicates, sort, and save to unique_emails.txt
sort total_emails.txt | uniq > unique_emails.txt

rm total_emails.txt
echo
echo "Unique emails saved in unique_emails.txt"

