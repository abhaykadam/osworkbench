BEGIN {counter=0;str="";}
	{
		if ($0 ~ /^@.*/)
		{
			printf ("%s\n",$0);
		}
		else if (counter>=0 && $0 ~ /[ \t\n][ \t\n]*for[ \t\n]*\(/)
		{
			printf ("%scc(sched,%d);\n",$0,pid);
			split ($0,array_open,"{");
			counter += length (array_open);
			split ($0,array_close,"}");
			counter -= length (array_close);
		}
		else
		{
			for (i=1;i<=length($0);i++)
			{
				ch = substr($0,i,1);
				if (ch ~ /{/)
					counter++;
				else if (ch ~ /}/)
					counter--;
				
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
					if (ch ~ /;/)
					{
						if (match (str,/[ \t\n][ \t\n]*if[ \t\n]*\(/) != 0)
						{
							str1 = substr ($0,i+1);
							
							if (match  (str1,/^[ \t\n]*else/) != 0) # this ; is followed by an else no cc() is to be added.
							{
								printf ("%s",str);
							}
							else
							{
								str = sprintf ("%scc(sched,%d);",str,pid);
								printf ("%s%s\n",str1,str);
							}
						}
						else if (match (str, /[a-zA-Z\_][a-zA-Z0-9\_]*[ \t\n]*\(/) != 0)
						{
							printf ("%scc(sched,%d);\n",str,pid);
						}
						else if (match (str, /=/)!=0) #line has a = sign.
						{
							printf ("%scc(sched,%d);\n",str,pid);
						}
						else
							printf ("%s\n",str);
						str="";
					}
				}
			}
		}
	}
