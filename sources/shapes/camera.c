/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:51:15 by linda             #+#    #+#             */
/*   Updated: 2024/11/25 12:56:14 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include <stdio.h>

#include "../../includes/objects.h"
#include "../../includes/miniRT.h"

void	init_image_plane(t_object *camera)
{
	float	pixel_len;
	t_tuple	*orthonormal_vec_x;
	t_tuple	*orthonormal_vec_y;
	t_tuple	temp;

	temp = tuple_cross2(&camera->s_camera.normal_vec, &(t_tuple){0, -1, 0, 0});
	orthonormal_vec_x = tuple_normalize(&temp);
	temp = tuple_cross2(&camera->s_camera.normal_vec, orthonormal_vec_x);
	orthonormal_vec_y = tuple_normalize(&temp);
	pixel_len = CANVAS_WIDTH / WIDTH_IN_PIXEL;
	camera->s_camera.s_img_plane.delta_x_vec = tuple_scale2(pixel_len, \
													orthonormal_vec_x);
	camera->s_camera.s_img_plane.delta_y_vec = tuple_scale2(pixel_len, \
													orthonormal_vec_y);
	camera->s_camera.s_img_plane.origin = calc_origin(camera);
	free(orthonormal_vec_x);
	free(orthonormal_vec_y);
}
// print_tuple(*orthonormal_vec_x);
// print_tuple(*orthonormal_vec_y);

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