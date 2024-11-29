/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:18:24 by daspring          #+#    #+#             */
/*   Updated: 2024/11/29 15:20:28 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

// #include <string.h>

#include "../../libft/libft.h"
#include "../../includes/miniRT.h"
#include "../../includes/parser.h"
#include "../../includes/utilities.h"
#include "../../includes/free.h"

void	determine_line_count(t_data *data, char **argv);
bool	is_correct_file_type(char *filename);
int		get_obj_name(char *identifier);
void	str_substitute(char *str, char from, char to);

void	handle_input(t_data *data, int argc, char **argv)
{
	if (argc != 2)
	{
		print_error_and_exit2("Wrong number of parameters.\n", "Program input");
	}
	if (is_correct_file_type(argv[1]) == false)
	{
		print_error_and_exit2("Wrong file extension.\n", "input: ");
	}
	determine_line_count(data, argv);
	data->objects = ft_calloc(data->input.line_count + 1, sizeof(t_object *));
	// check for NULL
	populate_objects_array(data, argv);
	check_plane_normal_vec_dir(data);
	check_completeness(data);
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
		free(line);
		data->input.line_count++;
		line = get_next_line(filedes);
	}
	free(line); // potential double free!
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
	data->line = line;
	idx = 0;
	while (line != NULL)
	{
		str_substitute(line, ',', ' ');
		str_substitute(line, '\t', ' ');
		line_array = ft_split(line, ' ');
		data->line_array = line_array;
// check for NULL
		if (line_array[0][0] != '\n' && line_array[0][0] != '#')
		{
			obj_name = get_obj_name(line_array[0]);
			data->objects[idx] = get_parse_ft()[obj_name](line_array);
			idx++;
		}
		free_char_ptr_array(line_array);
		free(line);
		line = get_next_line(filedes);
		data->line = line;
	}
	free(line); // potential double free
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
