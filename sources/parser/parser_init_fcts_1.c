/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_fcts_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:03:30 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/12 00:18:53 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
#include "../../includes/parser.h"
#include "../../includes/free.h"
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
	else
		error_and_exit2("identifier unknown", "object", NULL);
	return (-1);
}

void	init_brightness(t_object *obj, char **line_arr, int idx)
{
	double	brightness;
	int		error;

	error = 0;
	if (line_arr[idx] == NULL)
		error_and_exit2("brightness: missing argument", line_arr[0], obj);
	if (line_arr[idx][0] == '\n')
		error_and_exit2("brightness: missing argument", line_arr[0], obj);
	brightness = ft_atof_mod(line_arr[idx], &error);
	if (is_in_range_float(&brightness, 0, 1) && error == 0)
		obj->s_amb_light.brightness = brightness;
	else
		error_and_exit2("brightness: value not in range [0,1]", \
							line_arr[0], obj);
}

void	init_color(t_object *obj, char **line_arr, int idx)
{
	int	red;
	int	green;
	int	blue;
	int	error;

	error = 0;
	exit_if_args_incompl(line_arr, idx, "color: not enough arguments", obj);
	red = ft_atoi_mod(line_arr[idx], &error);
	exit_if_args_incompl(line_arr, idx + 1, "color: not enough arguments", obj);
	green = ft_atoi_mod(line_arr[idx + 1], &error);
	exit_if_args_incompl(line_arr, idx + 2, "color: not enough arguments", obj);
	blue = ft_atoi_mod(line_arr[idx + 2], &error);
	if (is_in_range_int(&red, 0, 255) && is_in_range_int(&green, 0, 255) && \
		is_in_range_int(&blue, 0, 255) && error == 0)
		obj->color = set_color(red / 255.0, green / 255.0, \
								blue / 255.0, 1);
	else
		error_and_exit2("color: value not in range [0,255]", line_arr[0], obj);
}

void	init_position(t_object *obj, char **line_arr, int idx)
{
	double	x_coord;
	double	y_coord;
	double	z_coord;
	int		error;

	error = 0;
	exit_if_args_incompl(line_arr, idx, "position: not enough arguments", obj);
	x_coord = ft_atof_mod(line_arr[idx], &error);
	exit_if_args_incompl(line_arr, idx + 1, \
							"position: not enough arguments", obj);
	y_coord = ft_atof_mod(line_arr[idx + 1], &error);
	exit_if_args_incompl(line_arr, idx + 2, \
							"position: not enough arguments", obj);
	z_coord = ft_atof_mod(line_arr[idx + 2], &error);
	if (is_in_range_float(&x_coord, -10000, 10000) && \
		is_in_range_float(&y_coord, -10000, 10000) && \
		is_in_range_float(&z_coord, -10000, 10000) && error == 0)
		obj->position = set_tuple(x_coord, y_coord, z_coord, PT);
	else
	{
		error_and_exit2("position: value not in range [-10000,10000]", \
						line_arr[0], obj);
	}
}

bool	is_in_range_float(double *num, int min, int max)
{
	if (*num <= (double)max && *num >= (double)min)
		return (true);
	else
		return (false);
}
