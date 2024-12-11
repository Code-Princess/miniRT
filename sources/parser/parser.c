/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:18:24 by daspring          #+#    #+#             */
/*   Updated: 2024/12/11 20:50:34 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

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
		error_and_exit("Wrong number of parameters.\n", "Program input");
	if (is_correct_file_type(argv[1]) == false)
		error_and_exit("Wrong file extension.\n", "input");
	determine_line_count(data, argv);
	data->objects = ft_calloc((data->input.line_count * 2) + 1, sizeof(t_object *));
	if (data->objects == NULL)
		error_and_exit("Malloc failed.\n", "input");
	populate_objects_array(data, argv);
	check_plane_normal_vec_dir(data);
	check_completeness(data);
	check_cylinder(data);
}

void	determine_line_count(t_data *data, char **argv)
{
	int		filedes;

	data->input.line_count = 0;
	filedes = open(argv[1], O_RDONLY);
	if (filedes == -1)
		error_and_exit("could not open file", "input");
	data->line = get_next_line_mod(filedes);
	while (data->line != NULL)
	{
		free(data->line);
		data->input.line_count++;
		data->line = get_next_line_mod(filedes);
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
	int		obj_name;
	int		idx;

	filedes = open(argv[1], O_RDONLY);
	data->line = get_next_line_mod(filedes);
	idx = 0;
	while (data->line != NULL)
	{
		str_substitute(data->line, ',', ' ');
		str_substitute(data->line, '\t', ' ');
		data->line_array = ft_split(data->line, ' ');
		if (data->line_array == NULL)
			error_and_exit2("ft_split failed", "input", NULL);
		if (data->line_array[0][0] != '\n' && data->line_array[0][0] != '#')
		{
			obj_name = get_obj_name(data->line_array[0]);
			data->objects[idx] = get_parse_ft()[obj_name](data->line_array);
			idx++;
		}
		free_char_ptr_array(data->line_array);
		free(data->line);
		data->line = get_next_line_mod(filedes);
	}
	close(filedes);
}

void	str_substitute(char *str, char from, char to)
{
	while (*str != '\0')
	{
		if (*str == from)
			*str = to;
		str++;
	}
}
