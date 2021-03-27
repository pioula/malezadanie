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
    echo -n "TEST $f ";
    time($PROGRAM < "$f" > $OUT 2> $ERR;)
    if diff "${f%in}out" "$OUT" >diff.diff && diff "${f%in}err" "$ERR" >diff.diff;
    then
        echo "PASSED";
    else
        echo "FAILED";
    fi;
done;