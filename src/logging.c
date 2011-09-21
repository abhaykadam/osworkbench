/*
	This file contains logging details
*/
#include "includes.h"

void fileWrite ()
{
	FILE* fp;
	int len;
	if ((fp=fopen ("LOG.txt","a+"))==NULL)
	{
		printf ("Log file can not be opened. %s\n",strerror(errno));
	}
	len = strlen (log_buffer);
	fwrite(log_buffer, len, 1, fp);
	bzero (log_buffer,len);
	fclose(fp);
}

//Function for logging
void logging (char* log_data)
{
	printf (log_data);
	if (strlen(log_buffer) >= 9000)
		fileWrite ();
	//memmove (log_buffer,log_data,strlen(log_data));
	sprintf (log_buffer,"%s%s",log_buffer,log_data);
}

void kill_handler (int signum)
{
	printf ("CATCHED:%s\n",strsignal(signum));
	fileWrite();
	printf ("Wait for a while. writing buffered data to log\n");
	usleep (10000);
	exit (EXIT_SUCCESS);
}
