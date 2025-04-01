#!/bin/bash 

function looking_lines(){
	
	file=$1
	#searches for words "scanf" or "printf"
	 grep -E 'scanf|printf' "$file"
	#counts number of lines containing scanf and printf separetly 
	echo "Number of lines for scanf:" 
	grep -E 'scanf' "$file" | wc -l
	echo "Number of lines for prinf: "
       	grep -E 'printf' "$file" | wc -l
	
	#redirects the lines containing “scanf” to a new file named scanf_log.txt and the lines
	#containing “printf” to a new file named printf_log.txt.
	lines=$(grep -E 'scanf' "$file" | wc -l)
       	echo "scanf: $lines" > scanf_log.txt
	lines_printf=$(grep -E 'printf' "$file" | wc -l)
       	echo "printf: $lines_printf" > printf_log.txt

	#append
	if [ -e scanf_log.txt ] && [ -e  printf_log.txt ]; then 
		grep -E 'scanf' "$file" >> scanf_log.txt	
		grep -E 'printf' "$file" >> printf_log.txt
	fi
	

	#number of lines in the input file and % of lines containing scanf and printf
	total_lines=$(wc -l <"$file")
	
	if [ "$total_lines" -eq 0 ]; then
       		percent_scanf=0
        	percent_printf=0
   	 else
        	percent_scanf=$(( 100 * lines / total_lines ))
        	percent_printf=$(( 100 * lines_printf / total_lines ))
   	fi

	echo "Total lines in file: $total_lines"
	echo "Percentage for printf: $percent_printf"
	echo "Percentage for scanf: $percent_scanf"

}	
looking_lines "sample.c"
