#!/bin/bash

echo How many objects would you like to add?
read -a line
num=${line[0]}
echo Enter configuration of your setup, e.g. \"line circle rectangle\"
read -a line
for ((i=0;i<$num;i++))
do
   choice[$i]=${line[i]}
done

touch project_instructions.cpp
echo \#include \"project_header.h\" > project_instructions.cpp
echo boundary instructions\(int mesh[N][N]\) >> project_instructions.cpp
echo { >> project_instructions.cpp
echo boundary boundary1\(mesh\)\; >> project_instructions.cpp
for ((i=0;i<$num;i++))
do
    echo Object number $i
    if [[ ${choice[$i]} == 'line' ]]; then
	echo Requesting line parameters:
	echo Column
	read -a line
	col=${line[0]}
	echo Row
	read -a line
	row=${line[0]}
	echo Start
	read -a line
	start=${line[0]}
	echo Choice
	read -a line
	choice=${line[0]}
	echo boundary1.line_column\($col\)\; >> project_instructions.cpp
	echo boundary1.line_row\($row\)\; >> project_instructions.cpp
	echo boundary1.line_start\($start\)\; >> project_instructions.cpp
	echo boundary1.line_choice\($choice\)\; >> project_instructions.cpp
	echo boundary1.line\(\)\; >> project_instructions.cpp
    elif [[ ${choice[$i]} == 'circle' ]]; then
	echo Requesting circle parameters:
	echo X-origin
	read -a line
	xo=${line[0]}
	echo Y-origin
	read -a line
	yo=${line[0]}
	echo Radius
	read -a line
	radius=${line[0]}
	echo boundary1.circle_x_origin\($xo\)\; >> project_instructions.cpp
	echo boundary1.circle_y_origin\($yo\)\; >> project_instructions.cpp
	echo boundary1.circle_radius\($radius\)\; >> project_instructions.cpp
	echo boundary1.circle\(\)\; >> project_instructions.cpp
    elif [[ ${choice[$i]} == 'rectangle' ]]; then
	echo Requesting rectangle parameters:
	echo X-origin
	read -a line
	xor=${line[0]}
	echo Y-origin
	read -a line
	yor=${line[0]}
	echo Height
	read -a line
	h=${line[0]}
	echo Width
	read -a line
	w=${line[0]}
	echo boundary1.rectangle_x_origin\($xor\)\; >> project_instructions.cpp
	echo boundary1.rectangle_y_origin\($xor\)\; >> project_instructions.cpp
	echo boundary1.rectangle_height\($h\)\; >> project_instructions.cpp
	echo boundary1.rectangle_width\($w\)\; >> project_instructions.cpp
	echo boundary1.rectangle\(\)\; >> project_instructions.cpp
    elif [[ ${choice[$i]} == 'point' ]]; then
	echo Requesting point parameters:
	echo X-origin
	read -a line
	pxo=${line[0]}
	echo Y-origin
	read -a line
	pyo=${line[0]}
	echo boundary1.point_x_origin\($pxo\)\; >> project_instructions.cpp
	echo boundary1.point_y_origin\($pyo\)\; >> project_instructions.cpp
	echo boundary1.point\(\)\; >> project_instructions.cpp
    fi
done
echo "return boundary1;" >> project_instructions.cpp
echo } >> project_instructions.cpp 
gedit project_instructions.cpp &
make project
./project 2 
gedit project_instructions.cpp
