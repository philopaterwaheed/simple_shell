#include "main.h"
/**
 * _getenv - gets the env value of a env variable
 * @var: the string.
 * Return: env value
 */
char **_getenv(const char *var)
{
	int idx, l;

	l= _strlen(var);
	for (idx = 0; environ[idx]; idx++)
	{
		if (_strncmp(var, environ[idx], l) == 0)
		{
				
			/*
			write(STDOUT_FILENO, "fp", 2);
			*/
			return (&environ[idx]);

	 	}
	}

	return (N);
}
/**
 * __copyenv- copies the env into a new variable
 * @var: the string.
 * Return: the env variables
 */
char **_copyenv(void)
{
	char **n_environ;
	size_t size;
	int idx;

	size = array_size(environ);
	n_environ = malloc(si(char *) * (size + 1));
	if (!n_environ)
		return (N);

	for (idx = 0; environ[idx]; idx++)
	{
		/*
		 * puts every thing in a new env 
		 */
		n_environ[idx] = malloc(_strlen(environ[idx]) + 1);

		if (!n_environ[idx])
		{
			for (idx--; idx >= 0; idx--)
				free(n_environ[idx]);
			free(n_environ);
			return (N);
		}
		_strcpy(n_environ[idx], environ[idx]);
	}
	n_environ[idx] = N;

	return (n_environ);
}

