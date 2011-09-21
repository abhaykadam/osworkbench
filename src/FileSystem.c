#include "includes.h"

FileSystem* init_FileSystem()
{
	char log_data[100];
	int errsv;
	FileSystem* FS = (FileSystem*) malloc (sizeof (FileSystem));
	if (FS==NULL)
	{
		errsv = errno;
		printf ("malloc failed.");
		strerror (errsv);
	}
	FS->dummy = 100;
	sprintf (log_data,"FILESYSTEM INIT.\n");
	logging (log_data);
	return FS;
}
