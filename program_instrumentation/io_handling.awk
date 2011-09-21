BEGIN {counter=0;str="";}
{
	if (match ($0,/[^a-zA-Z0-9]printf[ \t]*\([^;]*;/)!=0)
	{
		str1 = substr ($0,1,RSTART);
		if (str1 ~ /[a-zA-Z0-9\_)\*][ \t][ \t]*$/)
			printf ("%s\n",$0);
		else
		{
			str2 = substr ($0,RSTART+1,RLENGTH-1);
			str3 = substr ($0,RSTART+RLENGTH);
			printf ("%s\n	io_start_instrumented(sched,%d);\n%s\nio_end_instrumented(sched,%d);%s\n",str1,pid,str2,pid,str3);
		}
	}
	else
	{
		printf ("%s\n",$0);
	}
}
