#include "shell.h"

/**
 * *_get_env - Gets an env variable.
 * @var: Structure containing potential arguments.
 *
 * Return: NULL.
 */

char **_get_env(char *var)
{
	int i, len;

	len = _strlen(var);
	for (i = 0; env[i]; i++)
	{
		if (_strncmp(var, env[i], len) == 0)
			return (&env[i]);
	}

	return (NULL);
}

list_s *_get_env_value(char *variable)
{
	int equal_sign_index = 0;
	int index = 0;
	char *dils = NULL;
	char **env_value = _get_env(var);
	list_s *result = NULL;

	if (!env_value)
		return (NULL);

	while ((*env_value)[i] != '=')
		i++;
	equal_sign_index = ++i;

	dils = _strtok((*env_value) + equal_sign_index, ":");
	while (dils)
	{
		add_node_end(&result, dils);
		dils = _strtok(NULL, ":");
	}
	return (result);
}
