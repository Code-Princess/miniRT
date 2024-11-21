/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_fcts_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:03:30 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/21 14:19:21 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
#include "../../includes/parser.h"
#include "../../includes/maths.h"
#include "../../libft/libft.h"
#include "../../includes/utilities.h"

void	init_normal_vec(t_object *obj, char **line_arr, int idx)
{
	float	x_normal_vec;
	float	y_normal_vec;
	float	z_normal_vec;
	t_tuple	vec;

	if (line_arr[idx] == NULL)
		print_error_and_exit("normal_vec: not enough arguments", line_arr[0]);
	x_normal_vec = ft_atof(line_arr[idx]);
	y_normal_vec = ft_atof(line_arr[idx + 1]);
	z_normal_vec = ft_atof(line_arr[idx + 2]);
	vec = set_tuple(x_normal_vec, y_normal_vec, z_normal_vec, VEC);
	vec = *tuple_normalize(&vec);
	if (is_normalized(&vec) && is_in_range_float(&vec.x, -1, 1) && \
		is_in_range_float(&vec.y, -1, 1) && is_in_range_float(&vec.z, -1, 1))
		obj->s_camera.normal_vec = vec;
	else {;}
		//error!
}

void	init_axis_vec(t_object *obj, char **line_arr, int idx)
{
	float	x_normal_vec;
	float	y_normal_vec;
	float	z_normal_vec;
	t_tuple	vec;

	x_normal_vec = ft_atof(line_arr[idx]);
	y_normal_vec = ft_atof(line_arr[idx + 1]);
	z_normal_vec = ft_atof(line_arr[idx + 2]);
	vec = set_tuple(x_normal_vec, y_normal_vec, z_normal_vec, VEC);
	if (is_normalized(&vec) && is_in_range_float(&x_normal_vec, -1, 1) && \
		is_in_range_float(&y_normal_vec, -1, 1) && is_in_range_float(&z_normal_vec, -1, 1))
		obj->s_cy.axis_vec = vec;
	else {;}
		//error!
}

bool	is_normalized(t_tuple *vec)
{
	if (tuple_magni(vec) - 1 <= INFINI_FLOAT)
		return (true);
	else
		return (false);
}

void	init_angle(t_object *obj, char **line_arr, int idx)
{
	float	angle;

	angle = ft_atof(line_arr[idx]);
	if (is_in_range_float(&angle, 0, 180))
	{
		obj->s_camera.angle = angle;
	}
	else
	{
		print_error_and_exit("angle: value not in range [0,180]", line_arr[0]);
	}
}

void	init_radius(t_object *obj, char **line_arr, int idx)
{
	float	radius;

	radius = ft_atof(line_arr[idx]) / 2;
	if (obj->identifier == SP)
		obj->s_sphere.radius = radius;
	if (obj->identifier == CY)
		obj->s_cy.radius = radius;
}

void	init_height(t_object *obj, char **line_arr, int idx)
{
	float	height;

	height = ft_atof(line_arr[idx]);
	obj->s_cy.height = height;
}
