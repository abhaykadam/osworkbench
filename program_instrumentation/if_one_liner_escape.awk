BEGIN{start=0; str=""}
{
	if ($0 ~ /^@.*/)
	{
		printf ("%s\n",$0);
	}
	else if (start == 1)
	{
		if (match ($0,/^[ \t\n]*else/) != 0) #else is there after one liner if.
		{
			printf ("%s%s\n",str,$0);
		}
		else
		{
			printf ("%s\n%s",str,$0);
		}
		str="";
		start = 0;
	}
	else if (match ($0,/[ \t\n][ \t\n]*if[ \t\n]*\(/)!= 0) #line contains if condtion
	{
		#printf ("##%s\n",$0);
		str1 = substr ($0,RSTART);
		if (match (str1,/{/)== 0) #this is a one liner if with no braces
		{
			str = sprintf ("%s%s",str,$0);
			start = 1;
			#printf ("BRACE NOT FOUND IN $$$%s$$$ line_number:%d N R:%d\n",str,line_number,NR);
			if (line_number==NR)
			{
				printf ("%s\n",str);
			}
		}
		else
			printf ("%s\n",$0);
	}
	else
	{
		printf ("%s\n",$0);
	}
}
