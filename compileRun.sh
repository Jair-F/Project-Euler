#!/bin/bash

# This bash-script will compile the given C++-File, run it, show the time the C++-Program took to run and will delete afterwards the compiled binary-file

# bash test operators: https://kapeli.com/cheat_sheets/Bash_Test_Operators.docset/Contents/Resources/Documents/index

if [ $# -lt 1 ]; then
	echo "Description:"
	echo "This bash-script will compile the given C++-File, run it, show the time the C++-Program took to run and will delete afterwards the compiled binary-file"
	echo "$0 cpp-File"
fi
SOURCE_FILE=$1

echo "Compiling \"$SOURCE_FILE\""

clear
g++ -O3 "$1" -o a.out && time ./a.out && rm a.out