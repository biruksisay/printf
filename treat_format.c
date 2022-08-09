#include "main.h"
#include <stdio.h>

/**
 * get_print_func - gets the apropriate printing function
 * for a given format-specifier
 * @c: format-specifier
 *
 * Return: pointer to a function or NULL if not found
 */
char *(*get_print_func(char c))(modifier_t *, va_list)
{
	int i;
	t_print t[] = {
	    {'c', print_char},
	    {'s', print_string},
	    {'i', print_int},
	    {'d', print_int},
	    {'u', print_unsigned_int},
	    {'o', print_octal},
	    {'x', print_hex},
	    {'X', print_hex},
	    {'b', print_binary},
	    {'S', print_big_s},
	    {'p', print_pointer},
	    {'r', print_rev},
	     {'R', print_rot},
	    {'\0', NULL}};
	for (i = 0; t[i].f; i++)
	{
		if (t[i].f == c)
			return (t[i].func);
	}
	return (NULL);
}

