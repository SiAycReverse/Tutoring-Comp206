#!/bin/bash

if [[ "$#" -ne "3" ]]; then
   echo "wrong number of arguments"
   exit 1
fi

# at least check for minimum two wildcards * ? []
if [[ -z `echo "$1" | grep "[\*|\?|\+|\[\]]"` ]]; then
   echo "Parameter 1 must have at least one wild card"
   exit 1
fi

grep "$2" $1 >> $3

exit 0