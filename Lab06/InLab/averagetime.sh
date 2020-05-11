#!/bin/bash

#	Name: Pyung Lee
#	Email ID: pkl4fr
#	Date: 3/3/2020
#	File Name: averagetime.sh

#Read in dictionary + grid
read dictionary 
read grid

#save running times and calcualte average
SUM=0;

#calculate run times
RUNNING_TIME1 = './a.out $dictionary $grid | tail -1'
SUM = 'expr $SUM+$RUNNING_TIME1'

RUNNING_TIME2 = './a.out $dictionary $grid | tail -1'
SUM = 'expr $SUM+$RUNNING_TIME2'
RUNNING_TIME3 = './a.out $dictionary $grid | tail -1'
SUM = 'expr $SUM+$RUNNING_TIME3'

RUNNING_TIME4 = './a.out $dictionary $grid | tail -1'
SUM = 'expr $SUM+$RUNNING_TIME4'

RUNNING_TIME5 = './a.out $dictionary $grid | tail -1'
SUM = 'expr $SUM+$RUNNING_TIME5'

average = 'expr $SUM/5'

#print out average
echo "The average time in millisceconds: "
echo $SUM

