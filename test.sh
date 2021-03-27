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
    $PROGRAM < "$f" > 1.out;
    $PROGRAM < "$f" 2> 1.err;
    echo "TEST $f ";
    if diff "${f%in}out" 1.out;
    then
        echo "PASSED";
    else
        echo "FAILED";
    fi;
done;