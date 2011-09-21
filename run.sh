#!/bin/sh

###################################################
#					This script runs the work bench OS
#					Parameteres: OS_specfile, OS_Initfile, type - demo/instrumented,
##################################################

export OSHOME=`pwd`
echo "" > $OSHOME/src/C_process.h
if [ $# -lt 3 ]
then
	echo "ERROR IN INPUT. FORMAT: outfile <OSSpecfile> <OSInitile> <demo/instrumented>"
	exit
fi

	rm $OSHOME/src/outfile
	rm $OSHOME/outfile
	echo "#define MAIN_PROCESS_C ;" >  $OSHOME/src/C_process_init.h
	echo "#define INIT_PROCESS_C ;" >  $OSHOME/src/C_process_main.h

#cp $OSHOME/src/outfile .
osspecfile=$1
osinitfile=$2
exectype=$3

if [ $exectype = "demo" ]
then
	echo "Make the executable"
	cd $OSHOME/src
	make clean
	make
	echo "Execution with dummy code"
	echo "*************************"
	mv $OSHOME/src/outfile $OSHOME/
	cd -
	echo "Press any key to start execution. execution command: ./outfile $osspecfile $osinitfile $exectype"
	read x
	./outfile $osspecfile $osinitfile $exectype
	exit
fi

if [ $exectype != "instrument" ]
then 
	echo "Unknown type of execution. vaild: demo/instrument"
	exit
fi

echo "INSTRUMENTING PROGRAMS "

#Buildng the switch cases for the processes
echo "#define INIT_PROCESS_C switch (proc_id){\\" > $OSHOME/src/C_process_init.h
echo "#define MAIN_PROCESS_C switch (proc_id){\\" > $OSHOME/src/C_process_main.h


echo "#!/bin/sh" > $OSHOME/src/gcc_link.sh
echo -n "gcc -o outfile" >> $OSHOME/src/gcc_link.sh
i=1
IFS="
"
#READ OSINIT FILE AND INSTRUMENT THEM
for line in `cat $osinitfile`;do
 filename=`echo $line | cut -d ' ' -f 2`
 cp $filename $OSHOME/program_instrumentation/test.c
 cd $OSHOME/program_instrumentation

 ./demo.sh test.c $i
 gcc -c new_file.c -o new_file
 if [ $? != 0 ]
 then
 	echo "Program has some errors. Exiting OS"
 	exit
 else	
 	echo "COPYING FILE TO SRC DIR"
 	cp new_file.c $OSHOME/src/test_$i.c
 	echo -n " test_$i.c" >> $OSHOME/src/gcc_link.sh
 	
 	echo "case $i:\\" >> $OSHOME/src/C_process_init.h
 	echo "init_p$i (VMachine->scheduler);\\" >> $OSHOME/src/C_process_init.h
	echo "break;\\" >> $OSHOME/src/C_process_init.h
	
	echo "case $i:\\" >> $OSHOME/src/C_process_main.h
	echo "main_p$i ();\\">> $OSHOME/src/C_process_main.h
	echo "break;\\" >> $OSHOME/src/C_process_main.h
	
 	rm new_file.c
 	main_prototype=`cat $OSHOME/src/test_$i.c | awk -v var=$i 'BEGIN{regex1=sprintf("main_p%d",var);}{if ($0 ~ regex1){ split($0,arr,"{"); printf ("%s\n",arr[1]);}}'`
 	echo "$main_prototype;" >> $OSHOME/src/C_process.h
  echo "void init_p$i (Scheduler* s);" >> $OSHOME/src/C_process.h
 	i=`expr $i + 1`
 fi
 cd -
done

echo "} " >> $OSHOME/src/C_process_init.h
echo "} " >> $OSHOME/src/C_process_main.h
 
#gedit $OSHOME/src/C_process_init.h $OSHOME/src/C_process_main.h
echo "Finished Instrumentation"
echo "Recompiling source and processes."
cd $OSHOME/src
	make clean
	rm libworkbench.a
	make build_ar
echo "Building executable."
echo -n " libworkbench.a -lrt -lpthread" >> $OSHOME/src/gcc_link.sh
chmod +x $OSHOME/src/gcc_link.sh
./gcc_link.sh
if [ $? != 0 ]
then
 	echo "Program has some errors. Exiting OS"
 	exit
fi

cd $OSHOME

mv $OSHOME/src/outfile $OSHOME/
i=`expr $i - 1`
echo "Press any key to start execution. Execution command in $OSHOME : ./outfile $osspecfile $osinitfile $exectype $i"
read x

./outfile $osspecfile $osinitfile $exectype $i
