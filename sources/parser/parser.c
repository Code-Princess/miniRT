/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:18:24 by daspring          #+#    #+#             */
/*   Updated: 2024/11/08 19:47:41 by daspring         ###   ########.fr       */
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

void	handle_input(t_data *data, int argc, char **argv)
{
// if wrong num of inputs or wrong file-ending -> fatal_input_termination
	// filedes = open(argv[1]);
	if (argc != 2)
	{}
	if (is_correct_file_type(argv[1]) == false)
	{
printf("wrong file extension\n");
	}
	determine_line_count(data, argv);
printf("line_count: %d\n", data->input.line_count);
	data->objects = ft_calloc(data->input.line_count, sizeof(t_object *));
	// init_data(data);
	populate_objects_array(data, argv);
}

void	determine_line_count(t_data *data, char **argv)
{
	int		filedes;
	char	*line;

	data->input.line_count = 0;
	filedes = open("./scenes/simple_config.rt", O_RDONLY);
	// filedes = open(argv[1], O_RDONLY);
	line = get_next_line(filedes);
	while (line != NULL)
	{
		data->input.line_count++;
		line = get_next_line(filedes);
	}
// printf("first line from file:\n%s", get_next_line(filedes));
	close(filedes);
}

bool	is_correct_file_type(char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (extension == NULL)
		return (false);
printf("in fct - ft_strncmp(extension, .rt, 3): %d\n", ft_strncmp(extension, ".rt", 3));
	if (ft_strcmp(extension, ".rt") == 0)
	// if (ft_strncmp(extension, ".rt", 3) == 0)
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

	filedes = open("./scenes/simple_config.rt", O_RDONLY);
	// filedes = open(argv[1], O_RDONLY);
	line = get_next_line(filedes);
	idx = 0;
	while (line != NULL)
	{
		line_array = ft_split(line, ' ');
// check for NULL

		obj_name = get_obj_name(line_array[0]);
		get_parse_ft()[obj_name](line_array);
		// data->objects[idx] = get_parse_ft()[obj_name](line_array);
		free(line_array);
		idx++;
		line = get_next_line(filedes);
	}
// printf("first line from file:\n%s", get_next_line(filedes));
	close(filedes);
}

int	get_obj_name(char *identifier)
{
	if (ft_strcmp(identifier, "A") == 0)
		return (AMB_LIGHT);
	if (ft_strcmp(identifier, "C") == 0)
		return (CAMERA);
	if (ft_strcmp(identifier, "L") == 0)
		return (LIGHT);
	if (ft_strcmp(identifier, "sp") == 0)
		return (SPHERE);
	if (ft_strcmp(identifier, "pl") == 0)
		return (PLANE);
	if (ft_strcmp(identifier, "cy") == 0)
		return (CYLINDER);
	exit (-1); // proper error management missing!
}
