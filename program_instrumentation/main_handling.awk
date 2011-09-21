BEGIN{main_prototype=""; modified_main=sprintf ("main_p%d",var);}
{
	if (match ($0 , /[^a-zA-Z0-9\_]main[ \t]*\(/) != 0)
	{
		ret_type = substr ($0,1,RSTART);
		if (ret_type !~ /[a-zA-Z]/)
		{
			ret_type = prev_line;
		}
		main_prototype = sprintf ("%smain()",ret_type);
		sub (/main/,modified_main,main_prototype);
		split ($0,arr,"{");
		if (length(arr) > 1)
		{
			printf ("%s{%s\n",main_prototype,arr[2]);
		}
		else
		{
			printf ("%s",main_prototype);
		}
	}
	else
		printf ("%s\n",$0);
	prev_line=$0;
}
