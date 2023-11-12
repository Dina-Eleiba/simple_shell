#include "shell.h"

/**
* processExitCommand - Handle the 'exit' command.
* @commandTokens: An array of command tokens to process.
*/

void processExitCommand(char **commandTokens)
{
    int i;

    int exitStatus;

    for (i = 0; commandTokens[i] != NULL; i++)
    {
        if (strncmp(commandTokens[i], "exit", stringLength("exit")) == 0
        && !commandTokens[i + 1])
        {
            cleanupAndExit(commandTokens, EXIT_SUCCESS);
        }
        else if (strncmp(commandTokens[i], "exit",
	stringLength("exit")) == 0
        && commandTokens[i + 1])
        {
            exitStatus = stringToInteger(commandTokens[i + 1]);
            cleanupAndExit(commandTokens, exitStatus);
        }
    }
}

/**
* cleanupAndExit - Clean up resources and exit the
* shell with a specific status.
* @commandTokens: An array of command tokens.
* @exitStatus: The exit status to use.
*/

void cleanupAndExit(char **commandTokens, int exitStatus)
{
    deallocateBuffer(commandTokens);
    exit(exitStatus);
}
