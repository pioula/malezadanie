#!/bin/bash

if (($# != 2))
then
    echo "Usage: $0 <program file> <path to directory with tests>" >&2
    exit 1
fi

OUT=$(mktemp);
ERR=$(mktemp);
PROGRAM=$1;
MYPATH=$2;

for f in $MYPATH/*.in;
do
    echo -n -e "\e[1m\e[94mTEST \e[0m$f ";
    time($PROGRAM < "$f" > $OUT 2> $ERR);
    echo $?;
    if diff "${f%in}out" "$OUT" >diff.diff && diff "${f%in}err" "$ERR";
    then
        echo -e "\e[1m\e[32mOK";
    else
        echo -e "\e[1m\e[31mFAILED";
    fi;

    echo -n -e "\e[94mValgrind test: ";
    if valgrind --error-exitcode=123 --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all $PROGRAM < "$f" &>/dev/null;
    then
        echo -e "\e[1m\e[32mOK";
    else
        echo -e "\e[1m\e[31mFAILED";
    fi;
    
done;