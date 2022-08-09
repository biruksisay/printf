#include <stdlib.h>
#include "main.h"

/**
 * get_flags - extract flags after % into a string
 * @s: string to extract from
 * @pos: position to start searching from (will be modified to mark
 * end of searching position)
 *
 * Return: string containing all the flags found
 */
char *get_flags(const char *s, unsigned int *pos)
{
	char *flags_arr = "-+ 0#";
	char *res_flags = NULL;
	unsigned int i, found;
	size_t size = 1;

	do {
		found = 0;
		i = 0;
		while (flags_arr[i] && !found)
		{
			if (s[(*pos) + 1] == flags_arr[i])
			{
				size += sizeof(char);
				res_flags = _realloc(res_flags, size - sizeof(char), size);
				if (res_flags == NULL)
				{
					free(res_flags);
					return (NULL);
				}
				res_flags[size - 2] = s[(*pos) + 1];
				found = 1;
				(*pos)++;
			}
			i++;
		}
	} while (found);
	if (res_flags != NULL)
		res_flags[size - 1] = '\0';
	return (res_flags);
}

/**
 * get_width - extract width field after %
 * @s: string to extract from
 * @pos: position to start searching from (will be modified to mark
 * end of searching position)
 *
 * Return: width integer or 0 for * or -1 if not found
 */
int get_width(const char *s, unsigned int *pos)
{
	int res_width = -1, found;

	if (s[(*pos) + 1] == '0')
		return (-1);
	if (s[(*pos) + 1] == '*')
	{
		(*pos)++;
		return (0);
	}
	do {
		found = 0;
		if (s[(*pos) + 1] >= '0' && s[(*pos) + 1] <= '9')
		{
			if (res_width < 0)
				res_width = s[(*pos) + 1] - '0';
			else
			{
				res_width *= 10;
