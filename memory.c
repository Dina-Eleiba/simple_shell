#include "shell.h"

/**
* deallocateBuffer - function that free buffer
* @buffer: the buffer need to be freed
*/

void deallocateBuffer(char **buffer)
{
	int i;

	for (i = 0; buffer[i] != NULL; i++)
	{
		free(buffer[i]);
	}

	free(buffer);
}




/**
* freeEnvironment - function that free environ
*/

void freeEnvironment(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		free(environ[i]);
	}

	free(environ);
}
