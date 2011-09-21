BEGIN {counter=0; str="";start=0}
{
	if ($0 ~ /^@.*/)
	{
		printf ("%s\n",$0);
	}
	else
	{
		for (i=1;i<=length($0);i++)
		{
			ch = substr ($0,i,1);
			if (ch ~ /\"/)
				counter++;
			if (counter % 2 == 1) #inside the double quote
			{
				str = sprintf ("%s%c",str,ch);
#				printf ("M");
#				if (start==0)
#					str = "";
#				str = sprintf ("%s%c",str,ch);
#				printf ("\n\"INSIDE \"\" str:%s$$",str);
				start = 1;
			}
			else
			{
				#printf ("%c",ch);
				if (start == 1)
				{
					
					gsub (/@/,"|@@@@|",str);
					gsub (/if/,"|i|f|",str);
					gsub (/for/,"|f|o|r|",str);
					gsub (/;/,"|||",str);
					gsub (/=/,"|@@@|",str);
					gsub (/struct/,"|s|t|r|u|c|t|",str);
#					
					printf ("%s\"",str);
				}
				else
				{
					printf ("%c",ch);
				}
				start = 0;
				str = "";
			}
		}
		printf ("\n");
	}
}
