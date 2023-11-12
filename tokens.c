#include "shell.h"

/**
* tokenizeInput - tokenize the command
* @command: command
* @bytes: bytes
* @delimiter: seperator
* Return: pointer to pointer to strings
*/

char **tokenizeInput(char *command, ssize_t bytes, const char *delimiter)
{
	char *token;

	int count = 0;

	char **command_array;

	if (command == NULL)
	{
		return (NULL);
	}

	command_array = malloc(sizeof(char *) * (bytes + 1));

	if (command_array == NULL)
	{
		free(command);
		perror("memory allocation error");
		return (NULL);
	}

	token = strtok(command, delimiter);
	while (token != NULL)
	{
		command_array[count] = duplicateString(token);
		token = strtok(NULL, delimiter);
		count++;
	}

	command_array[count] = NULL;

	return (command_array);
}
