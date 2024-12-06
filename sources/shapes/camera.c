/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:51:15 by linda             #+#    #+#             */
/*   Updated: 2024/12/06 13:43:24 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include <stdio.h>

#include "../../includes/objects.h"
#include "../../includes/miniRT.h"

t_tuple	calc_origin(t_object *camera, t_tuple orthonormal_vec_x, \
						t_tuple orthonormal_vec_y);

void	init_image_plane(t_object *cam)
{
	double	pixel_len;
	t_tuple	orthonormal_vec_x;
	t_tuple	orthonormal_vec_y;
	t_tuple	temp;

	if (fabs(cam->s_camera.normal_vec.y - 1) < 1E-3 || \
		fabs(cam->s_camera.normal_vec.y + 1) < 1E-3)
	{
		orthonormal_vec_x = tuple_normalize(&(t_tuple){1, 0, 0, 0});
		orthonormal_vec_y = tuple_normalize(&(t_tuple){0, 0, 1, 0});
	}
	else
	{
		temp = tuple_cross(&cam->s_camera.normal_vec, &(t_tuple){0, -1, 0, 0});
		orthonormal_vec_x = tuple_normalize(&temp);
		temp = tuple_cross(&cam->s_camera.normal_vec, &orthonormal_vec_x);
		orthonormal_vec_y = tuple_normalize(&temp);
	}
	pixel_len = CANVAS_WIDTH / WIDTH_IN_PIXEL;
	cam->s_camera.s_img_plane.delta_x_vec = tuple_scale(pixel_len, \
													&orthonormal_vec_x);
	cam->s_camera.s_img_plane.delta_y_vec = tuple_scale(pixel_len, \
													&orthonormal_vec_y);
	cam->s_camera.s_img_plane.origin = calc_origin(cam, \
									orthonormal_vec_x, orthonormal_vec_y);
}

t_tuple	calc_origin(t_object *camera, t_tuple orthonormal_vec_x, \
						t_tuple orthonormal_vec_y)
{
	t_tuple		origin;
	double		canvas_height;
	double		dist;
	double		angle_rad;
	t_tuple		temp1;

	canvas_height = (CANVAS_WIDTH / WIDTH_IN_PIXEL) * (HEIGHT_IN_PIXEL + 1);
	angle_rad = deg_to_rad(camera->s_camera.angle / 2);
	dist = CANVAS_WIDTH / 2 / tan(angle_rad);
	temp1 = tuple_scale(dist, &camera->s_camera.normal_vec);
	origin = tuple_add(&camera->position, &temp1);
	temp1 = tuple_scale(-CANVAS_WIDTH / 2, &orthonormal_vec_x);
	origin = tuple_add(&origin, &temp1);
	temp1 = tuple_scale(-canvas_height / 2, &orthonormal_vec_y);
	origin = tuple_add(&origin, &temp1);
	return (origin);
}
