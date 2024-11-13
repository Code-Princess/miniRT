/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:18:24 by daspring          #+#    #+#             */
/*   Updated: 2024/11/13 19:43:35 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

// #include <string.h>

#include "../../libft/libft.h"
#include "../../includes/miniRT.h"
#include "../../includes/parser.h"

void	determine_line_count(t_data *data, char **argv);
bool	is_correct_file_type(char *filename);
int		get_obj_name(char *identifier);
void	str_substitute(char *str, char from, char to);

void	handle_input(t_data *data, int argc, char **argv)
{
// if wrong num of inputs or wrong file-ending -> fatal_input_termination
	// filedes = open(argv[1]);
	if (argc != 2)
	{
printf("wrong number of inputs\n");
	}
	if (is_correct_file_type(argv[1]) == false)
	{
printf("wrong file extension\n");
	}
	determine_line_count(data, argv);
	data->objects = ft_calloc(data->input.line_count + 1, sizeof(t_object *));
	populate_objects_array(data, argv);
}

void	determine_line_count(t_data *data, char **argv)
{
	int		filedes;
	char	*line;

	data->input.line_count = 0;
	filedes = open(argv[1], O_RDONLY);
	line = get_next_line(filedes);
	while (line != NULL)
	{
		data->input.line_count++;
		line = get_next_line(filedes);
	}
	close(filedes);
}

bool	is_correct_file_type(char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (extension == NULL)
		return (false);
	if (ft_strcmp(extension, ".rt") == 0)
		return (true);
	else
		return (false);
}

void	populate_objects_array(t_data *data, char **argv)
{
	int		filedes;
	char	*line;
	char	**line_array;
	int		obj_name;
	int		idx;

	filedes = open(argv[1], O_RDONLY);
	line = get_next_line(filedes);
	idx = 0;
	while (line != NULL)
	{
		str_substitute(line, ',', ' ');
		str_substitute(line, '\t', ' ');
		line_array = ft_split(line, ' ');
// check for NULL
		obj_name = get_obj_name(line_array[0]);
		data->objects[idx] = get_parse_ft()[obj_name](line_array);
		free(line_array);
		idx++;
		line = get_next_line(filedes);
	}
	close(filedes);
}

void	str_substitute(char *str, char from, char to)
{
	while (*str != '\0')
	{
		if (*str == from)
		{
			*str = to;
		}
		str++;
	}
}
