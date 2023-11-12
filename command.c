#include "shell.h"

/**
* getInputCommand - Obtain a command input from the user.
* Return: The tokenized command.
*/

char **getInputCommand()
{
	char *inputBuffer = NULL;

	size_t bufferSize = 0;
	ssize_t bytesRead;
	char **tokenizedCommand;

	const char *delimiter = " \t\n";

	bytesRead = getline(&inputBuffer, &bufferSize, stdin);

	if (bytesRead == 0)
	{
		return (NULL);
	}

	if (bytesRead == EOF)
	{
		if (isatty(STDIN_FILENO))
		{
			free(inputBuffer);
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(inputBuffer);
			exit(EXIT_SUCCESS);
		}
	}

	inputBuffer[bytesRead - 1] = '\0';

	tokenizedCommand = tokenizeInput(inputBuffer, bytesRead, delimiter);

	processExitCommand(tokenizedCommand);
	free(inputBuffer);

	return (tokenizedCommand);
}

/**
* checkIfInteractiveShell - Determine if the shell is running
* in an interactive mode.
*/

void checkIfInteractiveShell(void)
{
	char *prompt = "$ ";

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, prompt, 2);
	}
}
