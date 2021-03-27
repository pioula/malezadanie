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
    $PROGRAM < "$f" > $OUT 2> $ERR;
    echo -n "TEST $f ";
    if diff "${f%in}out" "$OUT" && diff "${f%in}err" "$ERR";
    then
        echo "PASSED";
    else
        echo "FAILED";
    fi;
done;