/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_fcts_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:03:30 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/21 19:24:03 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
#include "../../includes/parser.h"
#include "../../includes/utilities.h"
#include "../../libft/libft.h"

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
	print_error_and_exit("identifier unknown", "object");
	return (-1);
}

void	init_brightness(t_object *obj, char **line_arr, int idx)
{
	float	brightness;

	if (line_arr[idx] == NULL)
		print_error_and_exit("brightness: missing argument", line_arr[0]);
	if (line_arr[idx][0] == '\n')
		print_error_and_exit("brightness: missing argument", line_arr[0]);
	brightness = ft_atof(line_arr[idx]);
	if (is_in_range_float(&brightness, 0, 1))
	{
		obj->s_amb_light.brightness = brightness;
	}
	else
	{
		print_error_and_exit("brightness: value not in range [0,1]", line_arr[0]);
	}
}

void	init_color(t_object *obj, char **line_arr, int idx)
{
	int	red;
	int	green;
	int	blue;
	int	error;

	error = 0;
	exit_if_args_incomplete(line_arr, idx, "color: not enough arguments");
	red = ft_atoi_mod(line_arr[idx], &error);
	exit_if_args_incomplete(line_arr, idx + 1, "color: not enough arguments");
	green = ft_atoi_mod(line_arr[idx + 1], &error);
	exit_if_args_incomplete(line_arr, idx + 2, "color: not enough arguments");
	blue = ft_atoi_mod(line_arr[idx + 2], &error);
	if (is_in_range_int(&red, 0, 255) && is_in_range_int(&green, 0, 255) && \
		is_in_range_int(&blue, 0, 255) && error == 0)
	{
		obj->color = set_color(red / 255.0, green / 255.0, \
								blue / 255.0, 1);
	}
	else
	{
		print_error_and_exit("color: value not in range [0,255]", line_arr[0]);
	}
}

void	init_position(t_object *obj, char **line_arr, int idx)
{
	float	x_coord;
	float	y_coord;
	float	z_coord;

	exit_if_args_incomplete(line_arr, idx, "position: not enough arguments");
	x_coord = ft_atof(line_arr[idx]);
	exit_if_args_incomplete(line_arr, idx + 1, \
							"position: not enough arguments");
	y_coord = ft_atof(line_arr[idx + 1]);
	exit_if_args_incomplete(line_arr, idx + 2, \
							"position: not enough arguments");
	z_coord = ft_atof(line_arr[idx + 2]);
	obj->position = set_tuple(x_coord, y_coord, z_coord, PT);
}

bool	is_in_range_float(float *num, int min, int max)
{
	if (*num <= (float)max && *num >= (float)min)
		return (true);
	else
		return (false);
}

bool	is_in_range_int(int *num, int min, int max)
{
	if (*num <= max && *num >= min)
		return (true);
	else
		return (false);
}

void	exit_if_args_incomplete(char **line_arr, int idx, char *message)
{
	if (line_arr[idx] == NULL)
		print_error_and_exit(message, line_arr[0]);
	if (line_arr[idx][0] == '\n')
		print_error_and_exit(message, line_arr[0]);
}
