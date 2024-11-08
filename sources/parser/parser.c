/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:18:24 by daspring          #+#    #+#             */
/*   Updated: 2024/11/08 12:57:15 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

// #include <string.h>

#include "../../libft/libft.h"
#include "../../includes/miniRT.h"

void	determine_line_count(t_data *data, char **argv);
bool	is_correct_file_type(char *filename);

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
	// populate_obj_array;
	printf("line_count: %d\n", data->input.line_count);
	
}

void	determine_line_count(t_data *data, char **argv)
{
	int		filedes;
	char	*line;

	data->input.line_count = 0;
	filedes = open("./scenes/simple_config.rt", O_RDONLY);
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