/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:51:15 by linda             #+#    #+#             */
/*   Updated: 2024/11/29 15:08:32 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include <stdio.h>

#include "../../includes/objects.h"
#include "../../includes/miniRT.h"

t_tuple	calc_origin2(t_object *camera, t_tuple orthonormal_vec_x, t_tuple orthonormal_vec_y);

void	init_image_plane(t_object *camera)
{
	double	pixel_len;
	t_tuple	orthonormal_vec_x;
	t_tuple	orthonormal_vec_y;
	t_tuple	temp;

	// if (camera->s_camera.normal_vec.y - 1 < 1E-3)
	// {
	// 	orthonormal_vec_x = tuple_normalize(&(t_tuple){1, 0, 0, 0});
	// 	orthonormal_vec_y = tuple_normalize(&(t_tuple){0, 0, 1, 0});
	// }
	// else if (camera->s_camera.normal_vec.y + 1 < 1E-3)
	// {
	// 	orthonormal_vec_x = tuple_normalize(&(t_tuple){1, 0, 0, 0});
	// 	orthonormal_vec_y = tuple_normalize(&(t_tuple){0, 0, 1, 0});
	// }
	// else
	{
		temp = tuple_cross2(&camera->s_camera.normal_vec, &(t_tuple){0, -1, 0, 0});
		orthonormal_vec_x = tuple_normalize2(&temp);
		temp = tuple_cross2(&camera->s_camera.normal_vec, &orthonormal_vec_x);
		orthonormal_vec_y = tuple_normalize2(&temp);
	}
	pixel_len = CANVAS_WIDTH / WIDTH_IN_PIXEL;
	camera->s_camera.s_img_plane.delta_x_vec = tuple_scale2(pixel_len, \
													&orthonormal_vec_x);
	camera->s_camera.s_img_plane.delta_y_vec = tuple_scale2(pixel_len, \
													&orthonormal_vec_y);
	camera->s_camera.s_img_plane.origin = calc_origin2(camera, orthonormal_vec_x, orthonormal_vec_y);
	camera->s_camera.s_img_plane.origin = calc_origin(camera);
}
// print_tuple(*orthonormal_vec_x);
// print_tuple(*orthonormal_vec_y);

t_tuple	calc_origin(t_object *camera)
{
	t_tuple		origin;
	double		canvas_height;
	double		dist;
	double		angle_rad;
	t_tuple		temp1;

	canvas_height = (CANVAS_WIDTH / WIDTH_IN_PIXEL) * HEIGHT_IN_PIXEL;
	angle_rad = deg_to_rad(camera->s_camera.angle / 2.0);
	dist = CANVAS_WIDTH / 2.0 / tan(angle_rad);
	temp1 = tuple_scale2(dist, &camera->s_camera.normal_vec);
	origin = tuple_add2(&camera->position, &temp1);
	temp1 = tuple_scale2(-WIDTH_IN_PIXEL / 2.0, &camera->s_camera.s_img_plane.delta_x_vec);
	origin = tuple_add2(&origin, &temp1);
	temp1 = tuple_scale2(-HEIGHT_IN_PIXEL / 2.0, &camera->s_camera.s_img_plane.delta_y_vec);
	origin = tuple_add2(&origin, &temp1);
	return (origin);
}

t_tuple	calc_origin2(t_object *camera, t_tuple orthonormal_vec_x, t_tuple orthonormal_vec_y)
{
	t_tuple		origin;
	double		canvas_height;
	double		dist;
	double		angle_rad;
	t_tuple		temp1;

	canvas_height = (CANVAS_WIDTH / WIDTH_IN_PIXEL) * HEIGHT_IN_PIXEL;
	angle_rad = deg_to_rad(camera->s_camera.angle / 2);
	dist = CANVAS_WIDTH / 2 / tan(angle_rad);
	temp1 = tuple_scale2(dist, &camera->s_camera.normal_vec);
	origin = tuple_add2(&camera->position, &temp1);
	temp1 = tuple_scale2(-CANVAS_WIDTH / 2, &orthonormal_vec_x);
	origin = tuple_add2(&origin, &temp1);
	temp1 = tuple_scale2(-canvas_height / 2, &orthonormal_vec_y);
	origin = tuple_add2(&origin, &temp1);
	return (origin);
}
