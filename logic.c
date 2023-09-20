#include "main.h"
/**
 * handle_line - handels the line and operates on it 
 * 
 * @line: line to be operated on
 * @read: the ouput
 * Return: void
 */
void handle_line(char **line, ssize_t read)
{
	char *old_line, *n_line;
	char pre, curr, next;
	size_t i, j;
	ssize_t new_len;
	char semi = ';' , sp = ' ', ad = '&' ,orr ='|';

	new_len = get_new_len(*line);
	if (new_len == read - 1)
		return;
	n_line = malloc(new_len + 1);
	if (!n_line)
		return;
	j = 0;
	old_line = *line;
	for (i = 0; old_line[i]; i++)
	{
		curr = old_line[i];
		next = old_line[i + 1];
		if (i != 0)
		{
			pre = old_line[i - 1];
			if (curr == semi)
			{
				if (next == semi && pre != sp && pre != semi)
				{
					n_line[j++] = sp;
					n_line[j++] = semi;
					continue;
				}
				else if (pre == semi && next != sp)
				{
					n_line[j++] = semi;
					n_line[j++] = sp;
					continue;
				}
				if (pre != sp)
					n_line[j++] = sp;
				n_line[j++] = semi;
				if (next != sp)
					n_line[j++] = sp;
				continue;
			}
			else if (curr == ad)
			{
				if (next == ad && pre != sp)
					n_line[j++] = sp;
				else if (pre == ad && next != sp)
				{
					n_line[j++] = ad;
					n_line[j++] = sp;
					continue;
				}
			}
			else if (curr == orr)
			{
				if (next == orr && pre != sp)
					n_line[j++]  = sp;
				else if (pre == orr && next != sp)
				{
					n_line[j++] = orr;
					n_line[j++] = sp;
					continue;
				}
			}
		}
		else if (curr == semi)
		{
			if (i != 0 && old_line[i - 1] != sp)
				n_line[j++] = sp;
			n_line[j++] = semi;
			if (next != sp && next != semi)
				n_line[j++] = sp;
			continue;
		}
		n_line[j++] = old_line[i];
	}
	n_line[j] = NT;

	free(*line);
	*line = n_line;
}
/**
 * logical_op - handles logical operators
 * 
 * @line: line to be operated on
 * @new_len: the new line
 * Return: void
 */
void logical_ops(char *line, ssize_t *new_len)
{
	char pre, curr, next;
	char semi = ';' , sp = ' ', ad = '&' ,orr ='|';
	pre = *(line - 1);
	curr = *line;
	next = *(line + 1);

	if (curr == ad)
	{
		if (next == ad && pre != sp)
			(*new_len)++;
		else if (pre == ad && next != sp)
			(*new_len)++;
	}
	else if (curr == orr)
	{
		if (next == orr && pre != sp)
			(*new_len)++;
		else if (pre == orr && next != sp)
			(*new_len)++;
	}
	(void) semi;
}
/**
 * get_new_len - get the new line
 * 
 * @line: line to be operated on
 * Return: void
 */
ssize_t get_new_len(char *line)
{
	size_t i;
	ssize_t new_len = 0;
	char curr, next;
	char semi = ';' , sp = ' ', ad = '&' ,orr ='|';
	for (i = 0; line[i]; i++)
	{
		curr = line[i];
		next = line[i + 1];
		if (curr == '#')
		{
			if (i == 0 || line[i - 1] == sp)
			{
				line[i] = NT;
				break;
			}
		}
		else if (i != 0)
		{
			if (curr == semi)
			{
				if (next == semi && line[i - 1] != sp && line[i - 1] != semi)
				{
					new_len += 2;
					continue;
				}
				else if (line[i - 1] == semi && next != sp)
				{
					new_len += 2;
					continue;
				}
				if (line[i - 1] != sp)
					new_len++;
				if (next != sp)
					new_len++;
			}
			else
				logical_ops(&line[i], &new_len);
		}
		else if (curr == semi)
		{
			if (i != 0 && line[i - 1] != sp)
				new_len++;
			if (next != sp && next != semi)
				new_len++;
		}
		new_len++;
	}
	(void) ad;
	(void) orr;
	return (new_len);
}

