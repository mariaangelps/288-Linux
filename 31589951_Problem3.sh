#!/bin/bash 

#Problem 3:
function check_parameters(){
        #check if there is an argument or not by using $1, which is the 1st command line argument
   	if [ $# -lt 3 ]; then
        
		echo "There should be at least 3 parameters/filenames provided"
		exit 1
	# nth parameter
	elif [ $# -ge 3 ]; then
		#stores each file inside an array as elements
		file_n=("$@")
	fi

	#verify if file exists, If a file does not exist, print a warning message and skip to the next file.

	for f in "${file_n[@]}"; do
		if [ ! -e "$f" ]; then
			echo "Warning! File $f does not exist"
			echo "But I can create it! Go see the backup directory!"
			continue
		fi
	done
	
	#create timestamped directory 

	timestamp=$(date +"%Y-%m-%d")
	d_name="backup_${timestamp}"
	#echo "created dir"
	#prevent creating it again once created
	mkdir -p "$d_name"

	log_file="$d_name/backup_log.txt" > "$log_file"

	#4a.Copy file into backup directory
	for f in "${file_n[@]}"; do

		#if file doesnt exist, create them and copy them to the new dir
		if [ ! -e "$f" ]; then
			touch "$f" 
		fi
	#4b.add datestamp to file	
		
		renamed_file="$d_name/$(basename "$f")_$timestamp"
		
		#no need to assign cp to a variable, VERY important to remember
	
		cp "$f" "$d_name/$(basename "$f")_$timestamp"
		
	done


	#4C -> logging files
    	for f in "${file_n[@]}"; do
        	renamed_file="$d_name/$(basename "$f")_$timestamp"
        	echo "Input file: $f -> Backup File: $renamed_file" >> "$log_file"
    	done

	#5 -> COMPLETION OF BACKUP
	echo "The Backup is now completed! You can see the files in :  '$d_name'"
	echo "The log file is located at '$log_file'."
}

check_parameters "$@"
