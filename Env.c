#include "shell.h"

/**
* findEnvironmentVariable- Find the value of an environment variable
* @varName: the name of the env variable will be retrieved
* Return: A pointer to the value or NULL if not found.
*/

char *findEnvironmentVariable(char *varName)
{

	int n = 0;

	int varNameLength = stringLength(varName);

	for (n = 0; environ[n] != NULL; n++)
	{
		if (strncmp(varName, environ[n], varNameLength) == 0)
		{
			return (environ[n]);
		}
	}

	return (NULL);
}


/**
* printAllEnvironmentVariables - print all the environment variables
* @userCommand: the user’s command
* Return: always nothing
*/

void *printAllEnvironmentVariables(char **userCommand)
{
	int n;

	int envCommandLength = stringLength("env");

	if (userCommand == NULL || userCommand[0] == NULL)
	{
		return (0);
	}

	if (strncmp(userCommand[0], "env", envCommandLength) == 0)
	{
		for (n = 0; environ[n] != NULL; n++)
		{
			write(STDOUT_FILENO, environ[n], stringLength(environ[n]));
			write(STDOUT_FILENO, "\n", 1);
		}

		freeEnvironment();
	}

	return (0);
}
