#!/bin/bash
# 
#	Name: Pyung Lee
#	Email ID: pkl4fr
#	Date: 3/27/2020
#	File Name: averagetime.sh

echo "Enter exponent for counter.cpp: "
read exp

str="quit"
if [ "$exp" == "str" ]
then
    exit 0
fi

count=5
totalTime=0

for ((i = 1; i <= count; i++))
do
    echo "Running iteration $i..."
    time=`./a.out ${exp}`
    echo "time taken: ${time} ms"
    totalTime=`expr $totalTime + $time`
done 

echo "5 iterations took ${totalTime} ms"
averageTime=`expr $totalTime / 5`
echo "Average time was $averageTime ms"





