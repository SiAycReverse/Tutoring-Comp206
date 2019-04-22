#!/bin/bash
if [ ! -d ./backup ];
then
  mkdir ./backup
fi
cp *.c ./backup
cp *.h ./backup
