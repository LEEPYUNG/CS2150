#!/bin/bash
# 
#	Name: Pyung Lee
#	Email ID: pkl4fr
#	Date: 3/3/2020
#	File Name: averagetime.sh




#Read in dictionary + grid
read dictionary 
read grid

#calculate run times
RUNNING_TIME1=`./a.out $dictionary $grid | tail -1`
RUNNING_TIME2=`./a.out $dictionary $grid | tail -1`
RUNNING_TIME3=`./a.out $dictionary $grid | tail -1`
RUNNING_TIME4=`./a.out $dictionary $grid | tail -1`
RUNNING_TIME5=`./a.out $dictionary $grid | tail -1`


#sum them all up. 

echo $RUNNING_TIME1
echo $RUNNING_TIME2
echo $RUNNING_TIME3
echo $RUNNING_TIME4
echo $RUNNING_TIME5

#calculating sums using bc
sum1=`echo $RUNNING_TIME1 + $RUNNING_TIME2 | bc`
sum2=`echo $RUNNING_TIME3 + $RUNNING_TIME3 | bc`
sum3=`echo $sum1 + $sum2 | bc`
total=`echo $sum3 + $RUNNING_TIME5 | bc`

echo $total

#find average
num=5
average=`echo $total/$num | bc -l`

#print out average
echo "The average time in millisceconds: "
echo $average

