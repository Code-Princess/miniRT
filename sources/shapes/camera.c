/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:51:15 by linda             #+#    #+#             */
/*   Updated: 2024/10/18 20:48:47 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <stdio.h>

#include "../../includes/objects.h"
#include "../../includes/miniRT.h"

void	calc_image_plane(t_object *camera)
{
	float	pixel_len;

	pixel_len = CANVAS_WIDTH / WIDTH;
	camera->s_camera.s_img_plane.origin = calc_origin(camera);
	camera->s_camera.s_img_plane.delta_x_vec = *tuple_scale(pixel_len, &(t_tuple){1, 0, 0, 0,});
	camera->s_camera.s_img_plane.delta_y_vec = *tuple_scale(pixel_len, &(t_tuple){0, 1, 0, 0,});
// printf("pixel_len: %f\n", pixel_len);
// print_tuple(*tuple_scale(pixel_len, &(t_tuple){1, 0, 0, 0,}));
// print_tuple(camera->s_camera.s_img_plane.delta_x_vec);
}

t_tuple	calc_origin(t_object *camera)
{
	t_tuple		origin;
	float		canvas_height;
	float		dist;
	float		angle_rad;

	canvas_height = (CANVAS_WIDTH / WIDTH) * HEIGHT;
	angle_rad = deg_to_rad(camera->s_camera.angle/2);
	dist = CANVAS_WIDTH / 2 / tan(angle_rad);
	origin.x = camera->position.x - CANVAS_WIDTH / 2;
	origin.y = camera->position.y - canvas_height / 2;
	origin.z = camera->position.z + dist;
	origin.w = 1;
	return (origin);
}

void	init_camera(t_data *data)
{
	t_object	*camera;

	camera = malloc(1 * sizeof(t_object));
	// camera = data->objects[CAMERA];
	camera->obj_name = CAMERA;
	camera->identifier = C;
	camera->position.x = 0;
	camera->position.y = 0;
	camera->position.z = 0;
	camera->position.w = 1;
	camera->s_camera.angle = 90;
	camera->s_camera.normal_vec.x = 0;
	camera->s_camera.normal_vec.y = 0;
	camera->s_camera.normal_vec.z = 1;
	camera->s_camera.normal_vec.w = 0;
	// camera.s_camera.img_plane = NULL;
	calc_image_plane(camera);
// print_tuple(camera.s_camera.s_img_plane.delta_x_vec);
	data->objects[CAMERA] = camera;
	printf("still alive!\n");
}
