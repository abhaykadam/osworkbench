#!/bin/sh

if [ $# -lt 2 ]
then
	echo "ERROR IN INPUT. FORMAT: outfile demo.sh <file to instrument> <process id for that program>"
	exit
fi

if [ -e new_file.c ]
then
	rm new_file.c
fi

process_id=$2

cat $OSHOME/src/queue.h > demo.c
head -n 82 $OSHOME/src/data_structures.h | grep -v "queue.h" >> demo.c
echo "#endif" >> demo.c

echo "Scheduler* sched; unsigned pid; Process* p;" >> demo.c
cat $1 >> demo.c
gcc -E demo.c > demo_E.c

i=1;
# Any correct nesting of struct, enum, union is supported
# Escape struct declaration
echo "demo_E.c -> demo_$i.c   using escape.awk"
cat demo_E.c | awk -f escape.awk > demo_$i.c
prev_i=$i
i=`expr $i + 1`
echo "demo_$prev_i.c -> demo_$i.c using struct_check.awk"
cat demo_$prev_i.c | awk -f struct_check.awk > demo_$i.c

prev_i=$i
i=`expr $i + 1`
# Escape union declaration.
echo "demo_$prev_i.c -> demo_$i.c using union_check.awk"
cat demo_$prev_i.c | awk -f union_check.awk > demo_$i.c

prev_i=$i
i=`expr $i + 1`
# Escape enum declaration
echo "demo_$prev_i.c -> demo_$i.c using enum_check.awk"
cat demo_$prev_i.c | awk -f enum_check.awk > demo_$i.c

prev_i=$i
i=`expr $i + 1`
# Handle function prototypes
echo "demo_$prev_i.c -> demo_$i.c using handle prototype"
cat demo_$prev_i.c | sed 's/\([a-zA-Z0-9\_][a-zA-Z0-9\*\_]*[ \t\n][ \t\n]*[a-zA-Z0-9\*\_][a-zA-Z0-9\_]*[ \t\n]*([^;{]*;\)/\n@\1\n/g' > demo_$i.c

prev_i=$i
i=`expr $i + 1`
# For every statement inside function place a new line after every ;. Takes care of the struct declaration.
echo "demo_$prev_i.c -> demo_$i.c using semicolon.awk"
cat demo_$prev_i.c | awk -f semicolon.awk > demo_$i.c

prev_i=$i
i=`expr $i + 1`
echo "demo_$prev_i.c -> demo_$i.c using if_one_liner_escape.awk"
line_num=`wc -l demo_$prev_i.c | cut -d ' ' -f 1`
cat demo_$prev_i.c | awk -v line_number=$line_num -f if_one_liner_escape.awk > demo_$i.c

prev_i=$i
i=`expr $i + 1`
echo "demo_$prev_i.c -> demo_$i.c using put_function.awk"
cat demo_$prev_i.c | awk -v pid=$process_id -f put_function.awk > demo_$i.c

prev_i=$i
i=`expr $i + 1`
echo "demo_$prev_i.c -> demo_$i.c Handling the io start and io end requests."
#Handle IO start and end requests.
cat  demo_$prev_i.c | awk -v pid=$process_id -f io_handling.awk > demo_$i.c

#exit

prev_i=$i
i=`expr $i + 1`
echo "demo_$prev_i.c -> demo_$i.c using deleting @s"
cat demo_$prev_i.c | sed 's/^@\(.*\)/\1/' > demo_$i.c

prev_i=$i
i=`expr $i + 1`
echo "demo_$prev_i.c -> demo_$i.c using resuming escaped quoted if s."
cat demo_$prev_i.c | sed 's/|i|f|/if/g' > demo_$i.c

prev_i=$i
i=`expr $i + 1`
echo "demo_$prev_i.c -> demo_$i.c using resuming escaped quoted for s."
cat demo_$prev_i.c | sed 's/|f|o|r|/for/g' > demo_$i.c

prev_i=$i
i=`expr $i + 1`
echo "demo_$prev_i.c -> demo_$i.c using resuming escaped quoted ; s."
cat demo_$prev_i.c | sed 's/|||/;/g' > demo_$i.c

prev_i=$i
i=`expr $i + 1`
echo "demo_$prev_i.c -> demo_$i.c using resuming escaped quoted = s."
cat demo_$prev_i.c | sed 's/|@@@|/=/g' > demo_$i.c

prev_i=$i
i=`expr $i + 1`
echo "demo_$prev_i.c -> demo_$i.c using resuming escaped quoted struct s."
cat demo_$prev_i.c | sed 's/|s|t|r|u|c|t|/struct/g' > demo_$i.c


prev_i=$i
i=`expr $i + 1`
echo "demo_$prev_i.c -> demo_$i.c changes the name of the main funcion."
#Change the name of the main function
cat demo_$prev_i.c | awk -v var=$process_id -f main_handling.awk > demo_$i.c


prev_i=$i
i=`expr $i + 1`
echo "demo_$prev_i.c -> demo_$i.c adding pthread mutex unlock statement for mutex2."
#add pthread_mutex unlock
cat  demo_$prev_i.c | sed "s/\(main_p$process_id[^{]*{\)/\1pthread_mutex_unlock (\&mutex2);/" > demo_$i.c

echo "void init_p$process_id (Scheduler* s) {sched=s;}" >> demo_$i.c


cp demo_$i.c new_file.c

echo "Deleting temp files."
for (( j=1;j<=$i;j++ ))
do
	rm demo_$j.c
done

