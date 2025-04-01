#!/bin/bash


# So, first, we're gonna ask for a directory name
echo "Enter the directory name:"
read dir_name

# Now, let's check if the directory exists
if [ -d "$dir_name" ]; then
    cd "$dir_name" || exit
    echo "Alright, you're now inside $dir_name."
else
    # If not, ask if they want to create it
    echo "Directory doesn't exist. Do you wanna create it? (yes/no)"
    read create_dir
    if [ "$create_dir" == "yes" ]; then
        mkdir "$dir_name"
        cd "$dir_name" || exit
        echo "Directory $dir_name created, and now you're in it."
    else
        # If they don't want to create it, just exit
        echo "Exiting now."
        exit 1
    fi
fi

# Time to list files and directories
while true; do
    echo "Here's what's in $dir_name:"
    ls -p
    echo "Pick a file or subdirectory to open, or type 'exit' to quit:"
    read selection

    # If they type 'exit', we just exit
    if [ "$selection" == "exit" ]; then
        echo "Exiting."
        exit 0
    fi

    # If it's a file, show the first 10 lines
    if [ -f "$selection" ]; then
        echo "Here are the first 10 lines of $selection:"
        head -n 10 "$selection"
        
        # Track the current line we showed
        line_num=10
        
        # Now, let's ask if they wanna see more
        while true; do
            echo "Wanna see more? (yes/no)"
            read response
            if [ "$response" == "yes" ]; then
                # Show the next 10 lines
                tail -n +$line_num "$selection" | head -n 10
                # Increment the line number for the next chunk
                line_num=$((line_num + 10))
            elif [ "$response" == "no" ]; then
                break
            else
                echo "Please type 'yes' or 'no'."
            fi
        done

    # If it's a directory, let's navigate inside and do some searching
    elif [ -d "$selection" ]; then
        cd "$selection" || continue
        echo "You're now inside $selection."

        # Search for files modified in the last 24 hours
        echo "Searching for files modified in the last 24 hours:"
        find . -type f -mtime -1 -print

        # Ask which file they want to view
        echo "Pick a file from the results:"
        read file_selected

        # If the file exists, show the first 10 lines
        if [ -f "$file_selected" ]; then
            echo "Here are the first 10 lines of $file_selected:"
            head -n 10 "$file_selected"

            # Track the current line we showed
            line_num=10

            # Ask if they wanna see more lines
            while true; do
                echo "Wanna see more? (yes/no)"
                read response
                if [ "$response" == "yes" ]; then
                    # Show the next 10 lines
                    tail -n +$line_num "$file_selected" | head -n 10
                    # Increment the line number for the next chunk
                    line_num=$((line_num + 10))
                elif [ "$response" == "no" ]; then
                    break
                else
                    echo "Please type 'yes' or 'no'."
                fi
            done
        else
            echo "Invalid file selection."
        fi

        # Back to the main directory
        cd ..

    else
        echo "That's not a valid file or subdirectory. Try again."
    fi
done

