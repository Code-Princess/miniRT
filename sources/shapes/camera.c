/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:51:15 by linda             #+#    #+#             */
/*   Updated: 2024/10/14 17:03:23 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "../../includes/objects.h"
#include "../../includes/miniRT.h"

void	calc_image_plane(t_object *camera)
{
	float	pixel_len;

	pixel_len = CANVAS_WIDTH / WIDTH;
	camera->spec_membs.camera.img_plane.origin = calc_origin(camera);
	camera->spec_membs.camera.img_plane.delta_x_vec = tuple_scale(pixel_len, (t_tuple){1, 0, 0, 0,});
	camera->spec_membs.camera.img_plane.delta_y_vec = tuple_scale(pixel_len, (t_tuple){0, 1, 0, 0,});
}

t_tuple	calc_origin(t_object *camera)
{
	t_tuple		origin;
	float		canvas_height;
	float		dist;
	float		angle_rad;

	canvas_height = (CANVAS_WIDTH / WIDTH) * HEIGHT;
	angle_rad = deg_to_rad(camera->spec_membs.camera.angle/2);
	dist = CANVAS_WIDTH / 2 / tan(angle_rad);
	origin.x = camera->position.x - CANVAS_WIDTH / 2;
	origin.y = camera->position.y - canvas_height / 2;
	origin.z = camera->position.z + dist;
	origin.w = 1;
	return (origin);
}

void	init_camera(t_data *data)
{
	t_object	camera;

	camera = data->objects[CAMERA];
	camera.obj_name = CAMERA;
	camera.identifier = C;
	camera.position.x = 0;
	camera.position.y = 0;
	camera.position.z = 0;
	camera.position.w = 1;
	camera.spec_membs.camera.angle = 90;
	camera.spec_membs.camera.normal_vec.x = 0;
	camera.spec_membs.camera.normal_vec.y = 0;
	camera.spec_membs.camera.normal_vec.z = 1;
	camera.spec_membs.camera.normal_vec.w = 0;
	// camera.spec_membs.camera.img_plane = NULL;
	calc_image_plane(&camera);
	
}
