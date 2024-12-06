/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_fcts_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:03:30 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/06 15:44:14 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
#include "../../includes/parser.h"
#include "../../includes/maths.h"
#include "../../includes/utilities.h"
#include "../../libft/libft.h"

void	init_normal_vec(t_object *obj, char **line_arr, int idx)
{
	double	x_normal_vec;
	double	y_normal_vec;
	double	z_normal_vec;
	int		error;
	t_tuple	vec;

	error = 0;
	exit_if_args_incompl(line_arr, idx, "normal_vec: not enough arguments", \
							obj);
	x_normal_vec = ft_atof_mod(line_arr[idx], &error);
	exit_if_args_incompl(line_arr, idx + 1, \
							"normal_vec: not enough arguments", obj);
	y_normal_vec = ft_atof_mod(line_arr[idx + 1], &error);
	exit_if_args_incompl(line_arr, idx + 2, \
							"normal_vec: not enough arguments", obj);
	z_normal_vec = ft_atof_mod(line_arr[idx + 2], &error);
	if (error == 1)
		error_and_exit2("normal_vec: number has wrong format", line_arr[0], \
																obj);
	vec = set_tuple(x_normal_vec, y_normal_vec, z_normal_vec, VEC);
	if (is_normalized(&vec))
		obj->s_camera.normal_vec = vec;
	else
		error_and_exit2("normal_vec: vector not normalized", line_arr[0], obj);
}
	// vec = tuple_normalize(&vec);

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
			dir = direction(&data->objects[pos]->position, \
								&data->objects[idx_camera]->position);
			dot_prod = tuple_dot(&data->objects[pos]->s_plane.normal_vec, &dir);
			if (dot_prod < 0)
			{
				data->objects[pos]->s_plane.normal_vec = tuple_neg(&data->\
											objects[pos]->s_plane.normal_vec);
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
	int		error;

	error = 0;
	exit_if_args_incompl(line_arr, idx, "axis_vec: not enough args", obj);
	x_normal_vec = ft_atof_mod(line_arr[idx], &error);
	exit_if_args_incompl(line_arr, idx + 1, "axis_vec: not enough args", obj);
	y_normal_vec = ft_atof_mod(line_arr[idx + 1], &error);
	exit_if_args_incompl(line_arr, idx + 2, "axis_vec: not enough args", obj);
	z_normal_vec = ft_atof_mod(line_arr[idx + 2], &error);
	if (error == 1)
		error_and_exit2("axis_vec: number has wrong format", line_arr[0], obj);
	vec = set_tuple(x_normal_vec, y_normal_vec, z_normal_vec, VEC);
	if (is_normalized(&vec))
		obj->s_cy.axis_vec = vec;
	else
		error_and_exit2("axis_vec: vector not normalized", line_arr[0], obj);
}
	// vec = tuple_normalize(&vec);

void	init_angle(t_object *obj, char **line_arr, int idx)
{
	double	angle;
	int		error;

	error = 0;
	exit_if_args_incompl(line_arr, idx, "angle: not enough arguments", obj);
	angle = ft_atof_mod(line_arr[idx], &error);
	if (is_in_range_float(&angle, 0, 180) && error == 0)
		obj->s_camera.angle = angle;
	else
		error_and_exit2("angle: value not in range [0,180]", line_arr[0], obj);
}

void	init_radius(t_object *obj, char **line_arr, int idx)
{
	double	radius;
	char	message[100];
	int		error;

	error = 0;
	exit_if_args_incompl(line_arr, idx, "radius: missing argument", obj);
	radius = ft_atof_mod(line_arr[idx], &error) / 2;
	if (is_in_range_float(&radius, 0, MAX_RADIUS) && error == 0)
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
		error_and_exit2(message, line_arr[0], obj);
	}
}
