#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: the concatenated string
 */

char *_strcat(char *destination, char *source)
{
	int i, j;

	for (i = 0; destination[i] != '\0'; i++)
		;
	for (j = 0; source[j] != '\0'; j++)
		destination[i + j] = source[j];
	destination[i + j] = '\0';
	return (destination);
}

/**
 * _getenv - gets the value of an environment variable
 * @name:  name of variable in the environment..
 * Return: value of the variable in environment.
 */

char *_getenv(char *name)
{
	int i, j, name_length;
	char *environ;

	for (i = 0; env[i] != NULL; i++)
	{
		environ = env[i];
		name_length = _strlen(name);

		for (j = 0; j < name_length; j++)
		{
			if (env[j] != name[j])
				break;
		}
		if (j == name_length && env[j] == '=')
		{
			return (env + j + 1);
		}
	}
	return (NULL);
}

/**
 * get_location - gets the location of a command
 * @command: command to find
 *
 * Return: location of command
 */

char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int cmd_length, dir_length;
	struct stat buff;

	path = _getenv("PATH");
	if (path)
	{
		path_copy = _strdup(path);
		cmd_length = _str_length(cmd);
		path_token = str_token(path_copy, ":");

		while (path_token != NULL)
		{
			dir_length = _str_length(path_token);
			file_path = malloc(cmd_lenght + dir_length + 2);
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, cmd);
			_strcat(file_path, "\0");

			if (stat(file_path, &buff) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = str_token(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(cmd, &buff) == 0)
			return (cmd);

		return (NULL);
	}

	return (NULL);
}
