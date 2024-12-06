/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_mod.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:53:48 by daspring          #+#    #+#             */
/*   Updated: 2024/12/05 19:04:13 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#include "libft.h"
#include "../includes/miniRT.h"
#include "../includes/free.h"

static char	*create_ret_str(char buffer[], int fd, char *ret_str);
static char	*search_and_update_buffer(char *buffer, char *ret_str, \
										int *newline_found);
static char	*put_on_proper_nullterminator(char *string);
static int	buffer_is_empty(char *buffer);

/*
 *	All characters in an input line (ending in '\n' or with EOF) are returned
 *	in a string that ends with '\0'. To prevent any undefined behavior caused
 *	by a '\0' within the line itself, the value -2 is utilized as a local
 *	STRING-TERMINATOR.
 *	A static 2D-char-array is used to buffer the input from read in a
 *	persistent way.
 *	- if buffer is empty, fill the buffer, mark the end of buffer with -2
 *									to always be able to find the end of buffer
 *	- search for newline in buffer
 *		- if not found: append whole buffer to ret_str, zero the buffer, repeat
 *		- if found: append substr to ret_str, move buffer_data forward,
 *					return ret_str
 */

char	*get_next_line_mod(int fd)
{
	static char		buffer[OPEN_MAX][BUFFER_SIZE + 1];
	char			*ret_str;
	unsigned int	pos;
	t_data			*data;

	data = get_data();
	pos = 0;
	while (pos < OPEN_MAX)
		buffer[pos++][BUFFER_SIZE] = STRING_TERMINATOR;
	ret_str = malloc(1 * sizeof(char));
	if (fd < 0 || BUFFER_SIZE < 1 || ret_str == NULL)
	{
		free_obj_ptr_array(data->objects);
		exit (1);
	}
	ret_str[0] = STRING_TERMINATOR;
	ret_str = create_ret_str(buffer[fd], fd, ret_str);
	return (ret_str);
}

static char	*create_ret_str(char buffer[], int fd, char *ret_str)
{
	int	read_value;
	int	newline_found;

	newline_found = 0;
	while (1)
	{
		if (buffer_is_empty(buffer))
		{
			read_value = read(fd, buffer, BUFFER_SIZE);
			if (read_value > 0 && read_value < BUFFER_SIZE)
				buffer[read_value] = STRING_TERMINATOR;
			if (read_value <= 0)
			{
				buffer[0] = STRING_TERMINATOR;
				if (read_value == 0 && string_length(ret_str) > 0)
					return (put_on_proper_nullterminator(ret_str));
				return (free(ret_str), NULL);
			}
		}
		ret_str = search_and_update_buffer(buffer, ret_str, &newline_found);
		if (newline_found == 1 || ret_str == NULL)
			return (put_on_proper_nullterminator(ret_str));
	}
	return (NULL);
}

static char	*search_and_update_buffer(char *buffer, char *ret_str, \
										int *newline_found)
{
	size_t	pos;

	pos = 0;
	while (pos < BUFFER_SIZE)
	{
		if (buffer[pos] == '\n')
		{
			*newline_found = 1;
			ret_str = string_append(ret_str, buffer, pos + 1);
			ft_memmove(buffer, &(buffer[pos + 1]), BUFFER_SIZE - (pos + 0));
			buffer[BUFFER_SIZE - pos - 1] = STRING_TERMINATOR;
			return (ret_str);
		}
		if (buffer[pos] == STRING_TERMINATOR)
		{
			ret_str = string_append(ret_str, buffer, pos);
			buffer[0] = STRING_TERMINATOR;
			return (ret_str);
		}
		pos++;
	}
	ret_str = string_append(ret_str, buffer, string_length(buffer));
	buffer[0] = STRING_TERMINATOR;
	return (ret_str);
}

static char	*put_on_proper_nullterminator(char *string)
{
	if (string != NULL)
		string[string_length(string)] = 0;
	return (string);
}

static int	buffer_is_empty(char *buffer)
{
	int	pos;

	if (buffer[0] == STRING_TERMINATOR)
		return (1);
	pos = 0;
	while (pos < BUFFER_SIZE)
	{
		if (buffer[pos] != 0)
			return (0);
		pos++;
	}
	return (1);
}
