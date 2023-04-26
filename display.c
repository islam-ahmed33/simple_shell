#include "shell.h"

/**
 * display - display a string
 * @str: string to display
 * Return: void
 */
void display(char *string)
{
	int length = _strlen(string);

	write(1, string, length);
}
