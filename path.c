
#include "main.h"
/**
 * get_path_dir - gets the path directories to run the commands
 * @path: the path that iam gonna search in.
 * Return: a linked list with all the pathes.
 */
linked_list *get_path_dir(char *path)
{
	int index, x, y = 0;
	char **dirs, *path_c;
	linked_list *head = N;
	/*
	* printf ("searching dirs");
	*/
	path_c = fill_path_dir(path);
	/*
	* printf ("copy_path) %s" , path_c);
	*/
	if (!path_c)
	{
		printf ("didn't copy path");
		return (N);
	}
	dirs = _strtok(path_c, ":");
	/*
	*printf (" first %s",*dirs);
	*/
	free(path_c);
	if (!dirs)
	{
		printf ("dint' find dirs");
		return (N);
	}
	for (index = 0; dirs[index]; index++)
	{

		/*
		* printf ("searching inside dirs path");
		*/
		if (add_node_end(&head, dirs[index]) == N)
		{
			y++;
			free_list(head);
			free(dirs);
			return (N);
		}
	}
	/*
	* for debug perbuses
	*/
	for (x =0 ; dirs[x] ; x++ );
	free(dirs);

	return (head);
}
/**
 * fill_path_dir - transformes path into directories
 * @path: the path that iam gonna search in.
 * Return: a char* with he dirs
 */
char *fill_path_dir(char *path)
{
	int i, length = 0;
	char *path_c, *pwd;

	pwd = *(_getenv("PWD")) + 4;
	/*
	 * the path has been found
	 * printf ("pwd %s Path %s" , pwd, path);
	*/
	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			if (path[i + 1] == ':' || i == 0 || path[i + 1] == NT)
				length += _strlen(pwd) + 1;
			else
				length++;
		}
		else
			length++;
	}
	path_c = malloc(si(char) * (length + 1));
	if (!path_c)
		return (N);
	path_c[0] = NT;
	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			if (i == 0)
			{
				_strcat(path_c, pwd);
				_strcat(path_c, ":");
			}
			else if (path[i + 1] == ':' || path[i + 1] == NT)
			{
				_strcat(path_c, ":");
				_strcat(path_c, pwd);
			}
			else
				_strcat(path_c, ":");
		}
		else
		{
			_strncat(path_c, &path[i], 1);
		}
	}
	/*
	 * path correctely inputed 
	 *printf ("Path copy %sphilo", path_c);
	 */
	 return (path_c);
}
/**
 * proc_file_commands - runs the programs from the pathes
 * @file_path: the files in the pathes
 * @exe_return: the retun of the program
 * Return: a linked list with all the pathes.
 */
int proc_file_commands(char *file_path, int *exe_return)
{
	ssize_t file, b_read, i;
	unsigned int line_s = 0;
	unsigned int old_size = 120;
	char *line, **arguments, **front;
	char buffer[120];
	int ret;

	hs = 0;
	file = open(file_path, O_RDONLY);
	if (file == -1)
	{
		*exe_return = unopenable(file_path);
		return (*exe_return);
	}
	line = malloc(si(char) * old_size);
	if (!line)
		return (-1);
	do {
		b_read = read(file, buffer, 119);
		if (b_read == 0 && line_s == 0)
			return (*exe_return);
		buffer[b_read] = NT;
		line_s += b_read;
		line = _realloc(line, old_size, line_s);
		_strcat(line, buffer);
		old_size = line_s;
	} while (b_read);
	for (i = 0; line[i] == '\n'; i++)
		line[i] = ' ';
	for (; i < line_s; i++)
	{
		if (line[i] == '\n')
		{
			line[i] = ';';
			for (i += 1; i < line_s && line[i] == '\n'; i++)
				line[i] = ' ';
		}
	}
	handle_line(&line, line_s);
	arguments = _strtok(line, " ");
	free(line);
	if (!arguments)
		return (0);
	if (check_args(arguments) != 0)
	{
		*exe_return = 2;
		free_arguments(arguments, arguments);
		return (*exe_return);
	}
	front = arguments;

	for (i = 0; arguments[i]; i++)
	{
		if (_strncmp(arguments[i], ";", 1) == 0)
		{
			free(arguments[i]);
			arguments[i] = N;
			ret = call_args(arguments, front, exe_return);
			arguments = &arguments[++i];
			i = 0;
		}
	}

	ret = call_args(arguments, front, exe_return);

	free(front);
	return (ret);
}
/**
 * check_args - checks the arguments
 * @arguments: the arguments
 * Return: a linked list with all the pathes.
 */
int check_args(char **arguments)
{
	size_t i;
	char *cur, *nex;

	for (i = 0; arguments[i]; i++)
	{
		cur = arguments[i];
		if (cur[0] == ';' || cur[0] == '&' || cur[0] == '|')
		{
			if (i == 0 || cur[1] == ';')
				return (c_error(&arguments[i], 2));
			nex = arguments[i + 1];
			if (nex && (nex[0] == ';' || nex[0] == '&' || nex[0] == '|'))
				return (c_error(&arguments[i + 1], 2));
		}
	}
	return (0);
}
int unopenable(char *file_path)
{
	char *err, *hs_tostr;
	int lenght;

	hs_tostr = _itoa(hs);
	if (hs_tostr == N)
		return (127);

	lenght = _strlen(name) + _strlen(hs_tostr) + _strlen(file_path) + 16;
	err = malloc(si(char) * (lenght + 1));
	if (err == N)
	{
		free(hs_tostr);
		return (127);
	}

	_strcpy(err, name);
	_strcat(err, ": ");
	_strcat(err, hs_tostr);
	_strcat(err, ": Can't open ");
	_strcat(err, file_path);
	_strcat(err, "\n");

	free(hs_tostr);
	write(STDERR_FILENO, err, lenght);
	free(err);
	return (127);
}
