/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_fcts_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:03:30 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/15 16:52:01 by daspring         ###   ########.fr       */
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
	exit (-1); // proper error management missing!
}

void	init_brightness(t_object *obj, char **line_arr, int idx)
{
	float	brightness;

	brightness = ft_atof(line_arr[idx]);
	if (is_in_range(&brightness, 0, 1))
	{
		obj->s_amb_light.brightness = brightness;
	}
	else ;
		//error
}

void	init_color(t_object *obj, char **line_arr, int idx)
{
	int	red_col;
	int	green_col;
	int	blue_col;
	int	error;

	error = 0;
	red_col = ft_atoi_mod(line_arr[idx], &error);
	green_col = ft_atoi_mod(line_arr[idx + 1], &error);
	blue_col = ft_atoi_mod(line_arr[idx + 2], &error);
	if (is_in_range(&red_col, 0, 255) && is_in_range(&green_col, 0, 255) && \
		is_in_range(&blue_col, 0, 255) && error == 0)
	{
		obj->color = set_color(red_col / 255.0, green_col / 255.0, \
								blue_col / 255.0, 1);
	}
	else ;
		//error!
}

void	init_position(t_object *obj, char **line_arr, int idx)
{
	float	x_coord;
	float	y_coord;
	float	z_coord;
	int		error;

	error = 0;
	if (line_arr[idx] == NULL)
		print_error_and_exit("position: not enough arguments", line_arr[0]);
	x_coord = ft_atof(line_arr[idx]);
	if (line_arr[idx + 1] == NULL)
		print_error_and_exit("position: not enough arguments", line_arr[0]);
	y_coord = ft_atof(line_arr[idx + 1]);
	if (line_arr[idx + 2] == NULL)
		print_error_and_exit("position: not enough arguments", line_arr[0]);
	z_coord = ft_atof(line_arr[idx + 2]);
	obj->position = set_tuple(x_coord, y_coord, z_coord, PT);
}

bool	is_in_range(void *num, int min, int max)
{
	float	*number;

	number = (float *)num;
	if (*number <= (float)max && *number >= (float)min)
		return (true);
	else
		return (false);
}

void	print_error_and_exit(char *message, char *identifier)
{
	ft_printf_error("Error\n");
	ft_printf_error("%s %s\n", identifier, message);
	exit(1);
}
