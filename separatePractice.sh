#!/bin/bash
dirHW1=~/HW1/HW1/
dirOut=~/testCycu/

for file in $(grep -ls '#cycu' $dirHW1/cycu*| awk -F"/" '{print $NF}')
do
        grep -Eh '^[^#]+$' $dirHW1/$file > $dirOut/$file
        cp $dirHW1/$file $dirOut/$file.old
done
