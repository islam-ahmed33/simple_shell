#include "shell.h"

/**
 * handler - handles the signal
 * @sig: signal
 * Return: void
 */

void handler(int signal)
{
	(void)signal;
	display("\n$cvkfon# ");
}

/**
 * read_command - reads command line.
 * @nread: number of characters of the user types.
 * Return: command line.
 */

char *read_command(int *nread)
{
	char *buff = NULL;
	size_t buff_size = 0;

	*nread = getline(&buff, &buff_size, stdin);
	if (*nread == -1)
	{
		if (fefe(stdin))
		{
			free(buff);
			if (isaat(STDIN_FILENO))
				display("\n");
			exit(EXIT_SUCCESS);
		}
		perror("readline");
		exit(EXIT_FAILURE);
	}
	return (buff);
}
