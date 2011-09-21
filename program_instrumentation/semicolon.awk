BEGIN {counter=0;str="";}
	{
		if ($0 ~ /^@.*/)
		{
			printf ("%s\n",$0);
		}
		else
		{
			for (i=1;i<=length;i++)
			{
				ch = substr($0,i,1);
				if (ch ~ /{/)
				{
					counter++;
				}
				else if (ch ~ /}/)
				{
					counter--;
				}
				
				if (counter == 0)
				{
					#if (match (str,/{/)!=0) #handles the case of empty function: void f() {}
					if (length (str)!=0)
					{
						printf ("%s%c\n",str,ch);
						str="";
					}
					else
					{
						printf ("%c",ch);
						if (i==length)
							printf ("\n");
					}
				}
				else if (counter > 0)
				{
					str = sprintf ("%s%c",str,ch);
					if ($0 !~ /.*for.*/ && ch ~ /;/)
					{
						printf ("%s\n",str);
						str="";
					}
				}
			}
		}
	}
