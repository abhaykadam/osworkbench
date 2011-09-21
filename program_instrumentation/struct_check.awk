BEGIN {counter=0;start=0;str="";}
	{
		if ($0 ~ /@.*/)
		{
			printf ("%s\n",$0);
		}
		else
		{
			if ($0 ~ /.*struct.*/)
			{
				if (start == 0)
				{
					start = 1;
				}
			}
			else if (start == 0)
				printf ("%s\n",$0);
			if (start == 1)
			{
				if ($0 ~ /#.*/)
					str = sprintf ("%s\n@%s\n@",str,$0);
				else
				{
					for (i=1;i<=length;i++)
					{
						ch = substr($0,i,1);
						str = sprintf ("%s%c",str,ch);
						if (counter==0 && ch ~ /;/)
						{
							start = 0;
							printf ("%s\n",str);
							str="";
						}
						if (ch ~ /{/)
						{
							counter++;
						}
						else if (ch ~ /}/)
						{
							counter--;
							if (counter == 0)
							{
								start = 0;
								finish = 1;
								printf ("@%s\n",str);
								str="";
							}
						}
					}
				}
			}
		}
	}
