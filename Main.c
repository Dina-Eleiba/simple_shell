#include "shell.h"

/**
* main - Entry point for the shell program.
* @argc: Number of command-line arguments.
* @argv: Array of pointers to command-line argument strings.
* Return: 0 upon successful completion.
*/
int main(int argc, char *argv[])
{
	char **commandTokens = NULL;

	(void)argc;

	while (1)
	{
		checkIfInteractiveShell();
		commandTokens = getInputCommand();

		if (commandTokens != NULL)
		{
			executeCommand(commandTokens, argv);
			deallocateBuffer(commandTokens);
		}
	}

	if (!isatty(STDIN_FILENO))
	{
		commandTokens = getInputCommand();
		if (commandTokens != NULL)
		{
			executeCommand(commandTokens, argv);
			deallocateBuffer(commandTokens);
		}
	}

	freeEnvironment();
	deallocateBuffer(commandTokens);

	return (0);
}
