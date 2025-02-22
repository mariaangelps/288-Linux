#!/bin/bash

#Problem 2: 

function check_parameters(){
	#check if there is an argument or not by using $1, which is the 1st 	    command line argument
	if [ -n "$1" ]; then
		argument="$1"
	else
		echo "No given argument"
	fi
	
	#IF IT IS A DIRECTORY
	if [ -d "$argument" ]; then
		echo "The argument given is a directory"
		#3A. check permissions
		if [ -r "$argument" -a -x "$argument" ]; then
		       	echo "The directory has read and execute permission"
			echo 

			#3B. COUNTING DIRECTORIES AND FILE

			#count directories with wc -l because we are
			#counting how many lines we are printing,and each
			#line will have the directory path
		  	
			count_d=$(ls -d "$argument"/*/ | wc -l)
		       	echo 
			echo "number of sub-directories: $count_d"
		      
		       #COUNTING FILES

                       #-p option means append / indicator to directories
                       #this will help us to identify a directory and then later on remove it by identifying the slash using the grep -v command, as well as counting each line of the output used as the input of wc-l
                       count_f=$(ls -p "$argument" |grep -v / | wc -l)
                       echo "number of files: $count_f"


		       #3C. list subdirectories
		       	list_d=$(ls -d "$argument"/*/)
			echo
	 		echo "The subdirectories are the following: $list_d"
		       
			#size of subdirectories using du command, it usally prints the disk usage in the shell
			size_d=$(du -sh "$argument"/*/)
			echo "The size of the subdirectories are: $size_d"	
	      
		       #list files
                       list_f=$(ls -p "$argument" | grep -v /)
		       echo "The files inside the directory are the following: $list_f"     

		       #size of files  using du command, it usally prints the disk usage in the shell
	       	       for f in "$argument"/*; do
	      		       if [ -f "$f" ]; then
                                        size_f=$(du -sh "$f" | cut -f1)
                                        echo "The size of the file $f is: $size_f"
			       fi
		       done
	
	        else 
		       echo "Warning! The directory does not have read and execute permissions"
		fi

	#IF IT IS A FILE	
		
	elif [ -f "$argument" ]; then
		echo "The argument given is a file"
		#Check for permissions
		if [ -r "$argument" -a -x "$argument" ]; then
			echo "The file has read and execute permission"

		#Determine word count, line count and character
		#< change standard input to a command
			words=$(wc -w < "$argument")
			echo "Word count: $words"
			char=$(wc -m < "$argument")
			echo "Character Count: $char"
			line=$(wc -l < "$argument")
			echo "Line count: $line"
	
		
		#based on char count
			if [ "$char" -gt 10000 ]; then
				tag1="Text Heavy"
				echo "The file is $tag1"
			elif [ "$char" -gt 1000 ]; then
				if [ "$char" -lt 10000 ]; then
					tag2="Moderately Sized"
					echo "The file is $tag2"
				fi
			elif [ "$char" -lt 1000 ]; then
				tag3="Light file"
				echo "The file is a $tag3"
			else
				echo "No tag for these word count"


			fi
		
		else
			echo "Warning! The File does not have permissions"
		fi 

	else 
		echo "Incorrect input!"
	fi


}

#calling function
check_parameters "$1"
