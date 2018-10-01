#!/bin/bash

a0=1
a1=2
a2=3
a3=4
a4=5
a5=4
a6=7
echo 4 
for j in {1..2}
do
    for i in {1..1500}
    do
        echo $(($a0 + $a1 * $i + $a2 * $i**2 + $a3 * $i**3 + $a4 * $i**4 + $a5 * $i**5 + $a6 * $i**6))
    done

    for i in {1..1500}
    do
        echo $RANDOM
    done
done
