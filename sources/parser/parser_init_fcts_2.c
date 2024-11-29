/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_fcts_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:03:30 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/29 15:34:57 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
#include "../../includes/parser.h"
#include "../../includes/maths.h"
#include "../../libft/libft.h"
#include "../../includes/utilities.h"

void	init_normal_vec(t_object *obj, char **line_arr, int idx)
{
	double	x_normal_vec;
	double	y_normal_vec;
	double	z_normal_vec;
	t_tuple	vec;
	t_tuple	temp; // only as long as tuple_normalize is used above!

	exit_if_args_incomplete(line_arr, idx, "normal_vec: not enough arguments", obj);
	x_normal_vec = ft_atof(line_arr[idx]);
	exit_if_args_incomplete(line_arr, idx + 1, \
							"normal_vec: not enough arguments", obj);
	y_normal_vec = ft_atof(line_arr[idx + 1]);
	exit_if_args_incomplete(line_arr, idx + 2, \
							"normal_vec: not enough arguments", obj);
	z_normal_vec = ft_atof(line_arr[idx + 2]);
	vec = set_tuple(x_normal_vec, y_normal_vec, z_normal_vec, VEC);
	temp = tuple_normalize2(&vec); // only as long as tuple_normalize is used above!
	vec = temp; // only as long as tuple_normalize is used above!
// print_tuple(vec);
	if (is_normalized(&vec))
		obj->s_camera.normal_vec = vec;
	else
	{
		print_error_and_exit("normal_vec: vector not normalized", line_arr[0], obj);
	}
}

void	check_plane_normal_vec_dir(t_data *data)
{
	int		idx_camera;
	int		pos;
	float	dot_prod;
	t_tuple	dir;

	pos = 0;
	idx_camera = get_object_index(data, C);
	while (data->objects[pos] != NULL)
	{
		if (data->objects[pos]->identifier == PL)
		{
			dir = direction2(&data->objects[pos]->position, &data->objects[idx_camera]->position);
			dot_prod = tuple_dot2(&data->objects[pos]->s_plane.normal_vec, &dir);
			if (dot_prod < 0)
			{
				data->objects[pos]->s_plane.normal_vec = tuple_neg2(&data->objects[pos]->s_plane.normal_vec);
			}
		}
		pos++;
	}
}

void	init_axis_vec(t_object *obj, char **line_arr, int idx)
{
	double	x_normal_vec;
	double	y_normal_vec;
	double	z_normal_vec;
	t_tuple	vec;
	t_tuple	temp;

	exit_if_args_incomplete(line_arr, idx, "axis_vec: not enough arguments", obj);
	x_normal_vec = ft_atof(line_arr[idx]);
	exit_if_args_incomplete(line_arr, idx + 1, "axis_vec: not enough arguments", obj);
	y_normal_vec = ft_atof(line_arr[idx + 1]);
	exit_if_args_incomplete(line_arr, idx + 2, "axis_vec: not enough arguments", obj);
	z_normal_vec = ft_atof(line_arr[idx + 2]);
	vec = set_tuple(x_normal_vec, y_normal_vec, z_normal_vec, VEC);
	temp = tuple_normalize2(&vec); // only as long as tuple_normalize is used above!
	vec = temp; // only as long as tuple_normalize is used above!;
	if (is_normalized(&vec))
		obj->s_cy.axis_vec = vec;
	else
	{
		print_error_and_exit("axis_vec: vector not normalized", line_arr[0], obj);
	}
}

void	init_angle(t_object *obj, char **line_arr, int idx)
{
	double	angle;

	exit_if_args_incomplete(line_arr, idx, "angle: not enough arguments", obj);
	angle = ft_atof(line_arr[idx]);
	if (is_in_range_float(&angle, 0, 180))
	{
		obj->s_camera.angle = angle;
	}
	else
	{
		print_error_and_exit("angle: value not in range [0,180]", line_arr[0], obj);
	}
}

void	init_radius(t_object *obj, char **line_arr, int idx)
{
	double	radius;
	char	message[100];

	exit_if_args_incomplete(line_arr, idx, "radius: missing argument", obj);
	radius = ft_atof(line_arr[idx]) / 2;
	if (is_in_range_float(&radius, 0, MAX_RADIUS))
	{
		if (obj->identifier == SP)
			obj->s_sphere.radius = radius;
		if (obj->identifier == CY)
			obj->s_cy.radius = radius;
	}
	else
	{
		ft_bzero(message, 100);
		ft_strlcat(message, "radius: value not in range [0,", 100);
		ft_strlcat(message, ft_itoa(MAX_RADIUS), 100);
		ft_strlcat(message, "]", 100);
		print_error_and_exit(message, line_arr[0], obj);
		print_error_and_exit(message, line_arr[0], obj);
	}
}

void	init_height(t_object *obj, char **line_arr, int idx)
{
	double	height;
	char	message[100];

	exit_if_args_incomplete(line_arr, idx, "height: missing argument", obj);
	height = ft_atof(line_arr[idx]);
	if (is_in_range_float(&height, 0, MAX_CY_HEIGHT))
	{
		obj->s_cy.height = height;
	}
	else
	{
		ft_bzero(message, 100);
		ft_strlcat(message, "height: value not in range [0,", 100);
		ft_strlcat(message, ft_itoa(MAX_CY_HEIGHT), 100);
		ft_strlcat(message, "]", 100);
		print_error_and_exit(message, line_arr[0], obj);
	}
}

void	check_completeness(t_data *data)
{
	char	completeness_str[4];
	int		pos;

	// completeness_str = "XXX";
	pos = 0;
	while (data->objects[pos] != NULL)
	{
		if (data->objects[pos]->identifier == C)
		{
			completeness_str[0] = 'C';
		}
		else if (data->objects[pos]->identifier == A)
		{
			completeness_str[1] = 'A';
		}
		else if (data->objects[pos]->identifier == L)
		{
			completeness_str[2] = 'L';
		}
		pos++;
	}
	if (ft_strcmp(completeness_str, "CAL") != 0)
	{
		print_error_and_exit2("C, A or L missing", "objects");
	}
}
