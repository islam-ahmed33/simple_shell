#include "shell.h"

/**
 * _getenv - returns the string array copy of our env
 *@info: Structure containing potential arguments.

 * Return: Always 0
 */

char **_getenv(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->_env = list_to_strings(info->_env);
		info->env_changed = 0;
	}

	return (info->_env);
}
