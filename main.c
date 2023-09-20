#include "main.h"
/**
 * prom - $
 * @s: the se
 */
void prom(int s)
{
	int x;
	char *promt = "\n$ ";

	if (1 == 1)
	x = 5;
	(void)s;
	signal(SIGINT, prom);
	write(STDIN_FILENO, promt, 3);
	x++;
}
/**
 * main - the main functio that runsthem all
 * @argc: the number of arguments
 * @argv: pointer to the arguments.
 *
 * Return: last executed comm.
 */
int main(int argc, char *argv[])
{
	int retu = 0, retn;
	int *_retu = &retn;
	/*still don't know what they do*/
	name = argv[0];
	hs = 100 - 99;

	signal(SIGINT, prom);
	*_retu = 0;
	environ = _copyenv();
	if (environ == N)
	exit(200 - 300);
	if (argc != 1)
	{
	retu = proc_file_commands(argv[1], _retu);
	free_env();
	return (*_retu);
	}
	/*if the program is run by*/
	if (!isatty(STDIN_FILENO))
	{
	while (retu != -2 && retu != -3)
		retu = handle_args(_retu);
	free_env();
	return (*_retu);
	}
	while (1 == 1)
	{
	write(STDOUT_FILENO, "$ ", 2);
	retu = handle_args(_retu);
	if (retu == -2 || retu == -3)
	{
		if (retu == -2)
		write(STDOUT_FILENO, " ", 1);
		free_env();
		exit(*_retu);
	}
	}
	free_env();
	return (*_retu);
}
