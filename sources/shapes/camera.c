/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:51:15 by linda             #+#    #+#             */
/*   Updated: 2024/11/13 19:41:50 by llacsivy         ###   ########.fr       */
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

	pixel_len = CANVAS_WIDTH / WIDTH_IN_PIXEL;
	camera->s_camera.s_img_plane.origin = calc_origin(camera);
	camera->s_camera.s_img_plane.delta_x_vec = *tuple_scale(pixel_len, \
													&(t_tuple){1, 0, 0, 0,});
	camera->s_camera.s_img_plane.delta_y_vec = *tuple_scale(pixel_len, \
													&(t_tuple){0, 1, 0, 0,});
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
