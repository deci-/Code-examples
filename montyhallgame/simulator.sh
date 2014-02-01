#!/bin/bash

#A simulator for Monty Hall game by Paulius Vaitkunas. One full simulation simulates the actual game twice: 
#once with answer 'yes' #and once with answer 'no' to and when it finishes the simulation it prints out the results 
#from both cases and asks if you want to #run the simulation again. The c program exits with 0 if you win a car 
#and with 1 if you win a goat and the shell script counts these #exit statuses. 

carcounter=0
goatcounter=0
answer=0

echo You have started a Monty Hall Game simulator'!'
while [ $answer != 'n' ]; do
	echo How many 'times' would you like me to me to simulate the game?
	read -a line
	numberofsimulations=${line[0]}
	for (( c=1; c<=$numberofsimulations; c++ )) do
		echo The number of simulation':'  $c out of $numberofsimulations
		./monty 1 no
		if [[ $? -eq 0 ]]; then
			let carcounter=$(( $carcounter + 1 ))
		elif [[ $? -eq 1 ]]; then
			let goatcounter=$(( $goatcounter + 1 ))
		fi
	done
	
	for (( d=1; d<=$numberofsimulations; d++ )) do
		echo The number of simulation':'  $d out of $numberofsimulations
		./monty 1 yes
		
		if [[ $? -eq 0 ]]; then
			let carcounter1=$(( $carcounter1 + 1 ))
		
		elif [[ $? -eq 1 ]]; then
			let goatcounter1=$(( $goatcounter1 + 1 ))
		fi
	
	done
	let x=$(( $c - 1 ))
	let y=$(( $d - 1 ))
	echo I have simulated the game 'for' $numberofsimulations 'times'. I have obtained these results':'
	echo '***************************************************************************'
	echo '*'You have won a goat 'for' $goatcounter 'times' out of $x when you chose not to switch
	echo '*'You have won a car 'for' $carcounter 'times' out of $x when you chose not to switch
	echo '*'-------------------------------------------------------------------------'*'
	echo '*'You have won a goat 'for' $goatcounter1 'times' out of $y when you chose to switch
	echo '*'You have won a car 'for' $carcounter1 'times' out of $y when you chose to switch
	echo '***************************************************************************'
	echo Would you like me to simulate the game again '(y/n)'?
	read -a line
	answer=${line[0]}
	goatcounter=0
	goatcounter1=0
	carcounter=0
	carcounter1=0
done

