#include "shell.h"

/**
 * main - main function.
 * Return: 0 on success, 1 on error.
 */

int main(void)
{
	char **cmd, input;
	int status = 1;
	int nread;

	while (status)
	{
		display(">> ");
		cmd = read_cmd(&nread);
		argc = split_cmd(cmd, &nread);
		status = excute(argc);

		free(cmd);
		free(argc);
	}
	return (0);
}
