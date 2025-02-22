#!/bin/bash

# Problem 1:
echo "Welcome to the game"
echo "Please enter your name"
read user_name
name=$user_name

echo "Hello $name! Would you like to start now?"
echo "[y] / [n]"
read start_election

# Checks whether the user inserted y or n
# Explaining rules
# 3a. Rock beats scissors (by crushing them).
# 3b. Scissors beat paper (by cutting it).
# 3c. Paper beats rock (by covering it).

if [ $start_election = "y" ]; then
    echo "Alright! Let's start by setting up some rules"
    echo "Rule a: Rock beats scissors (by crushing them)"
    echo "Rule b: Scissors beat paper (by cutting it)"
    echo "Rule c: Paper beats rock (by covering it)"

    #Enter selection of rock, scissor, paper
    echo "Are we clear?"
    echo "[y] / [n]"
    read election2

    if [ $election2 = "y" ]; then
        echo "Alright! Then your turn! Which one would you like to choose?"
        read game_choice

        #checks if they are all lowercase
        while [[ $game_choice =~ [A-Z] ]]; do
	echo "Please write everything in lowercase"
            read game_choice
        done

        echo "Okay! Now it is my turn!"
	
        #5 Computer selection Random generator
        #Create an array that will store rock, scissors, paper string
        options=(rock scissors paper)
        computer_turn="${options[$(( RANDOM % 3 ))]}"
        echo "I choose: $computer_turn"

	#tie scenario
        if [[ $computer_turn == $game_choice ]]; then
            echo "It's a tie, try again ;("
            read game_choice
            echo "I choose: $computer_turn"
	fi


        if [[ $computer_turn == "scissors" && $game_choice == "paper" ]]; then
            echo "Scissors beat paper, I win"
	elif [[ $computer_turn == "rock" && $game_choice == "scissors" ]]; then
            echo "Rock beats scissors, I win"
        elif [[ $computer_turn == "paper" && $game_choice == "rock" ]]; then
            echo "Paper beats rock, I win!"
		
        else
            echo "You win! Yay!"
        fi
    else
        echo "It is fine! I will explain those rules again!"
        echo "Rule a: Rock beats scissors (by crushing them)"
        echo "Rule b: Scissors beat paper (by cutting it)"
        echo "Rule c: Paper beats rock (by covering it)"
    fi
else
    echo "It is alright! Let us know when you are ready!"
fi
