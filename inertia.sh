#!/bin/bash
#BASH Shell script used along with intertia.cpp allows you to plot the crescent and create a file with datapoints used
echo 'How many points would you like to simulate (up to 5000)?'
read -a line
numberofsimulations=${line[0]}
echo 'Would you like to write the output 'in' a text file (y/n)?'
read -a line
if [[ ${line[0]} == 'y' ]]; then
    echo 'Enter file name (with .dat extension):'
    read -a line
    filename=${line[0]}
    touch $filename
    echo Requesting $numberofsimulations simulations from C++ program...
    /home/paulius/labs/part3/inertia $numberofsimulations $filename
    echo Finished simulating $numberofsimulations points!
    echo Would you like me to plot the points'(y/n)'?
    read -a line
    if [[ ${line[0]} == 'y' ]]; then
	echo Creating gnuplot source file...
	touch gnu_source
	echo Source file created!
	echo Enter the name of the output file '(with .eps extension)':
	read -a line
	post_file=${line[0]}
	echo set output \"$post_file\" > gnu_source
	echo set term postscript >> gnu_source
	echo set xrange[-10:10] >> gnu_source
	echo set yrange[-10:10] >> gnu_source
	echo set grid >> gnu_source
	echo unset key >> gnu_source
	echo plot \"$filename\" using 1:2 with points pointtype 1 >> gnu_source
	gnuplot "gnu_source"
	echo Removing gnuplot source file...
	rm -rf gnu_source
	echo 'Plot finished! Would you like to open it now(y/n)?'
	read -a line
	if [[ ${line[0]} == 'y' ]]; then
	    echo Opening $post_file
	    evince $post_file
	fi
    fi
elif [[ ${line[0]} == 'n' ]]; then
    echo Requesting $numberofsimulations simulations from C++ program...
    /home/paulius/labs/part3/inertia $numberofsimulations
    echo Finished simulating $numberofsimulations points!
fi
echo Remove plot and data files'(y/n)'?
read -a line
if [[ ${line[0]} == 'y' ]]; then
    rm -rf $filename
    rm -rf $post_file
    echo $filename and $post_file have been removed!
fi
echo Finished! Exiting now!
