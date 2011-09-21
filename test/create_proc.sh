#!/bin/bash

#mkdir proc

#for ((i=1;i<=10;i++))do for((j=0;j<1000;j++))do echo "NOP_$j";done>proc/proc_$i; done

for ((i=1;i<=10;i++))do for ((j=1;j<=10;j++))do page=`expr $RANDOM % 12`; echo "access `expr $page + 1` $RANDOM"; done > proc/proc_$i; done
