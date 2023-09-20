#include "main.h"
/**
 * get_builtinn- to get the bulit in functions in the shell
 * Return: length the array best i could get acually.
 */
int (*get_builtinn(char *command))(char **args, char **front)
{
	builtin_ funcs[] = {
		{ "exit", _exit_ },
		{"env" ,_env},
		{ NULL, NULL }
	};
	int i;

	for (i = 0; funcs[i].nme; i++)
	{
		if (_strcmp(funcs[i].nme, command) == 0)
		{
			break;
		}
	}
	return (funcs[i].f);
}
