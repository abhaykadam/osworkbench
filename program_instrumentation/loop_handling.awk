BEGIN {counter=0; start=0;condition=0}
{
	if ($0 ~ /^@.*/)
	{
		printf ("%s\n",$0);
	}
	else
	{
		if ( (match ($0, /^for[ \t\n]*\(|[ \t\n][ \t\n]*for[ \t\n]*\(/) !=0 && start==0) || start == 1)
		{
			printf ("@@%s@@ RSTART:%d REND:%d@@\n",$0,RSTART, RSTART+RLENGTH-1 );
			str = substr ($0,RLENGTH);
#			start = 1;
#			for (i=1;i<=length($0);i++)
#			{
#				ch = substr ($0,i,1);
#				if (ch ~ /\(/)
#					counter++;
#				else if (ch ~ /\)/)
#					counter--;
#				if (counter == 0)
#				{
#					start=0;
#					printf ("@%s\n%s",substr ($0,1,i),substr ($0,i+1));
#				}
#			}
		}
		else
		{
			printf ("%s\n",$0);
		}
	}
}
