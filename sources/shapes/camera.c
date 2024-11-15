/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:51:15 by linda             #+#    #+#             */
/*   Updated: 2024/11/15 13:47:15 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include <stdio.h>

#include "../../includes/objects.h"
#include "../../includes/miniRT.h"

void	init_image_plane2(t_object *camera)
{
	float	pixel_len;

	pixel_len = CANVAS_WIDTH / WIDTH_IN_PIXEL;
	camera->s_camera.s_img_plane.delta_x_vec = *tuple_scale(pixel_len, \
													&(t_tuple){1, 0, 0, 0,});
	camera->s_camera.s_img_plane.delta_y_vec = *tuple_scale(pixel_len, \
													&(t_tuple){0, 1, 0, 0,});
	camera->s_camera.s_img_plane.origin = calc_origin(camera);
}

t_tuple	calc_origin2(t_object *camera)
{
	t_tuple		origin;
	float		canvas_height;
	float		dist;
	float		angle_rad;

	canvas_height = (CANVAS_WIDTH / WIDTH_IN_PIXEL) * HEIGHT_IN_PIXEL;
	angle_rad = deg_to_rad(camera->s_camera.angle / 2);
	dist = CANVAS_WIDTH / 2 / tan(angle_rad);
	origin = set_tuple(camera->position.x - CANVAS_WIDTH / 2, \
					camera->position.y - canvas_height / 2, \
					camera->position.z + dist, \
					1);
	return (origin);
}

void	init_image_plane(t_object *camera)
{
	float	pixel_len;
	t_tuple	*orthonormal_vec_x;
	t_tuple	*orthonormal_vec_y;

	orthonormal_vec_x = tuple_normalize(tuple_cross(&camera->s_camera.normal_vec, &(t_tuple){0, -1, 0, 0}));
print_tuple(*orthonormal_vec_x);
orthonormal_vec_y = tuple_normalize(tuple_cross(&camera->s_camera.normal_vec, orthonormal_vec_x));
print_tuple(*orthonormal_vec_y);
	pixel_len = CANVAS_WIDTH / WIDTH_IN_PIXEL;
	camera->s_camera.s_img_plane.delta_x_vec = *tuple_scale(pixel_len, \
													orthonormal_vec_x);
	camera->s_camera.s_img_plane.delta_y_vec = *tuple_scale(pixel_len, \
													orthonormal_vec_y);
	// camera->s_camera.s_img_plane.delta_x_vec = *tuple_scale(pixel_len, \
	// 												&(t_tuple){1, 0, 0, 0,});
	// camera->s_camera.s_img_plane.delta_y_vec = *tuple_scale(pixel_len, \
	// 												&(t_tuple){0, 1, 0, 0,});
	camera->s_camera.s_img_plane.origin = calc_origin(camera);
}

t_tuple	calc_origin(t_object *camera)
{
	t_tuple		origin;
	float		canvas_height;
	float		dist;
	float		angle_rad;

	canvas_height = (CANVAS_WIDTH / WIDTH_IN_PIXEL) * HEIGHT_IN_PIXEL;
	angle_rad = deg_to_rad(camera->s_camera.angle / 2);
	dist = CANVAS_WIDTH / 2 / tan(angle_rad);
	origin = set_tuple(camera->position.x - CANVAS_WIDTH / 2, \
					camera->position.y - canvas_height / 2, \
					camera->position.z + dist, \
					1);
	return (origin);
}